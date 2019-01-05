###############################################################################
#  Copyright (c) 2014-2019 libbitcoin-consensus developers (see COPYING).
#
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################

# libbitcoin-consensus project configuration.
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(libbitcoin-consensus LANGUAGES C CXX)

enable_testing()

list( APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules" )
include(CheckIncludeFiles)
include(CheckSymbolExists)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (MSVC)
  set( CANONICAL_LIB_NAME libbitcoin-consensus )
else ()
  set( CANONICAL_LIB_NAME bitcoin-consensus )
  find_package( PkgConfig REQUIRED )

  set( prefix "${CMAKE_PREFIX_PATH}" )
  set( exec_prefix "\${prefix}" )
  set( libdir "\${exec_prefix}/lib" )
  set( includedir "\${exec_prefix}/include" )

  set( PACKAGE_VERSION "4.0.0" )
  set( VERSION "${PACKAGE_VERSION}" )
endif ()

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# Add compiler options
#------------------------------------------------------------------------------
# Warn on all stuff.
add_compile_options( "-Wall" )

# Warn on extra stuff.
add_compile_options( "-Wextra" )

# Be really annoying.
add_compile_options( "-Wpedantic" )

# Disallow warning on style order of declarations.
add_compile_options( "-Wno-reorder" )

# Suppress warning for incomplete field initialization.
add_compile_options( "-Wno-missing-field-initializers" )

# Conform to style.
add_compile_options( "-Wno-missing-braces" )

# Ignore comments within comments or commenting of backslash extended lines.
add_compile_options( "-Wno-comment" )

# Conflict in stdlib under clang.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options( "-Wno-mismatched-tags" )
endif()

# Implement -Dpkgconfigdir and output ${pkgconfigdir}.
#------------------------------------------------------------------------------
set( pkgconfigdir "${libdir}/pkgconfig" CACHE PATH "Path to pkgconfig directory." )

# Implement -Dwith-tests and declare with-tests.
#------------------------------------------------------------------------------
set( with-tests "yes" CACHE BOOL "Compile with unit tests." )

# Implement -Denable-ndebug and define NDEBUG.
#------------------------------------------------------------------------------
set( enable-ndebug "yes" CACHE BOOL "Compile without debug assertions." )

if (enable-ndebug)
    add_definitions( -DNDEBUG )
endif()

# Inherit -Denable-shared and define BOOST_TEST_DYN_LINK.
#------------------------------------------------------------------------------
if (BUILD_SHARED_LIBS)
    add_definitions( -DBOOST_TEST_DYN_LINK )
endif()

# Initialize HAVE_BYTESWAP_H variable checking for byteswap.h
#------------------------------------------------------------------------------
check_include_files( "byteswap.h" HAVE_BYTESWAP_H )
if (!HAVE_BYTESWAP_H)
    set( HAVE_BYTESWAP_H 0 )
endif()

add_definitions( -DHAVE_BYTESWAP_H=${HAVE_BYTESWAP_H} )

# Initialize HAVE_ENDIAN_H variable checking for endian.h
#------------------------------------------------------------------------------
check_include_files( "endian.h" HAVE_ENDIAN_H )
if (!HAVE_ENDIAN_H)
    set( HAVE_ENDIAN_H 0 )
endif()

add_definitions( -DHAVE_ENDIAN_H=${HAVE_ENDIAN_H} )

# Initialize HAVE_SYS_ENDIAN_H variable checking for sys/endian.h
#------------------------------------------------------------------------------
check_include_files( "sys/endian.h" HAVE_SYS_ENDIAN_H )
if (!HAVE_SYS_ENDIAN_H)
    set( HAVE_SYS_ENDIAN_H 0 )
endif()

add_definitions( -DHAVE_SYS_ENDIAN_H=${HAVE_SYS_ENDIAN_H} )

# On HAVE_BYTESWAP_H, test for bswap_16
#------------------------------------------------------------------------------
if (HAVE_BYTESWAP_H)
    check_symbol_exists( "bswap_16" "byteswap.h" HAVE_DECL_BSWAP_16 )
    add_definitions( -DHAVE_DECL_BSWAP_16=${HAVE_DECL_BSWAP_16} )
endif()

# On HAVE_BYTESWAP_H, test for bswap_32
#------------------------------------------------------------------------------
if (HAVE_BYTESWAP_H)
    check_symbol_exists( "bswap_32" "byteswap.h" HAVE_DECL_BSWAP_32 )
    add_definitions( -DHAVE_DECL_BSWAP_32=${HAVE_DECL_BSWAP_32} )
endif()

# On HAVE_BYTESWAP_H, test for bswap_64
#------------------------------------------------------------------------------
if (HAVE_BYTESWAP_H)
    check_symbol_exists( "bswap_64" "byteswap.h" HAVE_DECL_BSWAP_64 )
    add_definitions( -DHAVE_DECL_BSWAP_64=${HAVE_DECL_BSWAP_64} )
endif()

# On HAVE_ENDIAN_H, test for le16toh
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "le16toh" "endian.h" HAVE_DECL_LE16TOH )
    add_definitions( -DHAVE_DECL_LE16TOH=${HAVE_DECL_LE16TOH} )
