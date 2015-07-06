/*
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-consensus.
 *
 * libbitcoin-consensus is free software: you can redistribute it and/or
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
#include <iostream>
#include <stdexcept>
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
    TxInputStream(const unsigned char* transaction, size_t transaction_size)
        : source_(transaction), remaining_(transaction_size)
    {
    }

    TxInputStream& read(char* destination, size_t size)
    {
        if (size > remaining_)
            throw std::ios_base::failure("end of data");

        memcpy(destination, source_, size);
        remaining_ -= size;
        source_ += size;
        return *this;
    }

private:
    const unsigned char* source_;
    size_t remaining_;
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
            return verify_result_eval_true;
        case SCRIPT_ERR_EVAL_FALSE:
            return verify_result_eval_false;

        // Max size errors
        case SCRIPT_ERR_SCRIPT_SIZE:
            return verify_result_script_size;
        case SCRIPT_ERR_PUSH_SIZE:
            return verify_result_push_size;
        case SCRIPT_ERR_OP_COUNT:
            return verify_result_op_count;
        case SCRIPT_ERR_STACK_SIZE:
            return verify_result_stack_size;
        case SCRIPT_ERR_SIG_COUNT:
            return verify_result_sig_count;
        case SCRIPT_ERR_PUBKEY_COUNT:
            return verify_result_pubkey_count;

        // Failed verify operations
        case SCRIPT_ERR_VERIFY:
            return verify_result_verify;
        case SCRIPT_ERR_EQUALVERIFY:
            return verify_result_equalverify;
        case SCRIPT_ERR_CHECKMULTISIGVERIFY:
            return verify_result_checkmultisigverify;
        case SCRIPT_ERR_CHECKSIGVERIFY:
            return verify_result_checksigverify;
        case SCRIPT_ERR_NUMEQUALVERIFY:
            return verify_result_numequalverify;

        // Logical/Format/Canonical errors
        case SCRIPT_ERR_BAD_OPCODE:
            return verify_result_bad_opcode;
        case SCRIPT_ERR_DISABLED_OPCODE:
            return verify_result_disabled_opcode;
        case SCRIPT_ERR_INVALID_STACK_OPERATION:
            return verify_result_invalid_stack_operation;
        case SCRIPT_ERR_INVALID_ALTSTACK_OPERATION:
            return verify_result_invalid_altstack_operation;
        case SCRIPT_ERR_UNBALANCED_CONDITIONAL:
            return verify_result_unbalanced_conditional;

        // BIP62
        case SCRIPT_ERR_SIG_HASHTYPE:
            return verify_result_sig_hashtype;
        case SCRIPT_ERR_SIG_DER:
            return verify_result_sig_der;
        case SCRIPT_ERR_MINIMALDATA:
            return verify_result_minimaldata;
        case SCRIPT_ERR_SIG_PUSHONLY:
            return verify_result_sig_pushonly;
        case SCRIPT_ERR_SIG_HIGH_S:
            return verify_result_sig_high_s;
        case SCRIPT_ERR_SIG_NULLDUMMY:
            return verify_result_sig_nulldummy;
        case SCRIPT_ERR_PUBKEYTYPE:
            return verify_result_pubkeytype;
        case SCRIPT_ERR_CLEANSTACK:
            return verify_result_cleanstack;

        // Softfork safeness
        case SCRIPT_ERR_DISCOURAGE_UPGRADABLE_NOPS:
            return verify_result_discourage_upgradable_nops;

        // Other
        case SCRIPT_ERR_OP_RETURN:
            return verify_result_op_return;
        case SCRIPT_ERR_UNKNOWN_ERROR:
        case SCRIPT_ERR_ERROR_COUNT:
        default:
            return verify_result_unknown_error;
    }
}

// This mapping decouples the consensus API from the satoshi implementation
// files. We prefer to keep our copies of consensus files isomorphic.
// This function is not published (but non-static for testability).
unsigned int verify_flags_to_script_flags(unsigned int flags)
{
    unsigned int script_flags = SCRIPT_VERIFY_NONE;

    if ((flags & verify_flags_p2sh) != 0)
        script_flags |= SCRIPT_VERIFY_P2SH;
    if ((flags & verify_flags_strictenc) != 0)
        script_flags |= SCRIPT_VERIFY_STRICTENC;
    if ((flags & verify_flags_dersig) != 0)
        script_flags |= SCRIPT_VERIFY_DERSIG;
    if ((flags & verify_flags_low_s) != 0)
        script_flags |= SCRIPT_VERIFY_LOW_S;
    if ((flags & verify_flags_nulldummy) != 0)
        script_flags |= SCRIPT_VERIFY_NULLDUMMY;
    if ((flags & verify_flags_sigpushonly) != 0)
        script_flags |= SCRIPT_VERIFY_SIGPUSHONLY;
    if ((flags & verify_flags_minimaldata) != 0)
        script_flags |= SCRIPT_VERIFY_MINIMALDATA;
    if ((flags & verify_flags_discourage_upgradable_nops) != 0)
        script_flags |= SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_NOPS;
    if ((flags & verify_flags_cleanstack) != 0)
        script_flags |= SCRIPT_VERIFY_CLEANSTACK;

    return script_flags;
}

// This function is published. The implementation exposes no satoshi internals.
verify_result_type verify_script(const unsigned char* transaction, 
    size_t transaction_size, const unsigned char* prevout_script, 
    size_t prevout_script_size, unsigned int tx_input_index, 
    unsigned int flags)
{
    if (transaction == NULL)
        throw std::invalid_argument("transaction");

    if (prevout_script == NULL)
        throw std::invalid_argument("prevout_script");

    CTransaction tx;
    try 
    {
        TxInputStream stream(transaction, transaction_size);
        Unserialize(stream, tx, SER_NETWORK, PROTOCOL_VERSION);
    }
    catch (const std::exception&)
    {
        return verify_result_tx_invalid;
    }

    if (tx_input_index >= tx.vin.size())
        return verify_result_tx_input_invalid;

    if (tx.GetSerializeSize(SER_NETWORK, PROTOCOL_VERSION) != transaction_size)
        return verify_result_tx_size_invalid;

    ScriptError_t error;
    TransactionSignatureChecker checker(&tx, tx_input_index);
    const unsigned int script_flags = verify_flags_to_script_flags(flags);
    CScript output_script(prevout_script, prevout_script + prevout_script_size);
    const CScript& input_script = tx.vin[tx_input_index].scriptSig;

    // See libbitcoin-blockchain : validate.cpp :
    // if (!output_script.run(input.script, tx, current_input))...
    // if (!output_script.run(input.script, current_tx, input_index,
    //     bip16_enabled))...
    VerifyScript(input_script, output_script, script_flags, checker, &error);

    return script_error_to_verify_result(error);
}

} // namespace consensus
} // namespace libbitcoin
