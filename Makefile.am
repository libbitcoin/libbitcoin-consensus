#
# documentation
#
doc_DATA = README INSTALL COPYING

#
# pkg-config
#
pkgconfig_DATA = libbitcoin-consensus.pc

# look for macros in the m4 subdirectory
ACLOCAL_AMFLAGS = -I m4

#
# headers
#
bitcoin_includedir = ${includedir}/bitcoin

bitcoin_include_HEADERS = \
    include/bitcoin/consensus.hpp

bitcoin_consensus_includedir = ${includedir}/bitcoin/consensus
bitcoin_consensus_include_HEADERS = \
    include/bitcoin/consensus/compat.h \
    include/bitcoin/consensus/compat.hpp \
    include/bitcoin/consensus/constants.hpp \
    include/bitcoin/consensus/define.hpp \
    include/bitcoin/consensus/primitives.hpp \
    include/bitcoin/consensus/satoshi_serialize.hpp \
    include/bitcoin/consensus/script.hpp \
    include/bitcoin/consensus/transaction.hpp

bitcoin_consensus_impl_serialize_includedir = ${includedir}/bitcoin/consensus/impl/serialize
bitcoin_consensus_impl_serialize_include_HEADERS = \
    include/bitcoin/consensus/impl/serialize/block.ipp \
    include/bitcoin/consensus/impl/serialize/misc.ipp

bitcoin_consensus_math_includedir = ${includedir}/bitcoin/consensus/math
bitcoin_consensus_math_include_HEADERS = \
    include/bitcoin/consensus/math/checksum.hpp \
    include/bitcoin/consensus/math/ec_keys.hpp \
    include/bitcoin/consensus/math/hash.hpp \
    include/bitcoin/consensus/math/hash_number.hpp \
    include/bitcoin/consensus/math/script_number.hpp

bitcoin_consensus_math_external_includedir = ${includedir}/bitcoin/consensus/math/external
bitcoin_consensus_math_external_include_HEADERS = \
    include/bitcoin/consensus/math/external/hmac_sha256.h \
    include/bitcoin/consensus/math/external/hmac_sha512.h \
    include/bitcoin/consensus/math/external/ripemd160.h \
    include/bitcoin/consensus/math/external/sha1.h \
    include/bitcoin/consensus/math/external/sha256.h \
    include/bitcoin/consensus/math/external/sha512.h \
    include/bitcoin/consensus/math/external/uint256.h \
    include/bitcoin/consensus/math/external/zeroize.h

bitcoin_consensus_util_includedir = ${includedir}/bitcoin/consensus/utility
bitcoin_consensus_util_include_HEADERS = \
    include/bitcoin/consensus/utility/array_slice.hpp \
    include/bitcoin/consensus/utility/assert.hpp \
    include/bitcoin/consensus/utility/data.hpp \
    include/bitcoin/consensus/utility/endian.hpp \
    include/bitcoin/consensus/utility/serializer.hpp

bitcoin_consensus_impl_utility_includedir = ${includedir}/bitcoin/consensus/impl/utility
bitcoin_consensus_impl_utility_include_HEADERS = \
    include/bitcoin/consensus/impl/utility/array_slice.ipp \
    include/bitcoin/consensus/impl/utility/data.ipp \
    include/bitcoin/consensus/impl/utility/endian.ipp \
    include/bitcoin/consensus/impl/utility/serializer.ipp

#
# libraries
#
lib_LTLIBRARIES = src/libbitcoin-consensus.la

src_libbitcoin_consensus_la_CPPFLAGS = \
    -I${srcdir}/include \
    ${secp256k1_CFLAGS}

src_libbitcoin_consensus_la_SOURCES = \
    src/math/checksum.cpp \
    src/math/ec_keys.cpp \
    src/math/external/hmac_sha256.c \
    src/math/external/hmac_sha512.c \
    src/math/external/ripemd160.c \
    src/math/external/sha1.c \
    src/math/external/sha256.c \
    src/math/external/sha512.c \
    src/math/external/zeroize.c \
    src/math/hash.cpp \
    src/math/hash_number.cpp \
    src/math/script_number.cpp \
    src/satoshi_serialize.cpp \
    src/script.cpp \
    src/transaction.cpp

src_libbitcoin_consensus_la_LIBADD = \
    ${secp256k1_LIBS}

#
# tests
#
if WITH_TESTS

TESTS = test/libbitcoin_consensus_test

check_PROGRAMS = test/libbitcoin_consensus_test

test_libbitcoin_consensus_test_CPPFLAGS = \
    -I${srcdir}/include \
    -I${srcdir}/test \
    ${secp256k1_CFLAGS}

test_libbitcoin_consensus_test_SOURCES = \
    test/main.cpp \
    test/script.cpp

test_libbitcoin_consensus_test_LDADD = \
    src/libbitcoin-consensus.la \
    -lboost_unit_test_framework \
    ${secp256k1_LIBS}
    
endif
