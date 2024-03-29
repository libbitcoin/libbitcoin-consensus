###############################################################################
#  Copyright (c) 2014-2023 libbitcoin-consensus developers (see COPYING).
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
AC_INIT([libbitcoin-consensus], [4.0.0], [eric@voskuil.org])

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
LT_PREREQ(2.4.2)

# Enable shared libraries if available, and static if they don't conflict.
LT_INIT
AC_SUBST([LIBTOOL_DEPS])

# Determine C++ compiler to use.
AC_PROG_CXX

# Enable sed for substitution.
AC_PROG_SED

# Compute the canonical host-system type variable host, including host_os.
AC_CANONICAL_HOST

# Enable silent rules option.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Check for pkg-config.
PKG_PROG_PKG_CONFIG
AS_IF([test -n "$PKG_CONFIG"], [],
    [AC_MSG_ERROR([pkg-config is required but was not found.])])

AS_CASE([${enable_static}],
    [yes], [AC_SUBST([PKG_CONFIG], ["$PKG_CONFIG --static"])],
    [])

# Declare environment variables that affect the build.
#------------------------------------------------------------------------------
AC_ARG_VAR([CC], "C compiler to use, such as gcc or clang")
AC_ARG_VAR([CXX], "C++ compiler to use, such as g++ or clang++")
AC_ARG_VAR([PKG_CONFIG_PATH], "Additional directories for package discovery.")

# Check for baseline language coverage in the compiler for the C++20 standard.
#------------------------------------------------------------------------------
AX_CXX_COMPILE_STDCXX([20], [noext], [mandatory])


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

# Implement --enable-isystem.
#------------------------------------------------------------------------------
AC_MSG_CHECKING([--enable-isystem option])
AC_ARG_ENABLE([isystem],
    AS_HELP_STRING([--enable-isystem],
        [Substitute -isystem for -I in dependencies. @<:@default=no@:>@]),
    [enable_isystem=$enableval],
    [enable_isystem=no])
AC_MSG_RESULT([$enable_isystem])


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


# Set flags.
#==============================================================================
# Require c++20 for all c++ products.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-std=c++20],
        [CXXFLAGS="$CXXFLAGS -std=c++20"])])

# Warn on all stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wall],
        [CFLAGS="$CFLAGS -Wall"])])

# Warn on all stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wall],
        [CXXFLAGS="$CXXFLAGS -Wall"])])

# Warn on extra stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wextra],
        [CFLAGS="$CFLAGS -Wextra"])])

# Warn on extra stuff.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wextra],
        [CXXFLAGS="$CXXFLAGS -Wextra"])])

# Disallow warning on style order of declarations.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-reorder],
        [CXXFLAGS="$CXXFLAGS -Wno-reorder"])])

# Suppress warning for incomplete field initialization.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-missing-field-initializers],
        [CXXFLAGS="$CXXFLAGS -Wno-missing-field-initializers"])])

# Conform to style.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-missing-braces],
        [CXXFLAGS="$CXXFLAGS -Wno-missing-braces"])])

# Ignore comments within comments or commenting of backslash extended lines.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-comment],
        [CXXFLAGS="$CXXFLAGS -Wno-comment"])])

# Suppress warning for copy of implicitly generated copy constructor.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-deprecated-copy],
        [CXXFLAGS="$CXXFLAGS -Wno-deprecated-copy"])])

# Conflict in stdlib under clang. Enabled in clang only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_CHECK_COMPILE_FLAG([-Wno-mismatched-tags],
        [CXXFLAGS="$CXXFLAGS -Wno-mismatched-tags"])])

# Address -undefined dynamic_lookup MacOS error.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_LINK_FLAG([-no_fixup_chains],
        [LDFLAGS="$LDFLAGS -no_fixup_chains"])])

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

# Suppress frequent warning in cloned files.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_CHECK_COMPILE_FLAG([-Wno-unused-parameter],
        [CXXFLAGS="$CXXFLAGS -Wno-unused-parameter"])])

# Suppress frequent warning in cloned files. Enabled in clang only.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*clang*],
    [AX_CHECK_COMPILE_FLAG([-Wno-c++17-extensions],
        [CXXFLAGS="$CXXFLAGS -Wno-c++17-extensions"])])


