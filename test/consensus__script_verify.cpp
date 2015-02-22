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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
//#include "script.hpp"

#include <stdint.h>
#include <string>
#include <vector>
#include <bitcoin/consensus.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(consensus__script_verify)

using namespace libbitcoin::consensus;

typedef std::vector<uint8_t> data_chunk;

static unsigned from_hex(const char ch)
{
    if ('A' <= ch && ch <= 'F')
        return 10 + ch - 'A';

    if ('a' <= ch && ch <= 'f')
        return 10 + ch - 'a';

    return ch - '0';
}

static bool decode_base16_private(uint8_t* out, size_t size, const char* in)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (!isxdigit(in[0]) || !isxdigit(in[1]))
            return false;

        out[i] = (from_hex(in[0]) << 4) + from_hex(in[1]);
        in += 2;
    }

    return true;
}

static bool decode_base16(data_chunk& out, const std::string& in)
{
    // This prevents a last odd character from being ignored:
    if (in.size() % 2 != 0)
        return false;

    data_chunk result(in.size() / 2);
    if (!decode_base16_private(result.data(), result.size(), in.data()))
        return false;

    out = result;
    return true;
}

static verify_result test_verify(const std::string& transaction,
    const std::string& prevout_script, uint32_t tx_input_index=0,
    uint32_t flags=(verify_flags_standard | verify_flags_mandatory))
{
    data_chunk tx_data, prevout_script_data;
    BOOST_REQUIRE(decode_base16(tx_data, transaction));
    BOOST_REQUIRE(decode_base16(prevout_script_data, prevout_script));
    return verify_script(&tx_data[0], tx_data.size(), &prevout_script_data[0],
        prevout_script_data.size(), tx_input_index, flags);
}

BOOST_AUTO_TEST_CASE(consensus__script_verify__invalid_tx__tx_invalid)
{
    const verify_result result = test_verify("42", "42");
    BOOST_REQUIRE_EQUAL(result, verify_result_tx_invalid);
}

BOOST_AUTO_TEST_SUITE_END()
