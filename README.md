# GONE - General info
- Version: 0.0.0
- Implementation Language: C23
- Largest Influences: Lua, GDScript, and C

File extension: .gone (Currently Unimplimented.)

## 1. Overview
GONE is 
a lightweight programming language designed for preformance and memory efficency.

GONE is developed and designed around C, with some minor assembly when C refuses to support what I want. Its first full release is intended to be able to do both running source code directly and compiling programs into standalone machine-code executables.

## 2. Language Design
GONE uses ideas ripped from Lua, GDScript, and C.

It uses braces to define code blocks, semicolons after statements, and indentation for visual clarity.
Variables are declared using var, with inferred and explicitly specified types. GONE supports functions, objects, and Lua-style tables.

Files provide object-oriented functionality, while tables provide flexible containers for storing and organizing values. Variables and functions are public by default where applicable, with private declarations available when access is intended.

## 3. MEMORY MANAGEMENT

Memory management and efficiency is a core part of GONE.
Ordinary values use automatically managed memory chunks that can grow when needed. And shrink when not. GONE also allows you too request fixed-capacity chunks when more direct control is necessary.

The runtime is intended to reclaim unused memory constantly and optimize allocations in the background when doing so is safe and beneficial. Memory management must avoid overhead and protect active program state, and active variable values.

## 4. EXECUTION AND COMPILATION

GONE uses a custom virtual machine and runtime, both implemented in C and assembly.

Programs can be executed directly from source code through the runtime, and the compiler can produce standalone executables that are usable anywhere that is supported.

The compiler is a separate executable and is built using GCC. The implementation avoids unnecessary dependencies and uses a handwritten lexer and parser.

## 5. RUNTIME FEATURES

GONE is intended to have:

- Functions.
- Dynamic variables and Lua-style tables.
- Explicit type declarations and type inference.
- Automatic and fixed-capacity memory allocation.
- Error handling through try/catch.
- Source inclusion and separate modules.
- Concurrent execution.
- Native C interoperability through a foreign function interface (FFI).
- A simple standard library without unnecessary features.

## 6. DESIGN PRINCIPLES

GONE prioritizes low memory usage, performance, simple syntax, and flexibility.

Its runtime should use efficient internal representations without forcing programmers to manually manage ordinary memory allocations.

Features will remain practical and minimal. Scorpi0n should provide the functionality needed to build real programs without introducing unnecessary complexity or dependencies.