# Check dependencies.
#==============================================================================
# Require Boost of at least version 1.76.0 and output ${boost_CPPFLAGS/LDFLAGS}.
#------------------------------------------------------------------------------
AS_CASE([${CC}], [*],
    [AX_BOOST_BASE([1.76.0],
        [AC_SUBST([boost_CPPFLAGS], [${BOOST_CPPFLAGS}])
         AC_SUBST([boost_ISYS_CPPFLAGS], [`echo ${BOOST_CPPFLAGS} | $SED s/^-I/-isystem/g | $SED s/' -I'/' -isystem'/g`])
         AC_SUBST([boost_LDFLAGS], [${BOOST_LDFLAGS}])
         AC_MSG_NOTICE([boost_CPPFLAGS : ${boost_CPPFLAGS}])
         AC_MSG_NOTICE([boost_ISYS_CPPFLAGS : ${boost_ISYS_CPPFLAGS}])
         AC_MSG_NOTICE([boost_LDFLAGS : ${boost_LDFLAGS}])],
        [AC_MSG_ERROR([Boost 1.76.0 or later is required but was not found.])])])

AS_CASE([${enable_isystem}],[yes],
    [AC_SUBST([boost_BUILD_CPPFLAGS], [${boost_ISYS_CPPFLAGS}])],
    [AC_SUBST([boost_BUILD_CPPFLAGS], [${boost_CPPFLAGS}])])

AC_MSG_NOTICE([boost_BUILD_CPPFLAGS : ${boost_BUILD_CPPFLAGS}])

AS_CASE([${with_tests}], [yes],
    [AX_BOOST_UNIT_TEST_FRAMEWORK
     AC_SUBST([boost_unit_test_framework_LIBS], [${BOOST_UNIT_TEST_FRAMEWORK_LIB}])
     AC_MSG_NOTICE([boost_unit_test_framework_LIBS : ${boost_unit_test_framework_LIBS}])],
    [AC_SUBST([boost_unit_test_framework_LIBS], [])])

# Require secp256k1 of at least version 0.1.0.20 and output ${secp256k1_CPPFLAGS/LIBS/PKG}.
#------------------------------------------------------------------------------
PKG_CHECK_MODULES([secp256k1], [libsecp256k1 >= 0.1.0.20],
    [secp256k1_INCLUDEDIR="`$PKG_CONFIG --variable=includedir "libsecp256k1 >= 0.1.0.20" 2>/dev/null`"
     secp256k1_OTHER_CFLAGS="`$PKG_CONFIG --cflags-only-other "libsecp256k1 >= 0.1.0.20" 2>/dev/null`"],
    [AC_MSG_ERROR([libsecp256k1 >= 0.1.0.20 is required but was not found.])])
AC_SUBST([secp256k1_PKG], ['libsecp256k1 >= 0.1.0.20'])
AC_SUBST([secp256k1_CPPFLAGS], [${secp256k1_CFLAGS}])
AS_IF([test x${secp256k1_INCLUDEDIR} != "x"],
    [AC_SUBST([secp256k1_ISYS_CPPFLAGS], ["-isystem${secp256k1_INCLUDEDIR} ${secp256k1_OTHER_CFLAGS}"])],
    [AC_SUBST([secp256k1_ISYS_CPPFLAGS], [${secp256k1_OTHER_CFLAGS}])])
AC_MSG_NOTICE([secp256k1_CPPFLAGS : ${secp256k1_CPPFLAGS}])
AC_MSG_NOTICE([secp256k1_ISYS_CPPFLAGS : ${secp256k1_ISYS_CPPFLAGS}])
AC_MSG_NOTICE([secp256k1_OTHER_CFLAGS : ${secp256k1_OTHER_CFLAGS}])
AC_MSG_NOTICE([secp256k1_INCLUDEDIR : ${secp256k1_INCLUDEDIR}])
AC_MSG_NOTICE([secp256k1_LIBS : ${secp256k1_LIBS}])

AS_CASE([${enable_isystem}],[yes],
    [AC_SUBST([secp256k1_BUILD_CPPFLAGS], [${secp256k1_ISYS_CPPFLAGS}])],
    [AC_SUBST([secp256k1_BUILD_CPPFLAGS], [${secp256k1_CPPFLAGS}])])

AC_MSG_NOTICE([secp256k1_BUILD_CPPFLAGS : ${secp256k1_BUILD_CPPFLAGS}])


# Process outputs into templates.
#==============================================================================
AC_CONFIG_FILES([Makefile libbitcoin-consensus.pc])
AC_OUTPUT
