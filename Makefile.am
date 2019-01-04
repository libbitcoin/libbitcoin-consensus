###############################################################################
#  Copyright (c) 2014-2019 libbitcoin-consensus developers (see COPYING).
#
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################

# Automake settings.
#==============================================================================
# Look for macros in the m4 subdirectory.
#------------------------------------------------------------------------------
ACLOCAL_AMFLAGS = -I m4


# Distribute, make and install products.
#==============================================================================
# files => ${pkgconfigdir}
#------------------------------------------------------------------------------
pkgconfig_DATA = \
    libbitcoin-consensus.pc

# files => ${docdir}
#------------------------------------------------------------------------------
doc_DATA = \
    AUTHORS \
    COPYING \
    ChangeLog \
    INSTALL \
    NEWS \
    README

# src/libbitcoin-consensus.la => ${libdir}
#------------------------------------------------------------------------------
lib_LTLIBRARIES = src/libbitcoin-consensus.la
src_libbitcoin_consensus_la_CPPFLAGS = -I${srcdir}/include -I${srcdir}/src -I${srcdir}/src/clone ${secp256k1_BUILD_CPPFLAGS}
src_libbitcoin_consensus_la_LIBADD = ${secp256k1_LIBS}
src_libbitcoin_consensus_la_SOURCES = \
    src/clone/amount.h \
    src/clone/hash.cpp \
    src/clone/hash.h \
    src/clone/prevector.h \
    src/clone/pubkey.cpp \
    src/clone/pubkey.h \
    src/clone/serialize.h \
    src/clone/tinyformat.h \
    src/clone/uint256.cpp \
    src/clone/uint256.h \
    src/clone/utilstrencodings.cpp \
    src/clone/utilstrencodings.h \
    src/clone/version.h \
    src/clone/compat/byteswap.h \
    src/clone/compat/endian.h \
    src/clone/crypto/common.h \
    src/clone/crypto/hmac_sha512.cpp \
    src/clone/crypto/hmac_sha512.h \
    src/clone/crypto/ripemd160.cpp \
    src/clone/crypto/ripemd160.h \
    src/clone/crypto/sha1.cpp \
    src/clone/crypto/sha1.h \
    src/clone/crypto/sha256.cpp \
    src/clone/crypto/sha256.h \
    src/clone/crypto/sha512.cpp \
    src/clone/crypto/sha512.h \
    src/clone/primitives/transaction.cpp \
    src/clone/primitives/transaction.h \
    src/clone/script/interpreter.cpp \
    src/clone/script/interpreter.h \
    src/clone/script/script.cpp \
    src/clone/script/script.h \
    src/clone/script/script_error.h \
    src/consensus/consensus.cpp \
    src/consensus/consensus.hpp

# local: test/libbitcoin-consensus-test
#------------------------------------------------------------------------------
if WITH_TESTS

TESTS = libbitcoin-consensus-test_runner.sh

check_PROGRAMS = test/libbitcoin-consensus-test
test_libbitcoin_consensus_test_CPPFLAGS = -I${srcdir}/include -I${srcdir}/src -I${srcdir}/src/clone ${boost_BUILD_CPPFLAGS} ${secp256k1_BUILD_CPPFLAGS}
test_libbitcoin_consensus_test_LDFLAGS = ${boost_LDFLAGS}
test_libbitcoin_consensus_test_LDADD = src/libbitcoin-consensus.la ${boost_unit_test_framework_LIBS} ${secp256k1_LIBS}
test_libbitcoin_consensus_test_SOURCES = \
    test/consensus__script_error_to_verify_result.cpp \
    test/consensus__script_verify.cpp \
    test/consensus__verify_flags_to_script_flags.cpp \
    test/main.cpp \
    test/script.hpp

endif WITH_TESTS

# files => ${includedir}/bitcoin
#------------------------------------------------------------------------------
include_bitcoindir = ${includedir}/bitcoin
include_bitcoin_HEADERS = \
    include/bitcoin/consensus.hpp

include_bitcoin_consensusdir = ${includedir}/bitcoin/consensus
include_bitcoin_consensus_HEADERS = \
    include/bitcoin/consensus/define.hpp \
    include/bitcoin/consensus/export.hpp \
    include/bitcoin/consensus/version.hpp

