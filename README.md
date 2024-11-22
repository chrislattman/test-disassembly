# About

main.c depends on:
- libm.so
- libc.so

main.cpp depends on:
- libstdc++.so
- libm.so
- libc.so
- libgcc_s.so

main.go has no library dependencies (always statically compiled)

main.rs depends on:
- libgcc_s.so
- libm.so
- libc.so
- ld-linux-x86-64.so

To compile statically:
- C/C++: pass -static to gcc/g++
- Go: already statically compiled
- Rust: pass -C target-feature=+crt-static to rustc (or in RUSTFLAGS environment variable before cargo)

Use the `strip` command to remove symbol table information (makes the binary smaller but less debuggable)

To make Circle and its methods public:
- In C: place struct Circle and function signatures in main.h header file, and remove static keyword from function signatures
- In C++: place class Circle in main.hpp header file
- In Go: capitalize circle in type circle struct as well as method names
- In Rust: add pub keyword before struct Circle

Note: part1 and part2 of main.rs aren't exported regardless of pub keyword
