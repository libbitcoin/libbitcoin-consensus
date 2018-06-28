###############################################################################
#  Copyright (c) 2014-2015 libbitcoin-consensus developers (see COPYING).
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

# bindings/java/wrap/libbitcoin-consensus-jni.la => ${libdir}
#------------------------------------------------------------------------------
if WITH_JAVA

lib_LTLIBRARIES += bindings/java/wrap/libbitcoin-consensus-jni.la
bindings_java_wrap_libbitcoin_consensus_jni_la_CPPFLAGS = -I${srcdir}/include ${java_BUILD_CPPFLAGS} ${secp256k1_BUILD_CPPFLAGS}
bindings_java_wrap_libbitcoin_consensus_jni_la_LIBADD = src/libbitcoin-consensus.la ${secp256k1_LIBS}
bindings_java_wrap_libbitcoin_consensus_jni_la_SOURCES = \
    bindings/java/wrap/consensus.cpp

endif WITH_JAVA

# *.java => *.class (local), requires ax_java_devel.m4
#------------------------------------------------------------------------------
if WITH_JAVA

dist_noinst_JAVA = \
    bindings/java/proxy/org/libbitcoin/consensus/SWIGTYPE_p_unsigned_char.java \
    bindings/java/proxy/org/libbitcoin/consensus/consensus.java \
    bindings/java/proxy/org/libbitcoin/consensus/consensusConstants.java \
    bindings/java/proxy/org/libbitcoin/consensus/consensusJNI.java \
    bindings/java/proxy/org/libbitcoin/consensus/verify_flags.java \
    bindings/java/proxy/org/libbitcoin/consensus/verify_result.java

CLEANFILES = ${java_builddir}/*.class

distclean-local:
	-rm -rf ${java_builddir} ${jar_builddir}

endif WITH_JAVA

# *.class => *.jar => ${jarexecdir}, requires ax_java_devel.m4
#------------------------------------------------------------------------------
if WITH_JAVA

nodist_jarexec_DATA = \
    ${jar_builddir}/org.libbitcoin.consensus-${VERSION}.jar

${nodist_jarexec_DATA}: classnoinst.stamp
	${JAR} cf ${JARFLAGS} ${nodist_jarexec_DATA} -C ${java_builddir} .

CLEANFILES += ${jar_builddir}/*.jar

endif WITH_JAVA

# bindings/python/wrap/_bitcoin-consensus.la => ${pkgpyexecdir}
#------------------------------------------------------------------------------
if WITH_PYTHON

pkgpyexec_LTLIBRARIES = bindings/python/wrap/_bitcoin-consensus.la
bindings_python_wrap__bitcoin_consensus_la_CPPFLAGS = -I${srcdir}/include ${python_BUILD_CPPFLAGS} ${secp256k1_BUILD_CPPFLAGS}
bindings_python_wrap__bitcoin_consensus_la_LDFLAGS = -module
bindings_python_wrap__bitcoin_consensus_la_LIBADD = src/libbitcoin-consensus.la ${secp256k1_LIBS}
bindings_python_wrap__bitcoin_consensus_la_SOURCES = \
    bindings/python/wrap/consensus.cpp

endif WITH_PYTHON

# files => ${pkgpythondir}
#------------------------------------------------------------------------------
if WITH_PYTHON

pkgpython_PYTHON = \
    bindings/python/proxy/consensus.py

endif WITH_PYTHON


# Custom make targets.
#==============================================================================
# make target: java
#------------------------------------------------------------------------------
target_java = \
    bindings/java/wrap/libbitcoin-consensus-jni.la

java: ${target_java}

# make target: python
#------------------------------------------------------------------------------
target_python = \
    bindings/python/wrap/_bitcoin-consensus.la

python: ${target_python}

