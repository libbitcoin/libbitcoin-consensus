###############################################################################
#  Copyright (c) 2014-2015 libbitcoin-consensus developers (see COPYING).
#
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################

# Standard declarations.
#==============================================================================
# Requires Automake 1.14 or newer.

# Declare the required version of Autoconf.
AC_PREREQ([2.65])

# Process command-line arguments and perform initialization and verification.
AC_INIT([libbitcoin-consensus], [3.1.0], [eric@voskuil.org])

# Do compilation tests.
AC_LANG(C++)

# Specify the temporary directory for build tools.
AC_CONFIG_AUX_DIR([build-aux])

# Specify the directory of additional local Autoconf macros.
AC_CONFIG_MACRO_DIR([m4])

# Run macros for operation of generated Makefiles, enable non-recursive make.
# Unless [foreign] is specified standard GNU files will be required,
# specifically: AUTHORS, COPYING, INSTALL, NEWS, README and ChangeLog.
AM_INIT_AUTOMAKE([subdir-objects])

# Enable C and POSIX extensions that may be disabled on certain platforms.
AC_USE_SYSTEM_EXTENSIONS

# Enable the archiver.
AM_PROG_AR

# Initialize libtool.
LT_INIT

# Determine C++ compiler to use.
AC_PROG_CXX

# Enable shared libraries if available, and static if they don't conflict.
AC_PROG_LIBTOOL

# Compute the canonical host-system type variable host, including host_os.
AC_CANONICAL_HOST

# Enable silent rules option.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Check for pkg-config.
PKG_PROG_PKG_CONFIG

# Declare environment variables that affect the build.
#------------------------------------------------------------------------------
AC_ARG_VAR([CC], "C compiler to use, such as gcc or clang")
AC_ARG_VAR([CXX], "C++ compiler to use, such as g++ or clang++")
AC_ARG_VAR([PKG_CONFIG_PATH], "Additional directories for package discovery.")

# Check for baseline language coverage in the compiler for the C++11 standard.
#------------------------------------------------------------------------------
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])


# Process options.
#==============================================================================
# Implement --with-pkgconfigdir and output ${pkgconfigdir}.
#------------------------------------------------------------------------------
AC_MSG_CHECKING([--with-pkgconfigdir option])
AC_ARG_WITH([pkgconfigdir],
    AS_HELP_STRING([--with-pkgconfigdir=DIR],
        [Path to pkgconfig directory. @<:@default=${libdir}/pkgconfig@:>@]),
    [pkgconfigdir=$withval],
    [pkgconfigdir=${libdir}/pkgconfig])
AC_MSG_RESULT([$pkgconfigdir])
AC_SUBST([pkgconfigdir])

# Implement --with-tests and declare WITH_TESTS.
#------------------------------------------------------------------------------
AC_MSG_CHECKING([--with-tests option])
AC_ARG_WITH([tests],
    AS_HELP_STRING([--with-tests],
        [Compile with unit tests. @<:@default=yes@:>@]),
    [with_tests=$withval],
    [with_tests=yes])
AC_MSG_RESULT([$with_tests])
AM_CONDITIONAL([WITH_TESTS], [test x$with_tests != xno])

# Implement --with-java and declare WITH_JAVA.
#------------------------------------------------------------------------------
AC_MSG_CHECKING([--with-java option])
AC_ARG_WITH([java],
    AS_HELP_STRING([--with-java],
        [Compile the Java bindings. @<:@default=no@:>@]),
    [with_java=$withval],
    [with_java=no])
AC_MSG_RESULT([$with_java])
AM_CONDITIONAL([WITH_JAVA], [test x$with_java != xno])

# Implement --with-python and declare WITH_PYTHON.
#------------------------------------------------------------------------------
AC_MSG_CHECKING([--with-python option])
AC_ARG_WITH([python],
    AS_HELP_STRING([--with-python],
        [Compile the Python bindings. @<:@default=no@:>@]),
    [with_python=$withval],
    [with_python=no])
