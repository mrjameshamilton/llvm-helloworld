# LLVM Hello World

This repository contains two simple "Hello World" examples to help get started with LLVM:

* [helloworld.ll](helloworld.ll): a minimal "Hello World" written in textual LLVM IR.
* [gen.cpp](gen.cpp): a minimal "Hello World" generator using the LLVM C++ API.

# Installing LLVM

There is an automatic installation script available to easily install
LLVM on Ubuntu/Debian systems available [here](https://apt.llvm.org/), for 
example to install LLVM 19:

```shell
$ wget https://apt.llvm.org/llvm.sh
$ chmod +x llvm.sh
$ ./llvm.sh 19
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
specifically the [IRBuilder](https://llvm.org/doxygen/classllvm_1_1IRBuilder.html) to generate LLVM IR.

## clang++ command line

```shell
# Compile the source to an object file.
$ clang++ `llvm-config --cxxflags` -o gen.o -c gen.cpp
# Link the object file with the LLVM libraries
$ clang++ `llvm-config --ldflags` -o gen gen.o `llvm-config --libs core` 
# Execute the generator and pipe the output to the LLVM IR interpreter.
$ ./gen | lli
```

Note how the [`llvm-config` tool](https://llvm.org/docs/CommandGuide/llvm-config.html) can be used to 
generate the necessary compiler and linker flags, for compiling & linking against LLVM.

## cmake project

```shell
$ mkdir -p build
$ cmake -S . -B build -G Ninja
$ ninja -C build
# Execute the generator and pipe the output to the LLVM IR interpreter.
$ build/gen | lli
```