endif()

# On HAVE_ENDIAN_H, test for le32toh
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "le32toh" "endian.h" HAVE_DECL_LE32TOH )
    add_definitions( -DHAVE_DECL_LE32TOH=${HAVE_DECL_LE32TOH} )
endif()

# On HAVE_ENDIAN_H, test for le64toh
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "le64toh" "endian.h" HAVE_DECL_LE64TOH )
    add_definitions( -DHAVE_DECL_LE64TOH=${HAVE_DECL_LE64TOH} )
endif()

# On HAVE_ENDIAN_H, test for htole16
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "htole16" "endian.h" HAVE_DECL_HTOLE16 )
    add_definitions( -DHAVE_DECL_HTOLE16=${HAVE_DECL_HTOLE16} )
endif()

# On HAVE_ENDIAN_H, test for htole32
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "htole32" "endian.h" HAVE_DECL_HTOLE32 )
    add_definitions( -DHAVE_DECL_HTOLE32=${HAVE_DECL_HTOLE32} )
endif()

# On HAVE_ENDIAN_H, test for htole64
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "htole64" "endian.h" HAVE_DECL_HTOLE64 )
    add_definitions( -DHAVE_DECL_HTOLE64=${HAVE_DECL_HTOLE64} )
endif()

# On HAVE_ENDIAN_H, test for be16toh
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "be16toh" "endian.h" HAVE_DECL_BE16TOH )
    add_definitions( -DHAVE_DECL_BE16TOH=${HAVE_DECL_BE16TOH} )
endif()

# On HAVE_ENDIAN_H, test for be32toh
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "be32toh" "endian.h" HAVE_DECL_BE32TOH )
    add_definitions( -DHAVE_DECL_BE32TOH=${HAVE_DECL_BE32TOH} )
endif()

# On HAVE_ENDIAN_H, test for be64toh
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "be64toh" "endian.h" HAVE_DECL_BE64TOH )
    add_definitions( -DHAVE_DECL_BE64TOH=${HAVE_DECL_BE64TOH} )
endif()

# On HAVE_ENDIAN_H, test for htobe16
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "htobe16" "endian.h" HAVE_DECL_HTOBE16 )
    add_definitions( -DHAVE_DECL_HTOBE16=${HAVE_DECL_HTOBE16} )
endif()

# On HAVE_ENDIAN_H, test for htobe32
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "htobe32" "endian.h" HAVE_DECL_HTOBE32 )
    add_definitions( -DHAVE_DECL_HTOBE32=${HAVE_DECL_HTOBE32} )
endif()

# On HAVE_ENDIAN_H, test for htobe64
#------------------------------------------------------------------------------
if (HAVE_ENDIAN_H)
    check_symbol_exists( "htobe64" "endian.h" HAVE_DECL_HTOBE64 )
    add_definitions( -DHAVE_DECL_HTOBE64=${HAVE_DECL_HTOBE64} )
endif()

# On HAVE_SYS_ENDIAN_H, test for le16toh
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "le16toh" "sys/endian.h" HAVE_DECL_LE16TOH )
    add_definitions( -DHAVE_DECL_LE16TOH=${HAVE_DECL_LE16TOH} )
endif()

# On HAVE_SYS_ENDIAN_H, test for le32toh
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "le32toh" "sys/endian.h" HAVE_DECL_LE32TOH )
    add_definitions( -DHAVE_DECL_LE32TOH=${HAVE_DECL_LE32TOH} )
endif()

# On HAVE_SYS_ENDIAN_H, test for le64toh
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "le64toh" "sys/endian.h" HAVE_DECL_LE64TOH )
    add_definitions( -DHAVE_DECL_LE64TOH=${HAVE_DECL_LE64TOH} )
endif()

# On HAVE_SYS_ENDIAN_H, test for htole16
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "htole16" "sys/endian.h" HAVE_DECL_HTOLE16 )
    add_definitions( -DHAVE_DECL_HTOLE16=${HAVE_DECL_HTOLE16} )