AC_MSG_RESULT([$with_python])
AM_CONDITIONAL([WITH_PYTHON], [test x$with_python != xno])

# Implement --enable-ndebug and define NDEBUG.
#------------------------------------------------------------------------------
AC_MSG_CHECKING([--enable-ndebug option])
AC_ARG_ENABLE([ndebug],
    AS_HELP_STRING([--enable-ndebug],
        [Compile without debug assertions. @<:@default=yes@:>@]),
    [enable_ndebug=$enableval],
    [enable_ndebug=yes])
AC_MSG_RESULT([$enable_ndebug])
AS_CASE([${enable_ndebug}], [yes], AC_DEFINE([NDEBUG]))

# Inherit --enable-shared and define BOOST_TEST_DYN_LINK.
#------------------------------------------------------------------------------
AS_CASE([${enable_shared}], [yes], AC_DEFINE([BOOST_TEST_DYN_LINK]))


# Set preprocessor defines.
#==============================================================================
# Conditionally define the preprocessor symbol HAVE_DECL_BSWAP_16.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([byteswap.h],
    [AC_CHECK_DECLS([bswap_16], [], [],
        [#if HAVE_BYTESWAP_H
         #include <byteswap.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BSWAP_32.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([byteswap.h],
    [AC_CHECK_DECLS([bswap_32], [], [],
        [#if HAVE_BYTESWAP_H
         #include <byteswap.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BSWAP_64.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([byteswap.h],
    [AC_CHECK_DECLS([bswap_64], [], [],
        [#if HAVE_BYTESWAP_H
         #include <byteswap.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_LE16TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([le16toh], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_LE32TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([le32toh], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_LE64TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([le64toh], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOLE16.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([htole16], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOLE32.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([htole32], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOLE64.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([htole64], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BE16TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([be16toh], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BE32TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([be32toh], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BE64TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([be64toh], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOBE16.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([htobe16], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOBE32.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([htobe32], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOBE64.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([endian.h],
    [AC_CHECK_DECLS([htobe64], [], [],
        [#if HAVE_ENDIAN_H
         #include <endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_LE16TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([le16toh], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_LE32TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([le32toh], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_LE64TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([le64toh], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOLE16.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([htole16], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOLE32.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([htole32], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOLE64.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([htole64], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BE16TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([be16toh], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BE32TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([be32toh], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_BE64TOH.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([be64toh], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOBE16.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([htobe16], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOBE32.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([htobe32], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])

# Conditionally define the preprocessor symbol HAVE_DECL_HTOBE64.
#------------------------------------------------------------------------------
AC_CHECK_HEADERS([sys/endian.h],
    [AC_CHECK_DECLS([htobe64], [], [],
        [#if HAVE_SYS_ENDIAN_H
         #include <sys/endian.h>
         #endif])])


# Check dependencies.
#==============================================================================
# Require Boost of at least version 1.55.0 if in gcc and output ${boost_CPPFLAGS/LDFLAGS}.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*gcc*],
    [AX_BOOST_BASE([1.55.0],
        [AC_SUBST([boost_CPPFLAGS], [${BOOST_CPPFLAGS}])
         AC_SUBST([boost_LDFLAGS], [${BOOST_LDFLAGS}])
         AC_MSG_NOTICE([boost_CPPFLAGS : ${boost_CPPFLAGS}])
         AC_MSG_NOTICE([boost_LDFLAGS : ${boost_LDFLAGS}])],
        [AC_MSG_ERROR([Boost 1.55.0 or later is required but was not found.])])])

# Require Boost of at least version 1.57.0 if in clang and output ${boost_CPPFLAGS/LDFLAGS}.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_BOOST_BASE([1.57.0],
        [AC_SUBST([boost_CPPFLAGS], [${BOOST_CPPFLAGS}])
         AC_SUBST([boost_LDFLAGS], [${BOOST_LDFLAGS}])
         AC_MSG_NOTICE([boost_CPPFLAGS : ${boost_CPPFLAGS}])
         AC_MSG_NOTICE([boost_LDFLAGS : ${boost_LDFLAGS}])],
        [AC_MSG_ERROR([Boost 1.57.0 or later is required but was not found.])])])

AS_CASE([${with_tests}], [yes],
    [AX_BOOST_UNIT_TEST_FRAMEWORK
     AC_SUBST([boost_unit_test_framework_LIBS], [${BOOST_UNIT_TEST_FRAMEWORK_LIB}])
     AC_MSG_NOTICE([boost_unit_test_framework_LIBS : ${boost_unit_test_framework_LIBS}])],
    [AC_SUBST([boost_unit_test_framework_LIBS], [])])

# Require secp256k1 of at least version 0.0.1 and output ${secp256k1_CPPFLAGS/LIBS/PKG}.
#------------------------------------------------------------------------------
PKG_CHECK_MODULES([secp256k1], [libsecp256k1 >= 0.0.1])
AC_SUBST([secp256k1_PKG], ['libsecp256k1 >= 0.0.1'])
AC_SUBST([secp256k1_CPPFLAGS], [${secp256k1_CFLAGS}])
AC_MSG_NOTICE([secp256k1_CPPFLAGS : ${secp256k1_CPPFLAGS}])
AC_MSG_NOTICE([secp256k1_LIBS : ${secp256k1_LIBS}])

# Require java if --with_java and output ${JAR/JAVAC/javadir} and ${java_CPPFLAGS}.
#------------------------------------------------------------------------------
AS_CASE([${with_java}], [yes],
    [AX_JAVA_DEVEL
     AC_SUBST([java_CPPFLAGS], [${JAVA_CPPFLAGS}])
     AC_MSG_NOTICE([java_CPPFLAGS : ${java_CPPFLAGS}])])

# Require python of at least version 2.7 if --with_python and output ${python_CPPFLAGS}.
#------------------------------------------------------------------------------
AS_CASE([${with_python}], [yes],
    [AM_PATH_PYTHON([2.7],
        [AX_PYTHON_DEVEL
         AC_SUBST([python_CPPFLAGS], [${PYTHON_CPPFLAGS}])
         AC_MSG_NOTICE([python_CPPFLAGS : ${python_CPPFLAGS}])])])


# Set flags.
#==============================================================================
# Require c++11 for all c++ products.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-std=c++11],
        [CXXFLAGS="$CXXFLAGS -std=c++11"])])

# Warn on all stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wall],
        [CFLAGS="$CFLAGS -Wall"])])

# Warn on extra stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wextra],
        [CFLAGS="$CFLAGS -Wextra"])])

# Be really annoying.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wpedantic],
        [CFLAGS="$CFLAGS -Wpedantic"],
        [AX_CHECK_COMPILE_FLAG([-pedantic],
            [CFLAGS="$CFLAGS -pedantic"])])])

