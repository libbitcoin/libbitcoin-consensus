#!/bin/sh
###############################################################################
#  Copyright (c) 2014-2015 libbitcoin-consensus developers (see COPYING).
#
#         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
#
###############################################################################
# Script to build language bindings for consensus c++ public interfaces.
# This script requires SWIG - "Simplified Wrapper and Interface Generator".
# SWIG is a simple tool available for most platforms at http://www.swig.org
# Add the path to swig.exe to the path of this process or your global path.

# Exit this script on the first error.
set -e

echo Generating consensus bindings...

# Do everything relative to this file location.
cd `dirname "$0"`

# Clean and make required directories.
rm -rf "bindings/target/generated-sources/src/main/cpp"
rm -rf "bindings/target/generated-sources/src/main/java/org/libbitcoin/consensus"
rm -rf "bindings/target/generated-sources/src/main/python"
rm -rf "bindings/target/generated-sources/src/main/python3"

mkdir -p "bindings/target/generated-sources/src/main/java/org/libbitcoin/consensus"
mkdir -p "bindings/target/generated-sources/src/main/cpp/java-wrap"
mkdir -p "bindings/target/generated-sources/src/main/python"
mkdir -p "bindings/target/generated-sources/src/main/cpp/python-wrap"
mkdir -p "bindings/target/generated-sources/src/main/python3"
mkdir -p "bindings/target/generated-sources/src/main/cpp/python3-wrap"

# Generate bindings.
#swig -c++ -debug-tmsearch -java -package org.libbitcoin.consensus -outdir "bindings/target/generated-sources/src/main/java/org/libbitcoin/consensus" -o "bindings/target/generated-sources/src/main/cpp/java-wrap/consensus.cpp" "bindings/src/main/swig/consensus-java.i"
swig -c++ -java -package org.libbitcoin.consensus -outdir "bindings/target/generated-sources/src/main/java/org/libbitcoin/consensus" -o "bindings/target/generated-sources/src/main/cpp/java-wrap/consensus.cpp" "bindings/src/main/swig/consensus-java.i"
swig -c++ -python -py3 -outdir "bindings/target/generated-sources/src/main/python3" -o "bindings/target/generated-sources/src/main/cpp/python3-wrap/consensus.cpp" "bindings/src/main/swig/consensus.i"
swig -c++ -python -outdir "bindings/target/generated-sources/src/main/python" -o "bindings/target/generated-sources/src/main/cpp/python-wrap/consensus.cpp" "bindings/src/main/swig/consensus.i"
