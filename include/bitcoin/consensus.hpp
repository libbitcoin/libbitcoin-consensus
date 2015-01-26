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
#ifndef LIBBITCOIN_CONSENSUS_CONSENSUS_HPP
#define LIBBITCOIN_CONSENSUS_CONSENSUS_HPP

// Convenience header that includes everything
// Not to be used internally. For API users.

//#include <bitcoin/consensus/compat.h>
#include <bitcoin/consensus/compat.hpp>
#include <bitcoin/consensus/constants.hpp>
#include <bitcoin/consensus/define.hpp>
#include <bitcoin/consensus/math/checksum.hpp>
#include <bitcoin/consensus/math/ec_keys.hpp>
#include <bitcoin/consensus/math/hash.hpp>
#include <bitcoin/consensus/math/hash_number.hpp>
#include <bitcoin/consensus/math/script_number.hpp>
#include <bitcoin/consensus/utility/array_slice.hpp>
#include <bitcoin/consensus/utility/assert.hpp>
#include <bitcoin/consensus/utility/data.hpp>
#include <bitcoin/consensus/utility/endian.hpp>
#include <bitcoin/consensus/utility/serializer.hpp>
#include <bitcoin/consensus/primitives.hpp>
#include <bitcoin/consensus/satoshi_serialize.hpp>
#include <bitcoin/consensus/script.hpp>
#include <bitcoin/consensus/transaction.hpp>

#endif
