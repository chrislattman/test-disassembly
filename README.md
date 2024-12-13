# About

main.c depends on:
- libm.so
- libc.so

main.cpp depends on:
- libstdc++.so
- libm.so
- libc.so
- libgcc_s.so

main.go has no library dependencies

main.rs depends on:
- libgcc_s.so
- libm.so
- libc.so

To make Circle and its methods public to other project files:
- In C: place `struct Circle` and function signatures in main.h header file, and remove `static` from function signatures
- In C++: place `class Circle` in main.hpp header file
- In Go: capitalize circle in `type circle struct` as well as method names
- In Rust: add `pub` before `struct Circle`

> For each C++ function to export, add `extern "C"` before the function signature. For Win32, add `extern "C" __declspec(dllexport)` before the function signature.

> For each C++ class method to export, remove `__attribute__((visibility("hidden")))` from the method signature (POSIX). For Win32, add `__declspec(dllexport)` to the method signature.

> For each Go function to export, add `import "C"` (one time only) and then add `//export <function-name>` right above function definition

> For each Rust function to export, add `#[no_mangle]` right above function definition, then add `pub extern "C"` before the function definition
