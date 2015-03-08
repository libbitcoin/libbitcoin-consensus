###############################################################################
#  Copyright (c) 2014-2015 libbitcoin-consensus developers (see COPYING).
#
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################

# Standard declarations.
#==============================================================================
# Declare the required version of autoconf.
AC_PREREQ([2.65])

# Process command-line arguments and perform initialization and verification.
AC_INIT([libbitcoin-consensus], [1.0.0], [eric@voskuil.org])

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

# Enable C and Posix extensions that may be disabled on certain platforms.
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


# Process options.
#==============================================================================
# Implement --with-pkgconfigdir and output ${pkgconfigdir}.
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--with-pkgconfigdir option)
AC_ARG_WITH([pkgconfigdir],
    AS_HELP_STRING([--with-pkgconfigdir=PATH],
        [Path to pkgconfig directory. @<:@default=${libdir}/pkgconfig@:>@]),
    [pkgconfigdir=$withval],
    [pkgconfigdir=${libdir}/pkgconfig])
AC_MSG_RESULT([$pkgconfigdir])
AC_SUBST([pkgconfigdir])

# Implement --with-tests and declare WITH_TESTS.
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--with-tests option)
AC_ARG_WITH([tests],
    AS_HELP_STRING([--with-tests],
        [Compile with unit tests. @<:@default=yes@:>@]),
    [with_tests=$withval],
    [with_tests=yes])
AC_MSG_RESULT([$with_tests])
AM_CONDITIONAL([WITH_TESTS], [test x$with_tests != xno])

# Implement --with-openssl.
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--with-openssl option)
AC_ARG_WITH([openssl],
    AS_HELP_STRING([--with-openssl],
        [Require OpenSSL dependency. @<:@default=yes@:>@]),
    [with_openssl=$withval],
    [with_openssl=yes])
AC_MSG_RESULT([$with_openssl])

# Implement --with-secp256k1 and define USE_SECP256K1 and declare WITH_SECP256K1.
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--with-secp256k1 option)
AC_ARG_WITH([secp256k1],
    AS_HELP_STRING([--with-secp256k1],
        [Compile with Secp256k1 instead of OpenSSL. @<:@default=no@:>@]),
    [with_secp256k1=$withval],
    [with_secp256k1=no])
AC_MSG_RESULT([$with_secp256k1])
AS_IF([test x$with_secp256k1 != xno], AC_DEFINE([USE_SECP256K1]))
AM_CONDITIONAL([WITH_SECP256K1], [test x$with_secp256k1 != xno])

# Implement --enable-ndebug option and define NDEBUG.
#------------------------------------------------------------------------------
AC_MSG_CHECKING(--enable-ndebug option)
AC_ARG_ENABLE([ndebug],
    AS_HELP_STRING([--enable-ndebug],
        [Compile without debug assertions. @<:@default=yes@:>@]),
    [enable_ndebug=$enableval],
    [enable_ndebug=yes])
AC_MSG_RESULT([$enable_ndebug])
AS_IF([test x$enable_ndebug != xno], AC_DEFINE([NDEBUG]))

# Inherit --enable-shared option and define BOOST_TEST_DYN_LINK.
#------------------------------------------------------------------------------
AS_IF([test x$enable_shared != xno], AC_DEFINE([BOOST_TEST_DYN_LINK]))


# Check dependencies.
#==============================================================================
# Require Boost of at least version 1.49.0 if in gcc.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*gcc*],
    [AX_BOOST_BASE([1.49.0], [], [AC_MSG_ERROR(
        [Boost 1.49.0 or later is required but was not found.])])])

# Require Boost of at least version 1.54.0 if in clang.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_BOOST_BASE([1.54.0], [], [AC_MSG_ERROR(
        [Boost 1.54.0 or later is required but was not found.])])])

AS_IF([test x$with_tests = xyes], [AX_BOOST_UNIT_TEST_FRAMEWORK])

# Require secp256k1 of at least version 0.0.1 and output ${secp256k1_CFLAGS} and ${secp256k1_LIBS}.
#------------------------------------------------------------------------------
AS_IF([test x$with_secp256k1 = xyes],
    [PKG_CHECK_MODULES([secp256k1], [libsecp256k1 >= 0.0.1])])

