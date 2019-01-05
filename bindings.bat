@echo off
REM ###########################################################################
REM #  Copyright (c) 2014-2019 libbitcoin-consensus developers (see COPYING).
REM #
REM #         GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY
REM #
REM ###########################################################################
REM Script to build language bindings for consensus c++ public interfaces.
REM This script requires SWIG - "Simplified Wrapper and Interface Generator".
REM SWIG is a simple tool available for most platforms at http://www.swig.org
REM Add the path to swig.exe to the path of this process or your global path.

echo Generating consensus bindings...

REM Do everything relative to this file location.
cd %~dp0

REM Clean and make required directories.
rmdir /s /q "bindings\java\wrap" 2>NUL
rmdir /s /q "bindings\java\proxy\org\libbitcoin\consensus" 2>NUL
rmdir /s /q "bindings\python\wrap" 2>NUL
rmdir /s /q "bindings\python\proxy" 2>NUL

mkdir "bindings\java\wrap"
mkdir "bindings\java\proxy\org\libbitcoin\consensus"
mkdir "bindings\python\wrap"
mkdir "bindings\python\proxy"

REM Generate bindings.
swig -c++ -java -outdir "bindings\java\proxy\org\libbitcoin\consensus" -o "bindings\java\wrap\consensus.cpp" "bindings\consensus.swg"
swig -c++ -python -outdir "bindings\python\proxy" -o "bindings\python\wrap\consensus.cpp" "bindings\consensus.swg"
