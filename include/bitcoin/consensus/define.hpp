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
#ifndef LIBBITCOIN_CONSENSUS_DEFINE_HPP
#define LIBBITCOIN_CONSENSUS_DEFINE_HPP

// See http://gcc.gnu.org/wiki/Visibility

// Generic helper definitions for shared library support
#if defined _MSC_VER || defined __CYGWIN__
    #define BCX_HELPER_DLL_IMPORT __declspec(dllimport)
    #define BCX_HELPER_DLL_EXPORT __declspec(dllexport)
    #define BCX_HELPER_DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define BCX_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
        #define BCX_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
        #define BCX_HELPER_DLL_LOCAL  __attribute__ ((visibility ("internal")))
    #else
        #define BCX_HELPER_DLL_IMPORT
        #define BCX_HELPER_DLL_EXPORT
        #define BCX_HELPER_DLL_LOCAL
    #endif
#endif

// Now we use the generic helper definitions above to
// define BCX_API and BCX_INTERNAL.
// BCX_API is used for the public API symbols. It either DLL imports or
// DLL exports (or does nothing for static build)
// BCX_INTERNAL is used for non-api symbols.

#if defined BCX_STATIC
    #define BCX_API
    #define BCX_INTERNAL
#elif defined BCX_DLL
    #define BCX_API      BCX_HELPER_DLL_EXPORT
    #define BCX_INTERNAL BCX_HELPER_DLL_LOCAL
#else
    #define BCX_API      BCX_HELPER_DLL_IMPORT
    #define BCX_INTERNAL BCX_HELPER_DLL_LOCAL
#endif

#endif