# Conform to style.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-missing-braces],
        [CXXFLAGS="$CXXFLAGS -Wno-missing-braces"])])

# Conflict in stdlib under clang. Enabled in clang only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_CHECK_COMPILE_FLAG([-Wno-mismatched-tags],
        [CXXFLAGS="$CXXFLAGS -Wno-mismatched-tags"])])

# Protect stack.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_LINK_FLAG([-fstack-protector],
        [LDFLAGS="$LDFLAGS -fstack-protector"])])

# Protect stack comprehensively.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_LINK_FLAG([-fstack-protector-all],
        [LDFLAGS="$LDFLAGS -fstack-protector-all"])])

# Hide internal functions from external libs. Enabled in gcc only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*gcc*],
    [AX_CHECK_COMPILE_FLAG([-fvisibility-hidden],
        [CXXFLAGS="$CXXFLAGS -fvisibility-hidden"])])

# Hide inlines from external libs. Enabled in gcc only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*gcc*],
    [AX_CHECK_COMPILE_FLAG([-fvisibility-inlines-hidden],
        [CXXFLAGS="$CXXFLAGS -fvisibility-inlines-hidden"])])


# Process outputs into templates.
#==============================================================================
AC_CONFIG_FILES([Makefile libbitcoin-consensus.pc])
AC_OUTPUT
