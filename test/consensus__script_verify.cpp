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

static verify_result test_verify(const std::string& tx,
    const std::string& pubkey, uint32_t index = 0,
    uint32_t flags=verify_flags_none)
{
    data_chunk tx_data, pubkey_data;
    BOOST_REQUIRE(decode_base16(tx_data, tx));
    BOOST_REQUIRE(decode_base16(pubkey_data, pubkey));
    return verify_script(&tx_data[0], tx_data.size(), &pubkey_data[0],
        pubkey_data.size(), index, flags);
}

BOOST_AUTO_TEST_CASE(consensus__script_verify__invalid_tx__tx_invalid)
{
    const verify_result result = test_verify(
        "42",
        "04cb0e9b2d0219af96c14408936ee38251aa347fe66839d310c62766cdd780d4b73e1a55631a0e7a44e5e3d6739b69a6e5714fd917278ef3c9cd5b7b83b622689e");
    BOOST_REQUIRE_EQUAL(result, verify_result_tx_invalid);
}

BOOST_AUTO_TEST_CASE(consensus__script_verify__unsigned_tx__disabled_opcode)
{
    const verify_result result = test_verify(
        "01000000011da9283b4ddf8d89eb996988b89ead56cecdc44041ab38bf787f1206cd90b51e0000000000ffffffff01405dc600000000001976a9140dfc8bafc8419853b34d5e072ad37d1a5159f58488ac00000000",
        "04cb0e9b2d0219af96c14408936ee38251aa347fe66839d310c62766cdd780d4b73e1a55631a0e7a44e5e3d6739b69a6e5714fd917278ef3c9cd5b7b83b622689e");
    BOOST_REQUIRE_EQUAL(result, verify_result_disabled_opcode);
}

// From libbitcoin test
// input 315ac7d4c26d69668129cc352851d9389b4a6868f1509c6c8b66bead11e2619f:0
BOOST_AUTO_TEST_CASE(consensus__script_verify__zero__verified)
{
    const verify_result result = test_verify(
        "0100000002dc38e9359bd7da3b58386204e186d9408685f427f5e513666db735aa8a6b2169000000006a47304402205d8feeb312478e468d0b514e63e113958d7214fa572acd87079a7f0cc026fc5c02200fa76ea05bf243af6d0f9177f241caf606d01fcfd5e62d6befbca24e569e5c27032102100a1a9ca2c18932d6577c58f225580184d0e08226d41959874ac963e3c1b2feffffffffdc38e9359bd7da3b58386204e186d9408685f427f5e513666db735aa8a6b2169010000006b4830450220087ede38729e6d35e4f515505018e659222031273b7366920f393ee3ab17bc1e022100ca43164b757d1a6d1235f13200d4b5f76dd8fda4ec9fc28546b2df5b1211e8df03210275983913e60093b767e85597ca9397fb2f418e57f998d6afbbc536116085b1cbffffffff0140899500000000001976a914fcc9b36d38cf55d7d5b4ee4dddb6b2c17612f48c88ac00000000",
        "02100a1a9ca2c18932d6577c58f225580184d0e08226d41959874ac963e3c1b2fe", 0);
    BOOST_REQUIRE_EQUAL(result, verify_result_bad_opcode);
}

// From libbitcoin test
// input 315ac7d4c26d69668129cc352851d9389b4a6868f1509c6c8b66bead11e2619f:1
BOOST_AUTO_TEST_CASE(consensus__script_verify__one__verified)
{
    const verify_result result = test_verify(
        "0100000002dc38e9359bd7da3b58386204e186d9408685f427f5e513666db735aa8a6b2169000000006a47304402205d8feeb312478e468d0b514e63e113958d7214fa572acd87079a7f0cc026fc5c02200fa76ea05bf243af6d0f9177f241caf606d01fcfd5e62d6befbca24e569e5c27032102100a1a9ca2c18932d6577c58f225580184d0e08226d41959874ac963e3c1b2feffffffffdc38e9359bd7da3b58386204e186d9408685f427f5e513666db735aa8a6b2169010000006b4830450220087ede38729e6d35e4f515505018e659222031273b7366920f393ee3ab17bc1e022100ca43164b757d1a6d1235f13200d4b5f76dd8fda4ec9fc28546b2df5b1211e8df03210275983913e60093b767e85597ca9397fb2f418e57f998d6afbbc536116085b1cbffffffff0140899500000000001976a914fcc9b36d38cf55d7d5b4ee4dddb6b2c17612f48c88ac00000000",
        "0275983913e60093b767e85597ca9397fb2f418e57f998d6afbbc536116085b1cb", 1);
    BOOST_REQUIRE_EQUAL(result, verify_result_bad_opcode);
}

BOOST_AUTO_TEST_SUITE_END()
