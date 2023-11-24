# Bearbytes C++ utils

This repository contains various utilities written using non-std C++23.
Furthermore, this repository stores examples of tooling configurations which
may serve as look-up resources when working on new projects.

The reason for existence of this repository is twofold:
- gather utilities which are useful in embedded programming,
- learn details of some useful std objects.

## Build, test, install

```console
$ cmake -S . -B build
$ cmake --build build
$ ctest --test-dir build
$ cmake --install build --prefix <some-path>
```
