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

#include "consensus/secp256k1_initializer.hpp"

#include <secp256k1.h>

namespace libbitcoin {
namespace consensus {

// Statically initialize and clean up on destruct.
secp256k1_initializer secp256k1_initializer::secp256k1 =
    secp256k1_initializer();

// Initialize context on construct.
secp256k1_initializer::secp256k1_initializer()
  : context_(secp256k1_context_create(SECP256K1_CONTEXT_VERIFY))
{
}

// Clean up the context on destruct.
secp256k1_initializer::~secp256k1_initializer()
{
    secp256k1_context_destroy(context_);
}

// Get the context after initialize on construct.
secp256k1_context_t* secp256k1_initializer::context()
{
    return context_;
}

} // namespace consensus
} // namespace libbitcoin

#endif
