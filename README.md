# Bearbytes C++ utils

This repository contains various utilities written using non-std C++23.
Furthermore, this repository stores examples of tooling configurations which
may serve as look-up resources when working on new projects.

The reason for existence of this repository is twofold:
- gather utilities which are useful in embedded programming,
- learn details of some useful std objects.

## Build, test, install

```console
$ cmake -S . -B build -G Ninja
$ cmake --build build
$ ctest --test-dir build
$ cmake --install build --prefix <some-path>
```

It is advised to add the following line to your `~/.bashrc` (or equivalent):

```console
export CMAKE_EXPORT_COMPILE_COMMANDS=1
```

This will enforce `CMake` to produce `compile_commands.json` while configuring
project. Otherwise the following option can be added while invoking cmake
`-D CMAKE_EXPORT_COMPILE_COMMANDS=ON`.

In order do explicitly define which compiler to use, one can add the following
lines to `~/.bashrc`:

```console
export CC=/usr/local/bin/clang
export CPP=/usr/local/bin/clang-cpp
export CXX=/usr/local/bin/clang++
```

## Style, clang-format and clang-tidy

The code style is very simple: all identifiers except for template parameters
use `snake_case`. Template parameters (both type and non-type) use `PascalCase`.
Other nuances are not detailed here. Document formatting is done automatically
with `clang-format`. If working with `VS Code` it is highly advised to:
- enable: `Format On Save`
- enable: `Trim Final Newlines`
- enable: `Trim Trailing Whitespace`
- enable: `Insert Final Newline`

Furthermore, if working with `clangd` it is advised to modernize code according
to suggested changes.
