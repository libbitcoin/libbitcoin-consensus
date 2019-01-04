#!/bin/sh
###############################################################################
#  Copyright (c) 2014-2019 libbitcoin-consensus developers (see COPYING).
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
rm -rf "bindings/java/wrap"
rm -rf "bindings/java/proxy/org/libbitcoin/consensus"
rm -rf "bindings/python/wrap"
rm -rf "bindings/python/proxy"

mkdir -p "bindings/java/wrap"
mkdir -p "bindings/java/proxy/org/libbitcoin/consensus"
mkdir -p "bindings/python/wrap"
mkdir -p "bindings/python/proxy"

# Generate bindings.
swig -c++ -java -outdir "bindings/java/proxy/org/libbitcoin/consensus" -o "bindings/java/wrap/consensus.cpp" "bindings/consensus.swg"
swig -c++ -python -outdir "bindings/python/proxy" -o "bindings/python/wrap/consensus.cpp" "bindings/consensus.swg"