endif()

# On HAVE_SYS_ENDIAN_H, test for htole32
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "htole32" "sys/endian.h" HAVE_DECL_HTOLE32 )
    add_definitions( -DHAVE_DECL_HTOLE32=${HAVE_DECL_HTOLE32} )
endif()

# On HAVE_SYS_ENDIAN_H, test for htole64
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "htole64" "sys/endian.h" HAVE_DECL_HTOLE64 )
    add_definitions( -DHAVE_DECL_HTOLE64=${HAVE_DECL_HTOLE64} )
endif()

# On HAVE_SYS_ENDIAN_H, test for be16toh
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "be16toh" "sys/endian.h" HAVE_DECL_BE16TOH )
    add_definitions( -DHAVE_DECL_BE16TOH=${HAVE_DECL_BE16TOH} )
endif()

# On HAVE_SYS_ENDIAN_H, test for be32toh
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "be32toh" "sys/endian.h" HAVE_DECL_BE32TOH )
    add_definitions( -DHAVE_DECL_BE32TOH=${HAVE_DECL_BE32TOH} )
endif()

# On HAVE_SYS_ENDIAN_H, test for be64toh
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "be64toh" "sys/endian.h" HAVE_DECL_BE64TOH )
    add_definitions( -DHAVE_DECL_BE64TOH=${HAVE_DECL_BE64TOH} )
endif()

# On HAVE_SYS_ENDIAN_H, test for htobe16
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "htobe16" "sys/endian.h" HAVE_DECL_HTOBE16 )
    add_definitions( -DHAVE_DECL_HTOBE16=${HAVE_DECL_HTOBE16} )
endif()

# On HAVE_SYS_ENDIAN_H, test for htobe32
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "htobe32" "sys/endian.h" HAVE_DECL_HTOBE32 )
    add_definitions( -DHAVE_DECL_HTOBE32=${HAVE_DECL_HTOBE32} )
endif()

# On HAVE_SYS_ENDIAN_H, test for htobe64
#------------------------------------------------------------------------------
if (HAVE_SYS_ENDIAN_H)
    check_symbol_exists( "htobe64" "sys/endian.h" HAVE_DECL_HTOBE64 )
    add_definitions( -DHAVE_DECL_HTOBE64=${HAVE_DECL_HTOBE64} )
endif()

# Find boost
#------------------------------------------------------------------------------
find_package( Boost 1.62.0 REQUIRED COMPONENTS
    unit_test_framework )

set( boost_unit_test_framework_LIBS "-lboost_unit_test_framework" )

if (enable-ndebug)
    set( Boost_LIBRARY_DIR "${Boost_LIBRARY_DIR_DEBUG}" )
else ()
    set( Boost_LIBRARY_DIR "${Boost_LIBRARY_DIR_RELEASE}" )
endif()

set( boost_CPPFLAGS "-I${Boost_INCLUDE_DIR}" )
set( boost_LDFLAGS "-L${Boost_LIBRARY_DIR}" )

# Find secp256k1
#------------------------------------------------------------------------------
find_package( Secp256K1 0.0.1 REQUIRED )

# Define project common includes directories
#------------------------------------------------------------------------------
if (BUILD_SHARED_LIBS)
    include_directories( SYSTEM
        ${secp256k1_INCLUDE_DIRS} )
else()
    include_directories( SYSTEM
        ${secp256k1_STATIC_INCLUDE_DIRS} )
endif()

# Define project common library directories
#------------------------------------------------------------------------------
if (BUILD_SHARED_LIBS)
    link_directories( 
        ${secp256k1_LIBRARY_DIRS} )
else()
    link_directories( 
        ${secp256k1_STATIC_LIBRARY_DIRS} )
endif()

# Define project common libraries/linker flags.
#------------------------------------------------------------------------------
if (BUILD_SHARED_LIBS)
    link_libraries( 
        "-fstack-protector"
        "-fstack-protector-all"
        ${secp256k1_LIBRARIES} )
else()
    link_libraries( 
        "-fstack-protector"
        "-fstack-protector-all"
        ${secp256k1_STATIC_LIBRARIES} )
endif()

