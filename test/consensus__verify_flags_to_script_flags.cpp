/**
 * Copyright (c) 2011-2019 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>
#include <bitcoin/consensus.hpp>
#include <boost/test/unit_test.hpp>

// These give us test accesss to unpublished symbols.
#include "consensus/consensus.hpp"
#include "script/interpreter.h"

using namespace libbitcoin::consensus;

BOOST_AUTO_TEST_SUITE(consensus__verify_flags_to_script_flags)

// Unnamed enum values require cast for boost comparison macros.

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__none__NONE)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_none), (uint32_t)SCRIPT_VERIFY_NONE);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__p2sh__P2SH)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_p2sh), (uint32_t)SCRIPT_VERIFY_P2SH);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__strictenc__STRICTENC)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_strictenc), (uint32_t)SCRIPT_VERIFY_STRICTENC);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__dersig__DERSIG)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_dersig), (uint32_t)SCRIPT_VERIFY_DERSIG);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__low_s__LOW_S)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_low_s), (uint32_t)SCRIPT_VERIFY_LOW_S);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__nulldummy__NULLDUMMY)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_nulldummy), (uint32_t)SCRIPT_VERIFY_NULLDUMMY);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__sigpushonly__SIGPUSHONLY)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_sigpushonly), (uint32_t)SCRIPT_VERIFY_SIGPUSHONLY);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__minimaldata__MINIMALDATA)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_minimaldata), (uint32_t)SCRIPT_VERIFY_MINIMALDATA);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__discourage_upgradable_nops__DISCOURAGE_UPGRADABLE_NOPS)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_discourage_upgradable_nops), (uint32_t)SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_NOPS);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__cleanstack__CLEANSTACK)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_cleanstack), (uint32_t)SCRIPT_VERIFY_CLEANSTACK);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__checklocktimeverify__CHECKLOCKTIMEVERIFY)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_checklocktimeverify), (uint32_t)SCRIPT_VERIFY_CHECKLOCKTIMEVERIFY);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__checksequenceverify__CHECKSEQUENCEVERIFY)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_checksequenceverify), (uint32_t)SCRIPT_VERIFY_CHECKSEQUENCEVERIFY);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__witness__WITNESS)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_witness), (uint32_t)SCRIPT_VERIFY_WITNESS);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__discourage_upgradable_witness_program__DISCOURAGE_UPGRADABLE_WITNESS_PROGRAM)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_discourage_upgradable_witness_program), (uint32_t)SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_WITNESS_PROGRAM);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__minimal_if__MINIMALIF)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_minimal_if), (uint32_t)SCRIPT_VERIFY_MINIMALIF);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__null_fail__NULLFAIL)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_null_fail), (uint32_t)SCRIPT_VERIFY_NULLFAIL);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__witness_public_key_compressed__PUBKEYTYPE)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(verify_flags_witness_public_key_compressed), (uint32_t)SCRIPT_VERIFY_WITNESS_PUBKEYTYPE);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__all__all)
{
    const uint32_t all_verify_flags =
        verify_flags_none |
        verify_flags_p2sh |
        verify_flags_strictenc |
        verify_flags_dersig |
        verify_flags_low_s |
        verify_flags_nulldummy |
        verify_flags_sigpushonly |
        verify_flags_minimaldata |
        verify_flags_discourage_upgradable_nops |
        verify_flags_cleanstack |
        verify_flags_checklocktimeverify |
        verify_flags_checksequenceverify |
        verify_flags_witness |
        verify_flags_discourage_upgradable_witness_program |
        verify_flags_minimal_if |
        verify_flags_null_fail |
        verify_flags_witness_public_key_compressed;

    const uint32_t all_script_flags =
        SCRIPT_VERIFY_NONE |
        SCRIPT_VERIFY_P2SH |
        SCRIPT_VERIFY_STRICTENC |
        SCRIPT_VERIFY_DERSIG |
        SCRIPT_VERIFY_LOW_S |
        SCRIPT_VERIFY_NULLDUMMY |
        SCRIPT_VERIFY_SIGPUSHONLY |
        SCRIPT_VERIFY_MINIMALDATA |
        SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_NOPS |
        SCRIPT_VERIFY_CLEANSTACK |
        SCRIPT_VERIFY_CHECKLOCKTIMEVERIFY |
        SCRIPT_VERIFY_CHECKSEQUENCEVERIFY |
        SCRIPT_VERIFY_WITNESS |
        SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_WITNESS_PROGRAM |
        SCRIPT_VERIFY_MINIMALIF |
        SCRIPT_VERIFY_NULLFAIL |
        SCRIPT_VERIFY_WITNESS_PUBKEYTYPE;

    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(all_verify_flags), all_script_flags);
}

BOOST_AUTO_TEST_SUITE_END()
