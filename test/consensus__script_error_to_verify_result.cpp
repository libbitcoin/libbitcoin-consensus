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
#include "script/script_error.h"

using namespace libbitcoin::consensus;

BOOST_AUTO_TEST_SUITE(consensus__script_error_to_verify_result)

// Logical result

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__OK__eval_true)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_OK), verify_result_eval_true);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__EVAL_FALSE__eval_false)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_EVAL_FALSE), verify_result_eval_false);
}

// Max size errors.

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SCRIPT_SIZE__script_size)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SCRIPT_SIZE), verify_result_script_size);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__PUSH_SIZE__push_size)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_PUSH_SIZE), verify_result_push_size);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__OP_COUNT__op_count)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_OP_COUNT), verify_result_op_count);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__STACK_SIZE__stack_size)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_STACK_SIZE), verify_result_stack_size);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_COUNT__sig_count)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_COUNT), verify_result_sig_count);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__PUBKEY_COUNT__pubkey_count)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_PUBKEY_COUNT), verify_result_pubkey_count);
}

// Failed verify operations

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__VERIFY__verify)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_VERIFY), verify_result_verify);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__EQUALVERIFY__equalverify)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_EQUALVERIFY), verify_result_equalverify);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__CHECKMULTISIGVERIFY__checkmultisigverify)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_CHECKMULTISIGVERIFY), verify_result_checkmultisigverify);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__CHECKSIGVERIFY__checksigverify)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_CHECKSIGVERIFY), verify_result_checksigverify);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__NUMEQUALVERIFY__numequalverify)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_NUMEQUALVERIFY), verify_result_numequalverify);
}

// Logical/Format/Canonical errors

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__BAD_OPCODE__bad_opcode)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_BAD_OPCODE), verify_result_bad_opcode);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__DISABLED_OPCODE__disabled_opcode)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_DISABLED_OPCODE), verify_result_disabled_opcode);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__INVALID_STACK_OPERATION__invalid_stack_operation)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_INVALID_STACK_OPERATION), verify_result_invalid_stack_operation);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__INVALID_ALTSTACK_OPERATION__invalid_altstack_operation)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_INVALID_ALTSTACK_OPERATION), verify_result_invalid_altstack_operation);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__UNBALANCED_CONDITIONAL__unbalanced_conditional)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_UNBALANCED_CONDITIONAL), verify_result_unbalanced_conditional);
}

// BIP65

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__NEGATIVE_LOCKTIME__sig_hashtype)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_NEGATIVE_LOCKTIME), verify_result_negative_locktime);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERR_UNSATISFIED_LOCKTIME__err_sig_der)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_UNSATISFIED_LOCKTIME), verify_result_unsatisfied_locktime);
}

// BIP62

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_HASHTYPE__sig_hashtype)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_HASHTYPE), verify_result_sig_hashtype);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERR_SIG_DER__err_sig_der)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_DER), verify_result_sig_der);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERR_MINIMALDATA__err_minimaldata)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_MINIMALDATA), verify_result_minimaldata);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_PUSHONLY__sig_pushonly)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_PUSHONLY), verify_result_sig_pushonly);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_HIGH_S__sig_high_s)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_HIGH_S), verify_result_sig_high_s);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_NULLDUMMY__sig_nulldummy)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_NULLDUMMY), verify_result_sig_nulldummy);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__PUBKEYTYPE__pubkeytype)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_PUBKEYTYPE), verify_result_pubkeytype);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__CLEANSTACK__cleanstack)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_CLEANSTACK), verify_result_cleanstack);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__MINIMALIF__minimalif)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_MINIMALIF), verify_result_minimalif);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__SIG_NULLFAIL__nullfail)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_SIG_NULLFAIL), verify_result_sig_nullfail);
}

// Softfork safeness

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___DISCOURAGE_UPGRADABLE_NOPS___discourage_upgradable_nops)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_DISCOURAGE_UPGRADABLE_NOPS), verify_result_discourage_upgradable_nops);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___DISCOURAGE_UPGRADABLE_WITNESS_PROGRAM___discourage_upgradable_witness_program)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_DISCOURAGE_UPGRADABLE_WITNESS_PROGRAM), verify_result_discourage_upgradable_witness_program);
}

// Segregated witness

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_PROGRAM_WRONG_LENGTH___witness_program_wrong_length)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_PROGRAM_WRONG_LENGTH), verify_result_witness_program_wrong_length);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_PROGRAM_WITNESS_EMPTY___witness_program_empty_witness)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_PROGRAM_WITNESS_EMPTY), verify_result_witness_program_empty_witness);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_PROGRAM_MISMATCH___witness_program_mismatch)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_PROGRAM_MISMATCH), verify_result_witness_program_mismatch);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_MALLEATED___witness_malleated)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_MALLEATED), verify_result_witness_malleated);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_MALLEATED_P2SH___witness_malleated_p2sh)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_MALLEATED_P2SH), verify_result_witness_malleated_p2sh);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_UNEXPECTED___witness_unexpected)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_UNEXPECTED), verify_result_witness_unexpected);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result___WITNESS_PUBKEYTYPE___witness_pubkeytype)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_WITNESS_PUBKEYTYPE), verify_result_witness_pubkeytype);
}

// Other

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__OP_RETURN__op_return)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_OP_RETURN), verify_result_op_return);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__UNKNOWN_ERROR__unknown_error)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_UNKNOWN_ERROR), verify_result_unknown_error);
}

BOOST_AUTO_TEST_CASE(consensus__script_error_to_verify_result__ERROR_COUNT__unknown_error)
{
    BOOST_REQUIRE_EQUAL(script_error_to_verify_result(SCRIPT_ERR_ERROR_COUNT), verify_result_unknown_error);
}

BOOST_AUTO_TEST_SUITE_END()
