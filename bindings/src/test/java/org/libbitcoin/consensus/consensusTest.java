/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
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
package org.libbitcoin.consensus;

import java.math.BigInteger;
import java.util.logging.Logger;
import java.util.logging.Level;
import org.libbitcoin.consensus.*;
import static org.libbitcoin.consensus.verify_flags.*;
import static org.libbitcoin.consensus.verify_result.*;
import static org.libbitcoin.consensus.consensus.*;

public class consensusTest {
  
//    public static final LoadLibrary loadLibrary = new LoadLibrary();
    
    private final static Logger logger = Logger.getLogger(consensusTest.class.getName());
    
    public static void main(String[] args) {
        System.loadLibrary("javawrapconsensus");
		consensus__script_verify__null_tx__throws_invalid_argument();
		consensus__script_verify__value_overflow__throws_invalid_argument();
		consensus__script_verify__null_prevout_script__throws_invalid_argument();
		consensus__script_verify__invalid_tx__tx_invalid();
		consensus__script_verify__invalid_input__tx_input_invalid();
		consensus__script_verify__undersized_tx__tx_invalid();
		consensus__script_verify__oversized_tx__tx_size_invalid();
		consensus__script_verify__incorrect_pubkey_hash__equalverify();
		consensus__script_verify__valid__true();
		consensus__script_verify__valid_nested_p2wpkh__true();
    }

	static boolean decode_base16_private(short[] out, String in)
	{
		for (int i = 0; i < in.length()/2; ++i)
		{
			out[i] = Short.parseShort(in.substring(2*i,2*(i+1)), 16);
		}

		return true;
	}

	static boolean decode_base16(short[][] out, String in)
	{
		// This prevents a last odd character from being ignored:
		if (in.length() % 2 != 0)
			return false;

		short[] result = new short[in.length() / 2];
		if (!decode_base16_private(result, in))
			return false;

		out[0] = result;
		return true;
	}

	static charArray decode_base16(String in)
	{
		// This prevents a last odd character from being ignored:
		if (in.length() % 2 != 0)
			return null;

		charArray result = new charArray(in.length() / 2);
		for (int i = 0; i < in.length()/2; ++i)
		{
			result.setitem(i, Short.parseShort(in.substring(2*i,2*(i+1)), 16));
		}

		return result;
	}

	static verify_result test_verify(String transaction,
		String prevout_script, Object... b)
	{
		
		BigInteger prevout_value = 0<b.length?(BigInteger) b[0]:BigInteger.valueOf(0);
		long tx_input_index = 1<b.length?(long)b[1]:0;
		int flags = 2<b.length?(int)b[2]:verify_flags_p2sh.swigValue();
		long tx_size_hack = 3<b.length?(long)b[3]:0;
		
		charArray tx_data = decode_base16(transaction);
		charArray prevout_script_data = decode_base16(prevout_script);
		verify_result result = verify_script(tx_data.cast(), transaction.length()/2 + tx_size_hack,
			prevout_script_data.cast(), prevout_script.length()/2,
			prevout_value,
			tx_input_index, flags);
		tx_data.delete();
		prevout_script_data.delete();
		return result;
	}

	// Test case derived from:
	// github.com/libbitcoin/libbitcoin-explorer/wiki/How-to-Spend-Bitcoin
	private final static String CONSENSUS_SCRIPT_VERIFY_TX =
		"01000000017d01943c40b7f3d8a00a2d62fa1d560bf739a2368c180615b0a7937c0e883e7c000000006b4830450221008f66d188c664a8088893ea4ddd9689024ea5593877753ecc1e9051ed58c15168022037109f0d06e6068b7447966f751de8474641ad2b15ec37f4a9d159b02af68174012103e208f5403383c77d5832a268c9f71480f6e7bfbdfa44904becacfad66163ea31ffffffff01c8af0000000000001976a91458b7a60f11a904feef35a639b6048de8dd4d9f1c88ac00000000";
	private final static String CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT =
		"76a914c564c740c6900b93afc9f1bdaef0a9d466adf6ee88ac";

	// Test case derived from first witness tx:
	private static final String CONSENSUS_SCRIPT_VERIFY_WITNESS_TX =
		"010000000001015836964079411659db5a4cfddd70e3f0de0261268f86c998a69a143f47c6c83800000000171600149445e8b825f1a17d5e091948545c90654096db68ffffffff02d8be04000000000017a91422c17a06117b40516f9826804800003562e834c98700000000000000004d6a4b424950313431205c6f2f2048656c6c6f20536567576974203a2d29206b656570206974207374726f6e6721204c4c415020426974636f696e20747769747465722e636f6d2f6b6873396e6502483045022100aaa281e0611ba0b5a2cd055f77e5594709d611ad1233e7096394f64ffe16f5b202207e2dcc9ef3a54c24471799ab99f6615847b21be2a6b4e0285918fd025597c5740121021ec0613f21c4e81c4b300426e5e5d30fa651f41e9993223adbe74dbe603c74fb00000000";
	private static final String CONSENSUS_SCRIPT_VERIFY_WITNESS_PREVOUT_SCRIPT =
		"a914642bda298792901eb1b48f654dd7225d99e5e68c87";

