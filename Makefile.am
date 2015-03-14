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
    
# local: swig
#------------------------------------------------------------------------------
swigdir =
nodist_swig_HEADERS = \
    bindings/consensus.i \
    include/bitcoin/consensus/define.hpp \
    include/bitcoin/consensus/export.hpp \
    include/bitcoin/consensus/version.hpp

# java bindings
#------------------------------------------------------------------------------
if WITH_JAVA

# c++ wrapper library
lib_LTLIBRARIES += bindings/java/cpp/libbitcoin-consensus_jni.la
bindings_java_cpp_libbitcoin_consensus_jni_la_CPPFLAGS = -I${srcdir}/include ${java_CPPFLAGS}
bindings_java_cpp_libbitcoin_consensus_jni_la_LIBADD = src/libbitcoin-consensus.la
bindings_java_cpp_libbitcoin_consensus_jni_la_SOURCES = \
    bindings/java/cpp/consensus_wrap.cpp

# generated directories
generated_java_sources = \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/consensusConstants.java \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/consensus.java \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/consensusJNI.java \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/SWIGTYPE_p_uint32_t.java \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/SWIGTYPE_p_uint8_t.java \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/verify_flags.java \
    ${srcdir}/bindings/java/lang/org/libbitcoin/consensus/verify_result.java
    
generated_java_classes = \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/consensusConstants.class \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/consensus.class \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/consensusJNI.class \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/SWIGTYPE_p_uint32_t.class \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/SWIGTYPE_p_uint8_t.class \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/verify_flags.class \
    ${builddir}/bindings/java/lang/org/libbitcoin/consensus/verify_result.class

# generated single paths
generated_java_wrapper = ${srcdir}/bindings/java/cpp/consensus_wrap.cpp
java_binding_package = libbitcoin-consensus
java_binding_package_name = org.libbitcoin.consensus
java_binding_path_cpp_src = ${srcdir}/bindings/java/cpp
java_binding_path_lang_build = ${builddir}/bindings/java/lang
java_binding_path_lang_build_package = ${builddir}/bindings/java/lang/org/libbitcoin/consensus
java_binding_path_lang_src = ${srcdir}/bindings/java/lang
java_binding_path_lang_src_package = ${srcdir}/bindings/java/lang/org/libbitcoin/consensus
java_classes_jarfile = bindings/java/libbitcoin-consensus.jar
java_sources_jarfile = bindings/java/libbitcoin-consensus.jar

# static build template
swig_java_args = -c++ -java -package ${java_binding_package_name}
${java_classes_jarfile}: ${generated_java_sources}
	${MKDIR_P} ${java_binding_path_lang_build_package}
	${JAVAC} -cp ${java_binding_path_lang_build_package} -d ${java_binding_path_lang_build} ${generated_java_sources}
	${JAR} cf ${JARFLAGS} ${builddir}/${java_classes_jarfile} -C ${java_binding_path_lang_build} .
${java_sources_jarfile}: ${generated_java_sources}
	${MKDIR_P} ${java_binding_path_lang_build_package}
	${JAR} cf ${JARFLAGS} ${builddir}/${java_sources_jarfile} -C ${java_binding_path_lang_src} .
${generated_java_wrapper}: ${nodist_swig_HEADERS}
	${MKDIR_P} ${java_binding_path_cpp_src}
	${MKDIR_P} ${java_binding_path_lang_src_package}
	${SWIG} ${swig_java_args} -outdir ${java_binding_path_lang_src_package} -o $@ $<
${generated_java_sources}: ${nodist_swig_HEADERS}
	${MKDIR_P} ${java_binding_path_cpp_src}
	${MKDIR_P} ${java_binding_path_lang_src_package}
	${SWIG} ${swig_java_args} -outdir ${java_binding_path_lang_src_package} -o ${generated_java_wrapper} $<

# proxy to include jar generation on `make all`
all-local: ${java_sources_jarfile} ${java_classes_jarfile}

# cleanup
java_binaries = \
    ${builddir}/${java_classes_jarfile} \
    ${builddir}/${java_sources_jarfile}

CLEANFILES = \
    ${java_binaries} \
    ${generated_java_classes}

# installation
jardir = ${datadir}/java

install-data-local:
	${MKDIR_P} "${DESTDIR}${jardir}"
	${INSTALL_DATA} ${java_classes_jarfile} "${DESTDIR}${jardir}"

uninstall-local:
	rm -f "${DESTDIR}${jardir}/${classes_jarfile_name}"

endif WITH_JAVA

# python bindings
#------------------------------------------------------------------------------
if WITH_PYTHON

# c++ wrapper library
pkgpyexec_LTLIBRARIES = bindings/python/cpp/_consensus.la
bindings_python_cpp__consensus_la_CPPFLAGS = -I${srcdir}/include ${python_CPPFLAGS} 
bindings_python_cpp__consensus_la_LDFLAGS = -module 
bindings_python_cpp__consensus_la_LIBADD = src/libbitcoin-consensus.la
bindings_python_cpp__consensus_la_SOURCES = \
    bindings/python/cpp/consensus_wrap.cpp

# generated single paths
python_binding_path_cpp_src = ${srcdir}/bindings/python/cpp
python_binding_path_lang_src = ${srcdir}/bindings/python/lang
generated_python_sources = ${srcdir}/bindings/python/lang/consensus.py
generated_python_wrapper = ${srcdir}/bindings/python/cpp/consensus_wrap.cpp

# static build template
swig_python_args = -c++ -python
pkgpython_PYTHON = ${generated_python_sources}
${generated_python_wrapper}: ${nodist_swig_HEADERS}
	${MKDIR_P} ${python_binding_path_cpp_src}
	${MKDIR_P} ${python_binding_path_lang_src}
	${SWIG} ${swig_python_args} -outdir ${python_binding_path_lang_src} -o $@ $<
${generated_python_sources}: ${nodist_swig_HEADERS}
	${MKDIR_P} ${python_binding_path_cpp_src}
	${MKDIR_P} ${python_binding_path_lang_src}
	${SWIG} ${swig_python_args} -outdir ${python_binding_path_lang_src} -o ${generated_python_wrapper} $<

endif WITH_PYTHON
