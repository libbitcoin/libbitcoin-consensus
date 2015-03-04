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

BUILT_SOURCES =

#
# libraries
#
lib_LTLIBRARIES = \
    src/libbitcoin-consensus.la

src_libbitcoin_consensus_la_CPPFLAGS = \
    -I${srcdir}/include \
    -I${srcdir}/src

if WITH_SECP256K1
src_libbitcoin_consensus_la_CPPFLAGS += \
    ${secp256k1_CFLAGS}

src_libbitcoin_consensus_la_LIBADD = \
    ${secp256k1_LIBS}
else
src_libbitcoin_consensus_la_CPPFLAGS += \
    ${ssl_CFLAGS} \
    ${crypto_CFLAGS}

src_libbitcoin_consensus_la_LIBADD = \
    ${ssl_LIBS} \
    ${crypto_LIBS}
endif

bitcoin_includedir = ${includedir}/bitcoin
bitcoin_include_HEADERS = \
    include/bitcoin/consensus.hpp

bitcoin_consensus_includedir = ${includedir}/bitcoin/consensus
bitcoin_consensus_include_HEADERS = \
    include/bitcoin/consensus/define.hpp \
    include/bitcoin/consensus/export.hpp \
    include/bitcoin/consensus/version.hpp

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

#
# bindings
#
if WITH_BINDINGS
SWIG_SOURCES = \
    bindings/consensus.i \
    include/bitcoin/consensus/define.hpp \
    include/bitcoin/consensus/export.hpp \
    include/bitcoin/consensus/version.hpp

if WITH_JAVA
endif

if WITH_PYTHON
BUILT_SOURCES += \
    bindings/python/consensus_wrap.cpp \
    bindings/python/consensus.py

pkgpython_PYTHON = bindings/python/consensus.py

pkgpyexec_LTLIBRARIES = bindings/python/_consensus.la

bindings_python__consensus_la_SOURCES = \
    bindings/python/consensus_wrap.cpp \
    ${SWIG_SOURCES}

bindings_python__consensus_la_CPPFLAGS = \
    ${AX_SWIG_PYTHON_CPPFLAGS} \
    -I${srcdir}/include

bindings_python__consensus_la_LDFLAGS = \
    -module

bindings_python__consensus_la_LIBADD = \
    ${builddir}/src/libbitcoin-consensus.la

bindings/python/consensus_wrap.cpp bindings/python/consensus.py : ${SWIG_SOURCES}
	${SWIG} ${AX_SWIG_PYTHON_OPT} -c++ -outdir bindings/python -o $@ $<

endif

endif

#
# tests
#
if WITH_TESTS

TESTS = \
    test/libbitcoin_consensus_test

check_PROGRAMS = \
    test/libbitcoin_consensus_test

test_libbitcoin_consensus_test_CPPFLAGS = \
    -I${srcdir}/include \
    -I${srcdir}/src \
    -I${srcdir}/test

if WITH_SECP256K1
test_libbitcoin_consensus_test_CPPFLAGS += \
    ${secp256k1_CFLAGS}
else
test_libbitcoin_consensus_test_CPPFLAGS += \
    ${ssl_CFLAGS} \
    ${crypto_CFLAGS}
endif

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

test_libbitcoin_consensus_test_SOURCES = \
    test/main.cpp \
    test/consensus__script_verify.cpp \
    test/consensus__verify_flags_to_script_flags.cpp \
    test/consensus__script_error_to_verify_result.cpp

endif