# Define ${CANONICAL_LIB_NAME} project.
#------------------------------------------------------------------------------
add_library( ${CANONICAL_LIB_NAME}
    "../../src/clone/amount.h"
    "../../src/clone/hash.cpp"
    "../../src/clone/hash.h"
    "../../src/clone/prevector.h"
    "../../src/clone/pubkey.cpp"
    "../../src/clone/pubkey.h"
    "../../src/clone/serialize.h"
    "../../src/clone/tinyformat.h"
    "../../src/clone/uint256.cpp"
    "../../src/clone/uint256.h"
    "../../src/clone/utilstrencodings.cpp"
    "../../src/clone/utilstrencodings.h"
    "../../src/clone/version.h"
    "../../src/clone/compat/byteswap.h"
    "../../src/clone/compat/endian.h"
    "../../src/clone/crypto/common.h"
    "../../src/clone/crypto/hmac_sha512.cpp"
    "../../src/clone/crypto/hmac_sha512.h"
    "../../src/clone/crypto/ripemd160.cpp"
    "../../src/clone/crypto/ripemd160.h"
    "../../src/clone/crypto/sha1.cpp"
    "../../src/clone/crypto/sha1.h"
    "../../src/clone/crypto/sha256.cpp"
    "../../src/clone/crypto/sha256.h"
    "../../src/clone/crypto/sha512.cpp"
    "../../src/clone/crypto/sha512.h"
    "../../src/clone/primitives/transaction.cpp"
    "../../src/clone/primitives/transaction.h"
    "../../src/clone/script/interpreter.cpp"
    "../../src/clone/script/interpreter.h"
    "../../src/clone/script/script.cpp"
    "../../src/clone/script/script.h"
    "../../src/clone/script/script_error.h"
    "../../src/consensus/consensus.cpp"
    "../../src/consensus/consensus.hpp" )

# ${CANONICAL_LIB_NAME} project specific include directories.
#------------------------------------------------------------------------------
if (BUILD_SHARED_LIBS)
    target_include_directories( ${CANONICAL_LIB_NAME} PRIVATE
        "../../include"
        "../../src"
        "../../src/clone"
        ${secp256k1_INCLUDE_DIRS} )
else()
    target_include_directories( ${CANONICAL_LIB_NAME} PRIVATE
        "../../include"
        "../../src"
        "../../src/clone"
        ${secp256k1_STATIC_INCLUDE_DIRS} )
endif()

target_include_directories( ${CANONICAL_LIB_NAME} PUBLIC
"../../include" )

# ${CANONICAL_LIB_NAME} project specific libraries/linker flags.
#------------------------------------------------------------------------------
if (BUILD_SHARED_LIBS)
    target_link_libraries( ${CANONICAL_LIB_NAME}
        ${secp256k1_LIBRARIES} )
else()
    target_link_libraries( ${CANONICAL_LIB_NAME}
        ${secp256k1_STATIC_LIBRARIES} )
endif()

# Define libbitcoin-consensus-test project.
#------------------------------------------------------------------------------
if (with-tests)
    add_executable( libbitcoin-consensus-test
        "../../test/consensus__script_error_to_verify_result.cpp"
        "../../test/consensus__script_verify.cpp"
        "../../test/consensus__verify_flags_to_script_flags.cpp"
        "../../test/main.cpp"
        "../../test/script.hpp" )

    add_test( NAME libbitcoin-consensus-test COMMAND libbitcoin-consensus-test
            --run_test=*
            --show_progress=no
            --detect_memory_leak=0
            --report_level=no
            --build_info=yes )

#     libbitcoin-consensus-test project specific include directories.
#------------------------------------------------------------------------------
    target_include_directories( libbitcoin-consensus-test PRIVATE
        "../../include"
        "../../src"
        "../../src/clone"
        ${Boost_INCLUDE_DIR} )

#     libbitcoin-consensus-test project specific libraries/linker flags.
#------------------------------------------------------------------------------
    target_link_libraries( libbitcoin-consensus-test
        ${CANONICAL_LIB_NAME}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )

endif()

# Manage pkgconfig installation.
#------------------------------------------------------------------------------
configure_file(
  "../../libbitcoin-consensus.pc.in"
  "libbitcoin-consensus.pc" @ONLY )

install( FILES
    "${CMAKE_CURRENT_BINARY_DIR}/libbitcoin-consensus.pc"
    DESTINATION "${pkgconfigdir}" )

# Manage installation of docs.
#------------------------------------------------------------------------------
install( FILES
    "../../AUTHORS"
    "../../COPYING"
    "../../ChangeLog"
    "../../INSTALL"
    "../../NEWS"
    "../../README"
    DESTINATION share/doc/libbitcoin-consensus )

# Manage ${CANONICAL_LIB_NAME} installation.
#------------------------------------------------------------------------------
install( TARGETS ${CANONICAL_LIB_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include )

# Manage include installation.
#------------------------------------------------------------------------------
install( DIRECTORY "../../include/bitcoin"
    DESTINATION include )

