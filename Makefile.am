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
JAVA_BINDING_PATH=bindings/java

JAVA_BINDING_BUILD_PATH=${JAVA_BINDING_PATH}/build
JAVA_PACKAGE_BUILD_PATH=${JAVA_BINDING_BUILD_PATH}/${JAVA_PACKAGE_PATH}

JAVA_BINDING_SRC_PATH=${JAVA_BINDING_PATH}/src
JAVA_PACKAGE_SRC_PATH=${JAVA_BINDING_SRC_PATH}/${JAVA_PACKAGE_PATH}

generated_java_sources = \
    ${JAVA_PACKAGE_SRC_PATH}/consensusConstants.java \
    ${JAVA_PACKAGE_SRC_PATH}/consensus.java \
    ${JAVA_PACKAGE_SRC_PATH}/consensusJNI.java \
    ${JAVA_PACKAGE_SRC_PATH}/SWIGTYPE_p_uint32_t.java \
    ${JAVA_PACKAGE_SRC_PATH}/SWIGTYPE_p_uint8_t.java \
    ${JAVA_PACKAGE_SRC_PATH}/verify_flags.java \
    ${JAVA_PACKAGE_SRC_PATH}/verify_result.java

generated_java_classes = \
    ${JAVA_PACKAGE_BUILD_PATH}/consensusConstants.class \
    ${JAVA_PACKAGE_BUILD_PATH}/consensus.class \
    ${JAVA_PACKAGE_BUILD_PATH}/consensusJNI.class \
    ${JAVA_PACKAGE_BUILD_PATH}/SWIGTYPE_p_uint32_t.class \
    ${JAVA_PACKAGE_BUILD_PATH}/SWIGTYPE_p_uint8_t.class \
    ${JAVA_PACKAGE_BUILD_PATH}/verify_flags.class \
    ${JAVA_PACKAGE_BUILD_PATH}/verify_result.class

generated_java_wrapper = \
    bindings/java/consensus_wrap.cpp

BUILT_SOURCES += \
    ${generated_java_wrapper} \
    ${generated_java_sources}

# language specific
classes_jarfile_name=libbitcoin-consensus.jar
classes_jarfile = ${JAVA_BINDING_PATH}/${classes_jarfile_name}
sources_jarfile_name=libbitcoin-consensus-sources.jar
sources_jarfile = ${JAVA_BINDING_PATH}/${sources_jarfile_name}

# c++ wrapper library
lib_LTLIBRARIES += bindings/java/libbitcoin-consensus_jni.la

bindings_java_libbitcoin_consensus_jni_la_SOURCES = \
    bindings/java/consensus_wrap.cpp \
    ${SWIG_SOURCES}

bindings_java_libbitcoin_consensus_jni_la_CPPFLAGS = \
    ${JNI_CFLAGS} \
    -I${srcdir}/include

bindings_java_libbitcoin_consensus_jni_la_LIBADD = \
    ${builddir}/src/libbitcoin-consensus.la

# custom build rules
${classes_jarfile}: ${generated_java_sources}
	${MKDIR_P} ${JAVA_PACKAGE_BUILD_PATH}
	${JAVAC} -cp ${JAVA_PACKAGE_BUILD_PATH} -d ${JAVA_BINDING_BUILD_PATH} ${generated_java_sources}
	${JAR} cf ${JARFLAGS} ${builddir}/${classes_jarfile} -C ${JAVA_BINDING_BUILD_PATH} .

${sources_jarfile}: ${generated_java_sources}
	${JAR} cf ${JARFLAGS} ${builddir}/${sources_jarfile} -C ${JAVA_BINDING_PATH} src

${generated_java_wrapper}: ${SWIG_SOURCES}
	${MKDIR_P} ${JAVA_PACKAGE_SRC_PATH}
	${SWIG} -Wall -java -c++ -package ${JAVA_PACKAGE_NAME} -outdir ${JAVA_PACKAGE_SRC_PATH} -o $@ $<

${generated_java_sources}: ${SWIG_SOURCES}
	${MKDIR_P} ${JAVA_PACKAGE_SRC_PATH}
	${SWIG} -Wall -java -c++ -package ${JAVA_PACKAGE_NAME} -outdir ${JAVA_PACKAGE_SRC_PATH} -o ${generated_java_wrapper} $<

# proxy to include jar generation on `make all`
all-local: ${sources_jarfile} ${classes_jarfile}

# cleanup
java_binaries = \
    ${builddir}/${classes_jarfile} \
    ${builddir}/${sources_jarfile}

CLEANFILES = \
    ${java_binaries} \
    ${generated_java_classes} \
    ${generated_java_sources} \
    ${generated_java_wrapper}

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
generated_python_sources= \
    bindings/python/consensus_wrap.cpp \
    bindings/python/consensus.py

BUILT_SOURCES += ${generated_python_sources}

# language specific
pkgpython_PYTHON = bindings/python/consensus.py

# c++ wrapper library
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

# custom build rules
bindings/python/consensus_wrap.cpp bindings/python/consensus.py : ${SWIG_SOURCES}
	${SWIG} -Wall ${AX_SWIG_PYTHON_OPT} -c++ -outdir bindings/python -o $@ $<

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
