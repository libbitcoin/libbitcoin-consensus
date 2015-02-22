/*
 * Copyright (c) 2011-2013 libbitcoin developers (see AUTHORS)
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_CONSENSUS_EXPORT_HPP
#define LIBBITCOIN_CONSENSUS_EXPORT_HPP

#include <cstddef>
#include <stdint.h>
#include <bitcoin/consensus/define.hpp>
#include <bitcoin/consensus/version.hpp>

namespace libbitcoin {
namespace consensus {

typedef enum verify_result_type
{
    // Logical result
    VERIFY_RESULT_EVAL_FALSE = 0,
    VERIFY_RESULT_EVAL_TRUE,

    // Max size errors
    VERIFY_RESULT_SCRIPT_SIZE,
    VERIFY_RESULT_PUSH_SIZE,
    VERIFY_RESULT_OP_COUNT,
    VERIFY_RESULT_STACK_SIZE,
    VERIFY_RESULT_SIG_COUNT,
    VERIFY_RESULT_PUBKEY_COUNT,

    // Failed verify operations
    VERIFY_RESULT_VERIFY,
    VERIFY_RESULT_EQUALVERIFY,
    VERIFY_RESULT_CHECKMULTISIGVERIFY,
    VERIFY_RESULT_CHECKSIGVERIFY,
    VERIFY_RESULT_NUMEQUALVERIFY,

    // Logical/Format/Canonical errors
    VERIFY_RESULT_BAD_OPCODE,
    VERIFY_RESULT_DISABLED_OPCODE,
    VERIFY_RESULT_INVALID_STACK_OPERATION,
    VERIFY_RESULT_INVALID_ALTSTACK_OPERATION,
    VERIFY_RESULT_UNBALANCED_CONDITIONAL,

    // BIP62 errors
    VERIFY_RESULT_SIG_HASHTYPE,
    VERIFY_RESULT_SIG_DER,
    VERIFY_RESULT_MINIMALDATA,
    VERIFY_RESULT_SIG_PUSHONLY,
    VERIFY_RESULT_SIG_HIGH_S,
    VERIFY_RESULT_SIG_NULLDUMMY,
    VERIFY_RESULT_PUBKEYTYPE,
    VERIFY_RESULT_CLEANSTACK,

    // Softfork safeness
    VERIFY_RESULT_DISCOURAGE_UPGRADABLE_NOPS,

    // Other
    VERIFY_RESULT_OP_RETURN,
    VERIFY_RESULT_UNKNOWN_ERROR,

    // augmention codes for tx deserialization
    VERIFY_RESULT_TX_INVALID,
    VERIFY_RESULT_TX_SIZE_INVALID,
    VERIFY_RESULT_TX_INPUT_INVALID
} verify_result;

typedef enum verify_flags_type
{
    // Set no flags.
    VERIFY_FLAGS_NONE = 0,

    // Evaluate P2SH subscripts (softfork safe, BIP16).
    VERIFY_FLAGS_P2SH = (1U << 0),

    // Passing a non-strict-DER signature or one with undefined hashtype to a
    // checksig operation causes script failure. Evaluating a pubkey that is 
    // not (0x04 + 64 bytes) or (0x02 or 0x03 + 32 bytes) by checksig causes 
    // script failure. (softfork safe, but not used or intended as a consensus
    // rule).
    VERIFY_FLAGS_STRICTENC = (1U << 1),

    // Passing a non-strict-DER signature to a checksig operation causes script
    // failure (softfork safe, BIP62 rule 1)
    VERIFY_FLAGS_DERSIG = (1U << 2),

    // Passing a non-strict-DER signature or one with S > order/2 to a checksig
    // operation causes script failure
    // (softfork safe, BIP62 rule 5).
    VERIFY_FLAGS_LOW_S = (1U << 3),

    // verify dummy stack item consumed by CHECKMULTISIG is of zero-length
    // (softfork safe, BIP62 rule 7).
    VERIFY_FLAGS_NULLDUMMY = (1U << 4),

    // Using a non-push operator in the scriptSig causes script failure
    // (softfork safe, BIP62 rule 2).
    VERIFY_FLAGS_SIGPUSHONLY = (1U << 5),

    // Require minimal encodings for all push operations (OP_0... OP_16,
    // OP_1NEGATE where possible, direct pushes up to 75 bytes, OP_PUSHDATA
    // up to 255 bytes, OP_PUSHDATA2 for anything larger). Evaluating any other
    // push causes the script to fail (BIP62 rule 3). In addition, whenever a
    // stack element is interpreted as a number, it must be of minimal length
    // (BIP62 rule 4).(softfork safe)
    VERIFY_FLAGS_MINIMALDATA = (1U << 6),

    // Discourage use of NOPs reserved for upgrades (NOP1-10)
    //
    // Provided so that nodes can avoid accepting or mining transactions
    // containing executed NOP's whose meaning may change after a soft-fork,
    // thus rendering the script invalid; with this flag set executing
    // discouraged NOPs fails the script. This verification flag will never be
    // a mandatory flag applied to scripts in a block. NOPs that are not
    // executed, e.g.  within an unexecuted IF ENDIF block, are *not* rejected.
    VERIFY_FLAGS_DISCOURAGE_UPGRADABLE_NOPS = (1U << 7),

    // Require that only a single stack element remains after evaluation. This
    // changes the success criterion from "At least one stack element must
    // remain, and when interpreted as a boolean, it must be true" to "Exactly
    // one stack element must remain, and when interpreted as a boolean, it must
    // be true". (softfork safe, BIP62 rule 6)
    // Note: CLEANSTACK should never be used without P2SH.
    VERIFY_FLAGS_CLEANSTACK = (1U << 8)
} verify_flags;

/**
 * Verify that the transaction correctly spends the public key, considering any
 * additional constraints specified by flags.
 * @param[in]  transaction      The transaction with the script to verify.
 * @param[in]  transactionSize  The byte length of the transaction.
 * @param[in]  publicKey        The script public key to verify against.
 * @param[in]  publicKeySize    The byte length of the script public key.
 * @param[in]  inputIndex       The zero-based index of the transaction input
 *                              of which the script is to be verified.
 * @param[in]  flags            Flags for additional verification constraints.
 * @returns                     A script verification result code.
 */
BCX_API verify_result_type verify_script(const uint8_t* transaction,
    size_t transactionSize, const uint8_t* publicKey, size_t publicKeySize,
    uint32_t inputIndex, uint32_t flags);

} // namespace consensus
} // namespace libbitcoin

#endif
