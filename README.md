# Bearbytes C++ utilities

This repository contains various utilities written in C++23 but without
standard library. Utilities presented here may be useful for bare metal
software development, where size constaints exclude use of standard library.
All utilities constitute a header-only library.

The main reason for existence of this repository was to learn various C++
concepts by implementing them by hand. Secondly, it was supposed to store
configuration files for various tooling used in C++ development (e.g. `CMake`,
`clang-format`, `clang-tidy`, `clangd`).

## Build, test, install

Utilities are all written in header files but there are unit tests and examples
which needs compilation. They are built without exceptions and RTTI. Commands:

```console
$ cmake -S . -B build -D CMAKE_BUILD_TYPE=<build-mode> -G Ninja
$ cmake --build build
$ ctest --test-dir build
$ cmake --install build --prefix <some-path>
```

where `<build-mode>` is e.g. `Release` or `Debug` and `<some-path>` can be a
relative path e.g. `install`. If you don't want to build unit tests and
examples you can install the artifact (header files) immediately after CMake
configuration step.

The side effect of CMake configuration step is a `compile_commands.json` file
(compilation database) in `build` folder. It is used by various tools, e.g.
`clangd`. In order to make sure that every CMake project produces compilation
database it is advised to add the following line to your `~/.bashrc` (or
equivalent):

```console
export CMAKE_EXPORT_COMPILE_COMMANDS=1
```

In order do explicitly define which compiler to use, one can add the following
lines to `~/.bashrc`:

```console
export CC=/usr/local/bin/clang
export CPP=/usr/local/bin/clang-cpp
export CXX=/usr/local/bin/clang++
```

## Style, clang-format and clang-tidy

The code style is very simple: all identifiers except for template parameters
use `snake_case`. Template parameters (both type, non-type and template) use
`PascalCase`. Rare occurrences of `#define`s use `SCREEMING_SNAKE_CASE`. Other
nuances are not detailed here. Document formatting is done automatically with
`clang-format`.

If working with `VS Code` it is highly advised to:
- enable: `Format On Save`
- enable: `Trim Final Newlines`
- enable: `Trim Trailing Whitespace`
- enable: `Insert Final Newline`

Furthermore, if working with `clangd` it is advised to modernize code according
to suggested changes.
