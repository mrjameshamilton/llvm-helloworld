# LLVM Hello World

This repository contains two simple "Hello World" examples to help get started with LLVM:

* [helloworld.ll](helloworld.ll): a minimal "Hello World" written in textual LLVM IR.
* [gen.cpp](gen.cpp): a minimal "Hello World" generator using the LLVM C++ API.

# Installing LLVM

There is an automatic installation script available to easily install
LLVM on Ubuntu/Debian systems available [here](https://apt.llvm.org/), for 
example to install LLVM 18:

```shell
$ wget https://apt.llvm.org/llvm.sh
$ chmod +x llvm.sh
$ ./llvm.sh 18
```

# Executing `helloworld.ll`

The easiest way to execute an LLVM IR script is using `lli`, the LLVM interpreter.

```shell
$ lli helloworld.ll
```

A script can also be compiled into an executable using `clang`:

```shell
$ clang helloworld.ll -o helloworld
$ ./helloworld
```

# Building the generator

The small C++ example demonstrates the basic use of the LLVM C++ API,
specially the IRBuilder to generate LLVM IR.

```shell
$ mkdir -p build
$ cmake -S . -B build -G Ninja
$ ninja -C build
$ build/gen | lli
```
