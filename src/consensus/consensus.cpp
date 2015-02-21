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
#include <cstddef>
#include <cstdint>
#include <bitcoin/consensus/define.hpp>
#include <bitcoin/consensus/export.hpp>
#include <bitcoin/consensus/version.hpp>
#include "primitives/transaction.h"
#include "script/interpreter.h"
#include "version.h"

namespace libbitcoin {
namespace consensus {

/**
 * Deserialization helper class, not exported.
 */
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

script_verification_result verify_script(
    const uint8_t* publicKey,
    uint32_t publicKeySize,
    const uint8_t* transaction,
    uint32_t transactionSize,
    uint32_t inputIndex,
    uint32_t flags)
{
    CTransaction tx;
    try 
    {
        TxInputStream stream(transaction, transactionSize);
        Unserialize(stream, tx, SER_NETWORK, PROTOCOL_VERSION);
    }
    catch (const std::exception&)
    {
        return script_verification_result::tx_deserialization_failed;
    }

    if (inputIndex >= tx.vin.size())
        return script_verification_result::invalid_tx_index;

    if (tx.GetSerializeSize(SER_NETWORK, PROTOCOL_VERSION) != transactionSize)
        return script_verification_result::invalid_tx_length;

    CScript script(publicKey, publicKey + publicKeySize);
    TransactionSignatureChecker signatureChecker(&tx, inputIndex);
    bool verified = VerifyScript(tx.vin[inputIndex].scriptSig, script, flags, 
        signatureChecker, NULL);

    return verified ? 
        script_verification_result_type::verified : 
        script_verification_result_type::unverified;
}

} // namespace consensus
} // namespace libbitcoin