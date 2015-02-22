/*
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-consensus.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "consensus/consensus.h"

#include <cstddef>
#include <stdint.h>
#include <bitcoin/consensus/define.hpp>
#include <bitcoin/consensus/export.hpp>
#include <bitcoin/consensus/version.hpp>
#include "primitives/transaction.h"
#include "script/interpreter.h"
#include "script/script_error.h"
#include "version.h"

// Helper class, not published. This is tested internal to verify_script.
class TxInputStream
{
public:
    TxInputStream(const uint8_t* transaction, size_t transactionSize)
        : source(transaction), remaining(transactionSize)
    {
    }

    TxInputStream& read(char* destination, size_t size)
    {
        if (size > remaining)
            throw std::ios_base::failure("end of data");

        if (destination == NULL)
            throw std::ios_base::failure("bad destination buffer");

        if (source == NULL)
            throw std::ios_base::failure("bad source buffer");

        memcpy(destination, source, size);
        remaining -= size;
        source += size;
        return *this;
    }

private:
    const uint8_t* source;
    size_t remaining;
};

namespace libbitcoin {
namespace consensus {

// This mapping decouples the consensus API from the satoshi implementation
// files. We prefer to keep our copies of consensus files isomorphic.
// This function is not published (but non-static for testability).
verify_result_type script_error_to_verify_result(ScriptError_t code)
{
    switch (code)
    {
        // Logical result
        case SCRIPT_ERR_OK:
            return consensus::VERIFY_RESULT_EVAL_TRUE;
        case SCRIPT_ERR_EVAL_FALSE:
            return consensus::VERIFY_RESULT_EVAL_FALSE;

        // Max size errors
        case SCRIPT_ERR_SCRIPT_SIZE:
            return consensus::VERIFY_RESULT_SCRIPT_SIZE;
        case SCRIPT_ERR_PUSH_SIZE:
            return consensus::VERIFY_RESULT_PUSH_SIZE;
        case SCRIPT_ERR_OP_COUNT:
            return consensus::VERIFY_RESULT_OP_COUNT;
        case SCRIPT_ERR_STACK_SIZE:
            return consensus::VERIFY_RESULT_STACK_SIZE;
        case SCRIPT_ERR_SIG_COUNT:
            return consensus::VERIFY_RESULT_SIG_COUNT;
        case SCRIPT_ERR_PUBKEY_COUNT:
            return consensus::VERIFY_RESULT_PUBKEY_COUNT;

        // Failed verify operations
        case SCRIPT_ERR_VERIFY:
            return consensus::VERIFY_RESULT_VERIFY;
        case SCRIPT_ERR_EQUALVERIFY:
            return consensus::VERIFY_RESULT_EQUALVERIFY;
        case SCRIPT_ERR_CHECKMULTISIGVERIFY:
            return consensus::VERIFY_RESULT_CHECKMULTISIGVERIFY;
        case SCRIPT_ERR_CHECKSIGVERIFY:
            return consensus::VERIFY_RESULT_CHECKSIGVERIFY;
        case SCRIPT_ERR_NUMEQUALVERIFY:
            return consensus::VERIFY_RESULT_NUMEQUALVERIFY;

        // Logical/Format/Canonical errors
        case SCRIPT_ERR_BAD_OPCODE:
            return consensus::VERIFY_RESULT_BAD_OPCODE;
        case SCRIPT_ERR_DISABLED_OPCODE:
            return consensus::VERIFY_RESULT_DISABLED_OPCODE;
        case SCRIPT_ERR_INVALID_STACK_OPERATION:
            return consensus::VERIFY_RESULT_INVALID_STACK_OPERATION;
        case SCRIPT_ERR_INVALID_ALTSTACK_OPERATION:
            return consensus::VERIFY_RESULT_INVALID_ALTSTACK_OPERATION;
        case SCRIPT_ERR_UNBALANCED_CONDITIONAL:
            return consensus::VERIFY_RESULT_UNBALANCED_CONDITIONAL;

        // BIP62
        case SCRIPT_ERR_SIG_HASHTYPE:
            return consensus::VERIFY_RESULT_SIG_HASHTYPE;
        case SCRIPT_ERR_SIG_DER:
            return consensus::VERIFY_RESULT_SIG_DER;
        case SCRIPT_ERR_MINIMALDATA:
            return consensus::VERIFY_RESULT_MINIMALDATA;
        case SCRIPT_ERR_SIG_PUSHONLY:
            return consensus::VERIFY_RESULT_SIG_PUSHONLY;
        case SCRIPT_ERR_SIG_HIGH_S:
            return consensus::VERIFY_RESULT_SIG_HIGH_S;
        case SCRIPT_ERR_SIG_NULLDUMMY:
            return consensus::VERIFY_RESULT_SIG_NULLDUMMY;
        case SCRIPT_ERR_PUBKEYTYPE:
            return consensus::VERIFY_RESULT_PUBKEYTYPE;
        case SCRIPT_ERR_CLEANSTACK:
            return consensus::VERIFY_RESULT_CLEANSTACK;

        // Softfork safeness
        case SCRIPT_ERR_DISCOURAGE_UPGRADABLE_NOPS:
            return consensus::VERIFY_RESULT_DISCOURAGE_UPGRADABLE_NOPS;

        // Other
        case SCRIPT_ERR_OP_RETURN:
            return consensus::VERIFY_RESULT_OP_RETURN;
        case SCRIPT_ERR_UNKNOWN_ERROR:
        case SCRIPT_ERR_ERROR_COUNT:
        default:
            return consensus::VERIFY_RESULT_UNKNOWN_ERROR;
    }
}

// This mapping decouples the consensus API from the satoshi implementation
// files. We prefer to keep our copies of consensus files isomorphic.
// This function is not published (but non-static for testability).
uint32_t verify_flags_to_script_flags(uint32_t flags)
{
    unsigned int script_flags = SCRIPT_VERIFY_NONE;

    if ((flags & consensus::VERIFY_FLAGS_P2SH) != 0)
        script_flags |= SCRIPT_VERIFY_P2SH;
    if ((flags & consensus::VERIFY_FLAGS_STRICTENC) != 0)
        script_flags |= SCRIPT_VERIFY_STRICTENC;
    if ((flags & consensus::VERIFY_FLAGS_DERSIG) != 0)
        script_flags |= SCRIPT_VERIFY_DERSIG;
    if ((flags & consensus::VERIFY_FLAGS_LOW_S) != 0)
        script_flags |= SCRIPT_VERIFY_LOW_S;
    if ((flags & consensus::VERIFY_FLAGS_NULLDUMMY) != 0)
        script_flags |= SCRIPT_VERIFY_NULLDUMMY;
    if ((flags & consensus::VERIFY_FLAGS_SIGPUSHONLY) != 0)
        script_flags |= SCRIPT_VERIFY_SIGPUSHONLY;
    if ((flags & consensus::VERIFY_FLAGS_MINIMALDATA) != 0)
        script_flags |= SCRIPT_VERIFY_MINIMALDATA;
    if ((flags & consensus::VERIFY_FLAGS_DISCOURAGE_UPGRADABLE_NOPS) != 0)
        script_flags |= SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_NOPS;
    if ((flags & consensus::VERIFY_FLAGS_CLEANSTACK) != 0)
        script_flags |= SCRIPT_VERIFY_CLEANSTACK;

    return script_flags;
}

// This function is published. The signature exposes no satoshi internals.
verify_result_type verify_script(const uint8_t* transaction, 
    size_t transactionSize, const uint8_t* publicKey, size_t publicKeySize,
    uint32_t inputIndex, uint32_t flags)
{
    CTransaction tx;
    try 
    {
        TxInputStream stream(transaction, transactionSize);
        Unserialize(stream, tx, SER_NETWORK, PROTOCOL_VERSION);
    }
    catch (const std::exception&)
    {
        return consensus::VERIFY_RESULT_TX_INVALID;
    }

    if (inputIndex >= tx.vin.size())
        return consensus::VERIFY_RESULT_TX_INPUT_INVALID;

    if (tx.GetSerializeSize(SER_NETWORK, PROTOCOL_VERSION) != transactionSize)
        return consensus::VERIFY_RESULT_TX_SIZE_INVALID;

    CScript script(publicKey, publicKey + publicKeySize);
    TransactionSignatureChecker checker(&tx, inputIndex);
    const CScript& endorsement = tx.vin[inputIndex].scriptSig;
    const uint32_t script_flags = verify_flags_to_script_flags(flags);

    ScriptError_t result;
    if (!VerifyScript(endorsement, script, script_flags, checker, &result))
        return script_error_to_verify_result(result);

    return consensus::VERIFY_RESULT_EVAL_TRUE;
}

} // namespace consensus
} // namespace libbitcoin