	//invalid_argument

	private static void consensus__script_verify__null_tx__throws_invalid_argument()
	{
		charArray prevout_script_data = decode_base16(CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT);
		try {
			verify_script(null, 1, prevout_script_data.cast(), CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT.length()/2, BigInteger.valueOf(0), 0, 0);
		} catch(IllegalArgumentException e) {
			assertTrue("transaction".equals(e.getMessage()));
		} finally {
			prevout_script_data.delete();
		}
	}

	private static void consensus__script_verify__value_overflow__throws_invalid_argument()
	{
		charArray prevout_script_data = decode_base16(CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT);
		try {
			verify_script(null, 1, prevout_script_data.cast(), CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT.length()/2, new BigInteger("ffffffffffffffff", 16), 0, 0);
		} catch(IllegalArgumentException e) {
			assertTrue("value".equals(e.getMessage()));
		} finally {
			prevout_script_data.delete();
		}
	}

	private static void consensus__script_verify__null_prevout_script__throws_invalid_argument()
	{
		charArray tx_data = decode_base16(CONSENSUS_SCRIPT_VERIFY_TX);
		try {
			verify_script(tx_data.cast(), CONSENSUS_SCRIPT_VERIFY_TX.length()/2, null, 1, BigInteger.valueOf(0), 0, 0);
		} catch(IllegalArgumentException e) {
			assertTrue("prevout_script".equals(e.getMessage()));
		} finally {
			tx_data.delete();
		}
	}

	private static void consensus__script_verify__invalid_tx__tx_invalid()
	{
		verify_result result = test_verify("42", "42");
		assertTrue(result == verify_result_tx_invalid);
	}

	private static void consensus__script_verify__invalid_input__tx_input_invalid()
	{
		verify_result result = test_verify(CONSENSUS_SCRIPT_VERIFY_TX, CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT, BigInteger.valueOf(0), 1L);
		assertTrue(result == verify_result_tx_input_invalid);
	}

	private static void consensus__script_verify__undersized_tx__tx_invalid()
	{
		verify_result result = test_verify(CONSENSUS_SCRIPT_VERIFY_TX, CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT, BigInteger.valueOf(0), 0L, verify_flags_p2sh.swigValue(), -1L);
		assertTrue(result == verify_result_tx_invalid);
	}

	private static void consensus__script_verify__oversized_tx__tx_size_invalid()
	{
		verify_result result = test_verify(CONSENSUS_SCRIPT_VERIFY_TX, CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT, BigInteger.valueOf(0), 0L, verify_flags_p2sh.swigValue(), +1L);
		assertTrue(result == verify_result_tx_size_invalid);
	}

	private static void consensus__script_verify__incorrect_pubkey_hash__equalverify()
	{
		verify_result result = test_verify(CONSENSUS_SCRIPT_VERIFY_TX, "76a914c564c740c6900b93afc9f1bdaef0a9d466adf6ef88ac");
		assertTrue(result == verify_result_equalverify);
	}

	private static void consensus__script_verify__valid__true()
	{
		verify_result result = test_verify(CONSENSUS_SCRIPT_VERIFY_TX, CONSENSUS_SCRIPT_VERIFY_PREVOUT_SCRIPT);
		assertTrue(result == verify_result_eval_true);
	}

	private static void consensus__script_verify__valid_nested_p2wpkh__true()
	{
		long index = 0;
		long value = 500000;
		int flags =
			verify_flags_p2sh.swigValue() |
			verify_flags_dersig.swigValue() |
			verify_flags_nulldummy.swigValue() |
			verify_flags_checklocktimeverify.swigValue() |
			verify_flags_checksequenceverify.swigValue() |
			verify_flags_witness.swigValue();

		verify_result result = test_verify(CONSENSUS_SCRIPT_VERIFY_WITNESS_TX, CONSENSUS_SCRIPT_VERIFY_WITNESS_PREVOUT_SCRIPT, BigInteger.valueOf(value), index, flags);
		assertTrue(result == verify_result_eval_true);
	}
	
	public static void assertTrue(boolean success) {
		if (!success) {
			logger.log(Level.SEVERE, "Test Failed!", new RuntimeException("Test Failed."));
		}
	}

	// TODO: create negative test vector.
	//BOOST_AUTO_TEST_CASE(consensus__script_verify__invalid__false)
	//{
	//    const verify_result result = test_verify(...);
	//    BOOST_REQUIRE_EQUAL(result, verify_result_eval_false);
	//}

}
