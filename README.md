[![Build Status](https://travis-ci.org/libbitcoin/libbitcoin-consensus.svg?branch=master)](https://travis-ci.org/libbitcoin/libbitcoin-consensus)

# Libbitcoin Consensus

*Bitcoin consensus library*

## Experimental

This library is experimental and is no libbitcoin library currently depends on it.

## Installation

First install **libssl-dev**, then:

```sh
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
$ sudo ldconfig
```

libbitcoin-consensus is now installed in `/usr/local/`.

# About

This library includes the following 34 files considered to be bitcoin consensus-critical. These files are identical to those used in version 0.10.0 of the Satoshi client.

```
src/amount.h
src/eccryptoverify.cpp
src/eccryptoverify.h
src/ecwrapper.cpp
src/ecwrapper.h
src/hash.cpp
src/hash.h
src/pubkey.cpp
src/pubkey.h
src/serialize.h
src/tinyformat.h
src/uint256.cpp
src/uint256.h
src/utilstrencodings.cpp
src/utilstrencodings.h
src/version.h
src/crypto/common.h
src/crypto/hmac_sha512.cpp
src/crypto/hmac_sha512.h
src/crypto/ripemd160.cpp
src/crypto/ripemd160.h
src/crypto/sha1.cpp
src/crypto/sha1.h
src/crypto/sha256.cpp
src/crypto/sha256.h
src/crypto/sha512.cpp
src/crypto/sha512.h
src/primitives/transaction.cpp
src/primitives/transaction.h
src/script/interpreter.cpp
src/script/interpreter.h
src/script/script.cpp
src/script/script.h
src/script/script_error.h
```
