[![Build Status](https://travis-ci.org/libbitcoin/libbitcoin-consensus.svg?branch=master)](https://travis-ci.org/libbitcoin/libbitcoin-consensus)

# Libbitcoin Consensus

*Bitcoin consensus library*

## Experimental

This library is experimental and is no libbitcoin library currently depends on it.

## Installation

Note that you need g++ 4.8 or higher. For this reason Ubuntu 12.04 and older are not supported. Make sure you have installed [libbitcoin/secp256k1](https://github.com/libbitcoin/secp256k1) beforehand according to its build instructions.

```sh
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
$ sudo ldconfig
```

libbitcoin-consensus is now installed in `/usr/local/`.
