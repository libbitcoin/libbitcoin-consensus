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
#include <stdint.h>
#include <bitcoin/consensus.hpp>
#include <boost/test/unit_test.hpp>

// These give us test accesss to unpublished symbols.
#include "consensus/consensus.h"
#include "script/interpreter.h"

using namespace libbitcoin::consensus;

BOOST_AUTO_TEST_SUITE(consensus__verify_flags_to_script_flags)

// Unnamed enum values require cast for boost comparison macros.

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__NONE__NONE)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_NONE), (uint32_t)SCRIPT_VERIFY_NONE);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__P2SH__P2SH)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_P2SH), (uint32_t)SCRIPT_VERIFY_P2SH);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__STRICTENC__STRICTENC)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_STRICTENC), (uint32_t)SCRIPT_VERIFY_STRICTENC);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__DERSIG__DERSIG)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_DERSIG), (uint32_t)SCRIPT_VERIFY_DERSIG);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__LOW_S__LOW_S)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_LOW_S), (uint32_t)SCRIPT_VERIFY_LOW_S);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__NULLDUMMY__NULLDUMMY)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_NULLDUMMY), (uint32_t)SCRIPT_VERIFY_NULLDUMMY);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__SIGPUSHONLY__SIGPUSHONLY)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_SIGPUSHONLY), (uint32_t)SCRIPT_VERIFY_SIGPUSHONLY);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__MINIMALDATA__MINIMALDATA)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_MINIMALDATA), (uint32_t)SCRIPT_VERIFY_MINIMALDATA);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__DISCOURAGE_UPGRADABLE_NOPS__DISCOURAGE_UPGRADABLE_NOPS)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_DISCOURAGE_UPGRADABLE_NOPS), (uint32_t)SCRIPT_VERIFY_DISCOURAGE_UPGRADABLE_NOPS);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__CLEANSTACK__CLEANSTACK)
{
    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(VERIFY_FLAGS_CLEANSTACK), (uint32_t)SCRIPT_VERIFY_CLEANSTACK);
}

BOOST_AUTO_TEST_CASE(consensus__verify_flags_to_script_flags__all__all)
{
    const uint32_t all_verify_flags =
        VERIFY_FLAGS_NONE |
        VERIFY_FLAGS_P2SH |
        VERIFY_FLAGS_STRICTENC |
        VERIFY_FLAGS_DERSIG |
        VERIFY_FLAGS_LOW_S |
        VERIFY_FLAGS_NULLDUMMY |
        VERIFY_FLAGS_SIGPUSHONLY |
        VERIFY_FLAGS_MINIMALDATA |
        VERIFY_FLAGS_DISCOURAGE_UPGRADABLE_NOPS |
        VERIFY_FLAGS_CLEANSTACK;

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
        SCRIPT_VERIFY_CLEANSTACK;

    BOOST_REQUIRE_EQUAL(verify_flags_to_script_flags(all_verify_flags), all_script_flags);
}

BOOST_AUTO_TEST_SUITE_END()
