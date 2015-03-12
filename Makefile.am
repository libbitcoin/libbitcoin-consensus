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

#
# java
#
if WITH_JAVA
JAVA_BINDING_PATH_CPP_SRC=${srcdir}/${JAVA_BINDING_PATH_CPP}

JAVA_BINDING_PATH_LANG_BUILD=${builddir}/${JAVA_BINDING_PATH_LANG}
JAVA_BINDING_PATH_LANG_BUILD_PACKAGE=${JAVA_BINDING_PATH_LANG_BUILD}/${JAVA_BINDING_PACKAGE_PATH}
JAVA_BINDING_PATH_LANG_SRC=${srcdir}/${JAVA_BINDING_PATH_LANG}
JAVA_BINDING_PATH_LANG_SRC_PACKAGE=${JAVA_BINDING_PATH_LANG_SRC}/${JAVA_BINDING_PACKAGE_PATH}

generated_java_sources = \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/consensusConstants.java \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/consensus.java \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/consensusJNI.java \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/SWIGTYPE_p_uint32_t.java \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/SWIGTYPE_p_uint8_t.java \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/verify_flags.java \
    ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}/verify_result.java

generated_java_classes = \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/consensusConstants.class \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/consensus.class \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/consensusJNI.class \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/SWIGTYPE_p_uint32_t.class \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/SWIGTYPE_p_uint8_t.class \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/verify_flags.class \
    ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}/verify_result.class

generated_java_wrapper = \
    ${JAVA_BINDING_PATH_CPP_SRC}/consensus_wrap.cpp

# language specific
classes_jarfile_name=libbitcoin-consensus.jar
classes_jarfile = ${JAVA_BINDING_PATH_BASE}/${classes_jarfile_name}
sources_jarfile_name=libbitcoin-consensus-sources.jar
sources_jarfile = ${JAVA_BINDING_PATH_BASE}/${sources_jarfile_name}

# c++ wrapper library
lib_LTLIBRARIES += bindings/java/cpp/libbitcoin-consensus_jni.la

bindings_java_cpp_libbitcoin_consensus_jni_la_SOURCES = \
    bindings/java/cpp/consensus_wrap.cpp \
    ${SWIG_SOURCES}

bindings_java_cpp_libbitcoin_consensus_jni_la_CPPFLAGS = ${JAVA_BINDING_CFLAGS} \
    -I${srcdir}/include

bindings_java_cpp_libbitcoin_consensus_jni_la_LIBADD = ${JAVA_BINDING_LIBS} \
    ${builddir}/src/libbitcoin-consensus.la

# custom build rules
${classes_jarfile}: ${generated_java_sources}
	${MKDIR_P} ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}
	${JAVAC} -cp ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE} -d ${JAVA_BINDING_PATH_LANG_BUILD} ${generated_java_sources}
	${JAR} cf ${JARFLAGS} ${builddir}/${classes_jarfile} -C ${JAVA_BINDING_PATH_LANG_BUILD} .

${sources_jarfile}: ${generated_java_sources}
	${MKDIR_P} ${JAVA_BINDING_PATH_LANG_BUILD_PACKAGE}
	${JAR} cf ${JARFLAGS} ${builddir}/${sources_jarfile} -C ${JAVA_BINDING_PATH_LANG_SRC} .

${generated_java_wrapper}: ${SWIG_SOURCES}
	${MKDIR_P} ${JAVA_BINDING_PATH_CPP_SRC}
	${MKDIR_P} ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}
	${SWIG} -Wall -java -c++ -package ${JAVA_BINDING_PACKAGE_NAME} -outdir ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE} -o $@ $<

${generated_java_sources}: ${SWIG_SOURCES}
	${MKDIR_P} ${JAVA_BINDING_PATH_CPP_SRC}
	${MKDIR_P} ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE}
	${SWIG} -Wall -java -c++ -package ${JAVA_BINDING_PACKAGE_NAME} -outdir ${JAVA_BINDING_PATH_LANG_SRC_PACKAGE} -o ${generated_java_wrapper} $<

# proxy to include jar generation on `make all`
all-local: ${sources_jarfile} ${classes_jarfile}

# cleanup
java_binaries = \
    ${builddir}/${classes_jarfile} \
    ${builddir}/${sources_jarfile}

CLEANFILES = \
    ${java_binaries} \
    ${generated_java_classes}

# installation
jardir=${datadir}/java

install-data-local:
	${MKDIR_P} "${DESTDIR}${jardir}"
	${INSTALL_DATA} ${classes_jarfile} "${DESTDIR}${jardir}"

uninstall-local:
	rm -f "${DESTDIR}${jardir}/${classes_jarfile_name}"

endif

#
# python
#
if WITH_PYTHON
PYTHON_BINDING_PATH_CPP_SRC=${srcdir}/${PYTHON_BINDING_PATH_CPP}
PYTHON_BINDING_PATH_LANG_SRC=${srcdir}/${PYTHON_BINDING_PATH_LANG}

generated_python_sources = \
    ${PYTHON_BINDING_PATH_LANG_SRC}/consensus.py

generated_python_wrapper= \
    ${PYTHON_BINDING_PATH_CPP_SRC}/consensus_wrap.cpp

# language specific
pkgpython_PYTHON = ${generated_python_sources}

# c++ wrapper library
pkgpyexec_LTLIBRARIES = bindings/python/cpp/_consensus.la

bindings_python_cpp__consensus_la_SOURCES = \
    bindings/python/cpp/consensus_wrap.cpp \
    ${SWIG_SOURCES}

bindings_python_cpp__consensus_la_CPPFLAGS = ${PYTHON_BINDING_CFLAGS} \
    -I${srcdir}/include

bindings_python_cpp__consensus_la_LDFLAGS = \
    -module

bindings_python_cpp__consensus_la_LIBADD = ${PYTHON_BINDING_LIBS} \
    ${builddir}/src/libbitcoin-consensus.la

# custom build rules
${generated_python_wrapper}: ${SWIG_SOURCES}
	${MKDIR_P} ${PYTHON_BINDING_PATH_CPP_SRC}
	${MKDIR_P} ${PYTHON_BINDING_PATH_LANG_SRC}
	${SWIG} -Wall -python -c++ -outdir ${PYTHON_BINDING_PATH_LANG_SRC} -o $@ $<

${generated_python_sources}: ${SWIG_SOURCES}
	${MKDIR_P} ${PYTHON_BINDING_PATH_CPP_SRC}
	${MKDIR_P} ${PYTHON_BINDING_PATH_LANG_SRC}
	${SWIG} -Wall -python -c++ -outdir ${PYTHON_BINDING_PATH_LANG_SRC} -o ${generated_python_wrapper} $<

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