# Require ssl of at least version 1.0.1 and output ${ssl_CFLAGS} and ${ssl_LIBS}.
#------------------------------------------------------------------------------
AS_IF([test x$with_openssl = xyes],
    [PKG_CHECK_MODULES([ssl], [libssl >= 1.0.1])])

# Require crypto of at least version 1.0.1 and output ${crypto_CFLAGS} and ${crypto_LIBS}.
#------------------------------------------------------------------------------
AS_IF([test x$with_openssl = xyes],
    [PKG_CHECK_MODULES([crypto], [libcrypto >= 1.0.1])])


# Set flags.
#==============================================================================
# Warn on all stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wall],
        [CXXFLAGS="$CXXFLAGS -Wall"])])

# Warn on extra stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wextra],
        [CXXFLAGS="$CXXFLAGS -Wextra"])])

# Be really annoying.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wpedantic],
        [CXXFLAGS="$CXXFLAGS -Wpedantic"],
        [AX_CHECK_COMPILE_FLAG([-pedantic],
            [CXXFLAGS="$CXXFLAGS -pedantic"])])])

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

# Clean up boost 1.54 headers. Enabled in clang only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_CHECK_COMPILE_FLAG([-Wno-deprecated-register],
        [CXXFLAGS="$CXXFLAGS -Wno-deprecated-register"])])

# Clean up boost 1.49 headers. Enabled in gcc only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*gcc*],
    [AX_CHECK_COMPILE_FLAG([-Wno-unused-local-typedefs],
        [CXXFLAGS="$CXXFLAGS -Wno-unused-local-typedefs"])])

# Clean up consensus warnings. Enabled in gcc only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*gcc*],
    [AX_CHECK_COMPILE_FLAG([-Wno-long-long],
        [CXXFLAGS="$CXXFLAGS -Wno-long-long"])])

# Clean up consensus warnings Enabled in clang only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_CHECK_COMPILE_FLAG([-Wno-c++11-long-long],
        [CXXFLAGS="$CXXFLAGS -Wno-c++11-long-long"])])

# Protect stack.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-fstack-protector],
        [AX_CHECK_LINK_FLAG([-fstack-protector],
            [CXXFLAGS="$CXXFLAGS -fstack-protector"])])])

# Protect stack comprehensively.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-fstack-protector-all],
        [AX_CHECK_LINK_FLAG([-fstack-protector-all],
            [CXXFLAGS="$CXXFLAGS -fstack-protector-all"])])])

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

AC_MSG_CHECKING(--with-bindings option)
AC_ARG_WITH([bindings],
    AS_HELP_STRING([--with-bindings],
        [Compile with language bindings. @<:@default=yes@:>@]),
    [with_bindings=$withval],
    [with_bindings=yes])
AC_MSG_RESULT([$with_bindings])
AS_IF([test x$with_bindings != xno],
    [
        AX_PKG_SWIG(2.0.0)
        SWIG_ENABLE_CXX

        AC_MSG_CHECKING(--with-python option)
        AC_ARG_WITH([python],
            AS_HELP_STRING([--with-python],
                [Compile python language bindings. @<:@default=yes@:>@]),
            [with_python=$withval],
            [with_python=yes])
        AC_MSG_RESULT([$with_python])
        AS_IF([test x$with_python != xno], 
            [
                AM_PATH_PYTHON(2.7)
                SWIG_PYTHON
            ])
        AM_CONDITIONAL([WITH_PYTHON], [test x$with_python != xno])

        AC_MSG_CHECKING(--with-java option)
        AC_ARG_WITH([java],
            AS_HELP_STRING([--with-java],
                [Compile java language bindings. @<:@default=yes@:>@]),
            [with_java=$withval],
            [with_java=yes])
        AC_MSG_RESULT([$with_java])
        AS_IF([test x$with_java != xno], 
            [
                AX_SWIG_JAVA([org.bitcoin.libconsensus])
            ])
        AM_CONDITIONAL([WITH_JAVA], [test x$with_java != xno])
    ])
AM_CONDITIONAL([WITH_BINDINGS], [test x$with_bindings != xno])

# Process outputs into templates.
#==============================================================================
AC_CONFIG_FILES([Makefile libbitcoin-consensus.pc ])
AC_OUTPUT
