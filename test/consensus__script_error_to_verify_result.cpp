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
#include "script/script_error.h"

using namespace libbitcoin::consensus;

BOOST_AUTO_TEST_SUITE(consensus__script_error_to_verify_result)

// Logical result

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__OK__EVAL_TRUE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_OK), VERIFY_RESULT_EVAL_TRUE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__EVAL_FALSE__EVAL_FALSE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_EVAL_FALSE), VERIFY_RESULT_EVAL_FALSE);
}

// Max size errors

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SCRIPT_SIZE__SCRIPT_SIZE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SCRIPT_SIZE), VERIFY_RESULT_SCRIPT_SIZE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__PUSH_SIZE__PUSH_SIZE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_PUSH_SIZE), VERIFY_RESULT_PUSH_SIZE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__OP_COUNT__OP_COUNT)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_OP_COUNT), VERIFY_RESULT_OP_COUNT);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__STACK_SIZE__STACK_SIZE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_STACK_SIZE), VERIFY_RESULT_STACK_SIZE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_COUNT__SIG_COUNT)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_COUNT), VERIFY_RESULT_SIG_COUNT);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__PUBKEY_COUNT__PUBKEY_COUNT)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_PUBKEY_COUNT), VERIFY_RESULT_PUBKEY_COUNT);
}

// Failed verify operations

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__VERIFY__VERIFY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_VERIFY), VERIFY_RESULT_VERIFY);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__EQUALVERIFY__EQUALVERIFY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_EQUALVERIFY), VERIFY_RESULT_EQUALVERIFY);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__CHECKMULTISIGVERIFY__CHECKMULTISIGVERIFY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_CHECKMULTISIGVERIFY), VERIFY_RESULT_CHECKMULTISIGVERIFY);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__CHECKSIGVERIFY__CHECKSIGVERIFY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_CHECKSIGVERIFY), VERIFY_RESULT_CHECKSIGVERIFY);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__NUMEQUALVERIFY__NUMEQUALVERIFY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_NUMEQUALVERIFY), VERIFY_RESULT_NUMEQUALVERIFY);
}

// Logical/Format/Canonical errors

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__BAD_OPCODE__BAD_OPCODE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_BAD_OPCODE), VERIFY_RESULT_BAD_OPCODE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__DISABLED_OPCODE__DISABLED_OPCODE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_DISABLED_OPCODE), VERIFY_RESULT_DISABLED_OPCODE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__INVALID_STACK_OPERATION__INVALID_STACK_OPERATION)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_INVALID_STACK_OPERATION), VERIFY_RESULT_INVALID_STACK_OPERATION);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__INVALID_ALTSTACK_OPERATION__INVALID_ALTSTACK_OPERATION)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_INVALID_ALTSTACK_OPERATION), VERIFY_RESULT_INVALID_ALTSTACK_OPERATION);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__UNBALANCED_CONDITIONAL__UNBALANCED_CONDITIONAL)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_UNBALANCED_CONDITIONAL), VERIFY_RESULT_UNBALANCED_CONDITIONAL);
}

// BIP62

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_HASHTYPE__SIG_HASHTYPE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_HASHTYPE), VERIFY_RESULT_SIG_HASHTYPE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERR_SIG_DER__ERR_SIG_DER)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_DER), VERIFY_RESULT_SIG_DER);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERR_MINIMALDATA__ERR_MINIMALDATA)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_MINIMALDATA), VERIFY_RESULT_MINIMALDATA);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_PUSHONLY__SIG_PUSHONLY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_PUSHONLY), VERIFY_RESULT_SIG_PUSHONLY);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_HIGH_S__SIG_HIGH_S)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_HIGH_S), VERIFY_RESULT_SIG_HIGH_S);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_NULLDUMMY__SIG_NULLDUMMY)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_NULLDUMMY), VERIFY_RESULT_SIG_NULLDUMMY);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__PUBKEYTYPE__PUBKEYTYPE)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_PUBKEYTYPE), VERIFY_RESULT_PUBKEYTYPE);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__CLEANSTACK__CLEANSTACK)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_CLEANSTACK), VERIFY_RESULT_CLEANSTACK);
}

// Softfork safeness

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___DISCOURAGE_UPGRADABLE_NOPS___DISCOURAGE_UPGRADABLE_NOPS)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_DISCOURAGE_UPGRADABLE_NOPS), VERIFY_RESULT_DISCOURAGE_UPGRADABLE_NOPS);
}

// Other

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__OP_RETURN__OP_RETURN)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_OP_RETURN), VERIFY_RESULT_OP_RETURN);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__UNKNOWN_ERROR__UNKNOWN_ERROR)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_UNKNOWN_ERROR), VERIFY_RESULT_UNKNOWN_ERROR);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERROR_COUNT__UNKNOWN_ERROR)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_ERROR_COUNT), VERIFY_RESULT_UNKNOWN_ERROR);
}

BOOST_AUTO_TEST_SUITE_END()
