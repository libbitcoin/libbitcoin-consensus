#
# documentation
#
doc_DATA = README INSTALL COPYING

#
# pkg-config
#
pkgconfig_DATA = libbitcoin-consensus.pc

#
# look for macros in the m4 subdirectory
#
ACLOCAL_AMFLAGS = -I m4

#
# headers
#
bitcoin_includedir = ${includedir}/bitcoin

bitcoin_include_HEADERS = \
    include/bitcoin/consensus.hpp

bitcoin_consensus_includedir = ${includedir}/bitcoin/consensus
bitcoin_consensus_include_HEADERS = \
    include/bitcoin/consensus/define.hpp \
    include/bitcoin/consensus/export.hpp \
    include/bitcoin/consensus/version.hpp

#
# libraries
#
lib_LTLIBRARIES = src/libbitcoin-consensus.la

src_libbitcoin_consensus_la_CPPFLAGS = \
    -I${srcdir}/include \
    -I${srcdir}/src

if WITH_SECP256K1
src_libbitcoin_consensus_la_CPPFLAGS += \
    ${secp256k1_CFLAGS}
else
src_libbitcoin_consensus_la_CPPFLAGS += \
    ${ssl_CFLAGS} \
    ${crypto_CFLAGS}
endif

src_libbitcoin_consensus_la_SOURCES = \
    src/consensus/consensus.cpp \
    src/crypto/hmac_sha512.cpp \
    src/crypto/ripemd160.cpp \
    src/crypto/sha1.cpp \
    src/crypto/sha256.cpp \
    src/crypto/sha512.cpp \
    src/primitives/transaction.cpp \
    src/script/interpreter.cpp \
    src/script/script.cpp \
    src/eccryptoverify.cpp \
    src/hash.cpp \
    src/pubkey.cpp \
    src/uint256.cpp \
    src/utilstrencodings.cpp

if WITH_SECP256K1
else
src_libbitcoin_consensus_la_SOURCES += \
    src/ecwrapper.cpp
endif

if WITH_SECP256K1
src_libbitcoin_consensus_la_LIBADD = \
    ${secp256k1_LIBS}
else
src_libbitcoin_consensus_la_LIBADD = \
    ${ssl_LIBS} \
    ${crypto_LIBS}
endif

#
# tests
#
if WITH_TESTS

TESTS = test/libbitcoin_consensus_test

check_PROGRAMS = test/libbitcoin_consensus_test

test_libbitcoin_consensus_test_CPPFLAGS = \
    -I${srcdir}/include \
    -I${srcdir}/test

if WITH_SECP256K1
test_libbitcoin_consensus_test_CPPFLAGS += \
    ${secp256k1_CFLAGS}
else
test_libbitcoin_consensus_test_CPPFLAGS += \
    ${ssl_CFLAGS} \
    ${crypto_CFLAGS}
endif

test_libbitcoin_consensus_test_SOURCES = \
    test/main.cpp \
    test/script.cpp

#TODO:
#test/script.cpp

test_libbitcoin_consensus_test_LDADD = \
    src/libbitcoin-consensus.la \
    -lboost_unit_test_framework
    
if WITH_SECP256K1
test_libbitcoin_consensus_test_LDADD += \
    ${secp256k1_LIBS}
else
test_libbitcoin_consensus_test_LDADD += \
    ${ssl_LIBS} \
    ${crypto_LIBS}
endif   
    
endif
