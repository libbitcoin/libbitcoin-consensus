###############################################################################
#  Copyright (c) 2014-2015 libbitcoin-consensus developers (see COPYING).
#
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################

# Standard declarations.
#==============================================================================
# look for macros in the m4 subdirectory
ACLOCAL_AMFLAGS = -I m4


# Automake products.
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
src_libbitcoin_consensus_la_CPPFLAGS = -I${srcdir}/include -I${srcdir}/src ${crypto_CPPFLAGS} ${secp256k1_CPPFLAGS}
src_libbitcoin_consensus_la_LIBADD = ${crypto_LIBS} ${secp256k1_LIBS}
src_libbitcoin_consensus_la_SOURCES = \
    src/eccryptoverify.cpp \
    src/ecwrapper.cpp \
    src/hash.cpp \
    src/pubkey.cpp \
    src/uint256.cpp \
    src/utilstrencodings.cpp \
    src/consensus/consensus.cpp \
    src/crypto/hmac_sha512.cpp \
    src/crypto/ripemd160.cpp \
    src/crypto/sha1.cpp \
    src/crypto/sha256.cpp \
    src/crypto/sha512.cpp \
    src/primitives/transaction.cpp \
    src/script/interpreter.cpp \
    src/script/script.cpp

# local: test/libbitcoin_consensus_test
#------------------------------------------------------------------------------
if WITH_TESTS

# Execute 'test/libbitcoin_consensus_test' as a test.
TESTS = test/libbitcoin_consensus_test

check_PROGRAMS = test/libbitcoin_consensus_test
test_libbitcoin_consensus_test_CPPFLAGS = -I${srcdir}/include -I${srcdir}/src ${crypto_CPPFLAGS} ${secp256k1_CPPFLAGS}
test_libbitcoin_consensus_test_LDADD = src/libbitcoin-consensus.la ${crypto_LIBS} ${secp256k1_LIBS} ${boost_unit_test_framework_LIBS}
test_libbitcoin_consensus_test_SOURCES = \
    test/consensus__script_error_to_verify_result.cpp \
    test/consensus__script_verify.cpp \
    test/consensus__verify_flags_to_script_flags.cpp \
    test/main.cpp

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

# bindings/java/cpp/libbitcoin-consensus-jni.la => ${libdir}
#------------------------------------------------------------------------------
if WITH_JAVA

lib_LTLIBRARIES += bindings/java/cpp/libbitcoin-consensus-jni.la
bindings_java_cpp_libbitcoin_consensus_jni_la_CPPFLAGS = -I${srcdir}/include ${java_CPPFLAGS}
bindings_java_cpp_libbitcoin_consensus_jni_la_LIBADD = src/libbitcoin-consensus.la
bindings_java_cpp_libbitcoin_consensus_jni_la_SOURCES = \
    bindings/java/cpp/consensus_wrap.cpp

endif WITH_JAVA

# files => ${javadir}
#------------------------------------------------------------------------------
if WITH_JAVA

noinst_JAVA = \
    bindings/java/lang/org/libbitcoin/consensus/consensus.java \
    bindings/java/lang/org/libbitcoin/consensus/consensusConstants.java \
    bindings/java/lang/org/libbitcoin/consensus/consensusJNI.java \
    bindings/java/lang/org/libbitcoin/consensus/SWIGTYPE_p_uint32_t.java \
    bindings/java/lang/org/libbitcoin/consensus/SWIGTYPE_p_uint8_t.java \
    bindings/java/lang/org/libbitcoin/consensus/verify_flags.java \
    bindings/java/lang/org/libbitcoin/consensus/verify_result.java

endif WITH_JAVA

# bindings/python/cpp/_bitcoin-consensus.la => ${pkgpyexecdir}
#------------------------------------------------------------------------------
if WITH_PYTHON

pkgpyexec_LTLIBRARIES = bindings/python/cpp/_bitcoin-consensus.la
bindings_python_cpp__bitcoin_consensus_la_CPPFLAGS = -I${srcdir}/include ${python_CPPFLAGS}
bindings_python_cpp__bitcoin_consensus_la_LDFLAGS = -module
bindings_python_cpp__bitcoin_consensus_la_LIBADD = src/libbitcoin-consensus.la
bindings_python_cpp__bitcoin_consensus_la_SOURCES = \
    bindings/python/cpp/consensus_wrap.cpp

endif WITH_PYTHON

# files => ${pkgpythondir}
#------------------------------------------------------------------------------
if WITH_PYTHON

pkgpython_PYTHON = \
    bindings/python/lang/consensus.py

endif WITH_PYTHON

