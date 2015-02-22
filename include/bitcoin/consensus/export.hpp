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

/**
 * Result codes for script calls.
 */
enum script_verification_result
{
    /**
     * The script verified successfully.
     */
    script_verified = 0,

    /**
     * The script failed to verify.
     */
     script_unverified = 1,

    /**
     * The transaction index exceeds the number of transaction inputs.
     */
     script_invalid_tx_index = 2,

    /**
     * The transaction deserialized to a length other than specified.
     */
     script_invalid_tx_length = 3,

    /**
     * The transaction failed to deserialize.
     */
     script_tx_deserialization_failed = 4
};

/**
 * Additional flags for script verification.
 */
enum script_verification_flags
{
    /**
     * No flags.
     */
    verify_none = 0,

    /**
     * Evaluate BIP16 (P2SH subscripts).
     */
    verify_bip16 = (1U << 0),

    /**
     * Enforce BIP66 (strict DER compliance).
     */
    verify_bip66 = (1U << 2)
};

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
 * @returns                     A script verification result with a value of
 *                              okay if the script verifies.
 */
BCX_API int verify_script(const uint8_t* transaction, size_t transactionSize,
    const uint8_t* publicKey, size_t publicKeySize, uint32_t inputIndex, 
    uint32_t flags);

} // namespace consensus
} // namespace libbitcoin

#endif
