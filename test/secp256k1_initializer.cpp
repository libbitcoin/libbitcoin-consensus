/**
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
#ifdef USE_SECP256K1

#include <boost/test/unit_test.hpp>
#include "consensus/secp256k1_initializer.hpp"

BOOST_AUTO_TEST_SUITE(secp256k1_initializer)

BOOST_AUTO_TEST_CASE(secp256k1_initializer__get_context)
{
    const secp256k1_context_t* ctx = libbitcoin::consensus::secp256k1_initializer::secp256k1.context();
    BOOST_REQUIRE(ctx != NULL);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
