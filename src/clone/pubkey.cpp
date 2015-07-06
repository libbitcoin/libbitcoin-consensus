// Copyright (c) 2009-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "pubkey.h"

#include "eccryptoverify.h"

#ifdef USE_SECP256K1
#include <secp256k1.h>
#else
#include "ecwrapper.h"
#endif

bool CPubKey::Verify(const uint256 &hash, const std::vector<unsigned char>& vchSig) const {
    if (!IsValid())
        return false;
#ifdef USE_SECP256K1
    secp256k1_context_t* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    int ret = secp256k1_ecdsa_verify(ctx, (const unsigned char*)&hash, &vchSig[0], vchSig.size(), begin(), size());
    secp256k1_context_destroy(ctx);
    if (ret != 1)
        return false;
#else
    CECKey key;
    if (!key.SetPubKey(begin(), size()))
        return false;
    if (!key.Verify(hash, vchSig))
        return false;
#endif
    return true;
}

bool CPubKey::RecoverCompact(const uint256 &hash, const std::vector<unsigned char>& vchSig) {
    if (vchSig.size() != 65)
        return false;
    int recid = (vchSig[0] - 27) & 3;
    bool fComp = ((vchSig[0] - 27) & 4) != 0;
#ifdef USE_SECP256K1
    int pubkeylen = 65;
    secp256k1_context_t* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    int ret = secp256k1_ecdsa_recover_compact(ctx, (const unsigned char*)&hash, &vchSig[1], (unsigned char*)begin(), &pubkeylen, fComp, recid);
    secp256k1_context_destroy(ctx);
    if (ret == 0)
        return false;
    assert((int)size() == pubkeylen);
#else
    CECKey key;
    if (!key.Recover(hash, &vchSig[1], recid))
        return false;
    std::vector<unsigned char> pubkey;
    key.GetPubKey(pubkey, fComp);
    Set(pubkey.begin(), pubkey.end());
#endif
    return true;
}

bool CPubKey::IsFullyValid() const {
    if (!IsValid())
        return false;
#ifdef USE_SECP256K1
    secp256k1_context_t* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    int ret = secp256k1_ec_pubkey_verify(ctx, begin(), size());
    secp256k1_context_destroy(ctx);
    if (ret == 0)
        return false;
#else
    CECKey key;
    if (!key.SetPubKey(begin(), size()))
        return false;
#endif
    return true;
}

bool CPubKey::Decompress() {
    if (!IsValid())
        return false;
#ifdef USE_SECP256K1
    int clen = size();
    secp256k1_context_t* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    int ret = secp256k1_ec_pubkey_decompress(ctx, (unsigned char*)begin(), &clen);
    secp256k1_context_destroy(ctx);
    assert(ret != 0);
    assert(clen == (int)size());
#else
    CECKey key;
    if (!key.SetPubKey(begin(), size()))
        return false;
    std::vector<unsigned char> pubkey;
    key.GetPubKey(pubkey, false);
    Set(pubkey.begin(), pubkey.end());
#endif
    return true;
}

bool CPubKey::Derive(CPubKey& pubkeyChild, ChainCode &ccChild, unsigned int nChild, const ChainCode& cc) const {
    assert(IsValid());
    assert((nChild >> 31) == 0);
    assert(begin() + 33 == end());
    unsigned char out[64];
    BIP32Hash(cc, nChild, *begin(), begin()+1, out);
    memcpy(ccChild.begin(), out + 32, 32);
#ifdef USE_SECP256K1
    pubkeyChild = *this;
    secp256k1_context_t* ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
    int ret = secp256k1_ec_pubkey_tweak_add(ctx, (unsigned char*)pubkeyChild.begin(), pubkeyChild.size(), out) != 0;
    secp256k1_context_destroy(ctx);
#else
    CECKey key;
    bool ret = key.SetPubKey(begin(), size());
    ret &= key.TweakPublic(out);
    std::vector<unsigned char> pubkey;
    key.GetPubKey(pubkey, true);
    pubkeyChild.Set(pubkey.begin(), pubkey.end());
#endif
    return ret;
}

void CExtPubKey::Encode(unsigned char code[74]) const {
    code[0] = nDepth;
    memcpy(code+1, vchFingerprint, 4);
    code[5] = (nChild >> 24) & 0xFF; code[6] = (nChild >> 16) & 0xFF;
    code[7] = (nChild >>  8) & 0xFF; code[8] = (nChild >>  0) & 0xFF;
    memcpy(code+9, chaincode.begin(), 32);
    assert(pubkey.size() == 33);
    memcpy(code+41, pubkey.begin(), 33);
}

void CExtPubKey::Decode(const unsigned char code[74]) {
    nDepth = code[0];
    memcpy(vchFingerprint, code+1, 4);
    nChild = (code[5] << 24) | (code[6] << 16) | (code[7] << 8) | code[8];
    memcpy(chaincode.begin(), code+9, 32);
    pubkey.Set(code+41, code+74);
}

bool CExtPubKey::Derive(CExtPubKey &out, unsigned int nChild) const {
    out.nDepth = nDepth + 1;
    CKeyID id = pubkey.GetID();
    memcpy(&out.vchFingerprint[0], &id, 4);
    out.nChild = nChild;
    return pubkey.Derive(out.pubkey, out.chaincode, nChild, chaincode);
}
