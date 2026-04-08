# Area51

A small C++ demo application with a bundled test package ready for use in
[Yocto Project](https://www.yoctoproject.org/) builds via the `ptest` class.

---

## Project layout

```
Area51/
├── include/
│   ├── Human.hpp          # Human class header
│   └── catch.hpp          # Catch2 single-header test framework
├── src/
│   └── Human.cpp          # Human class implementation
├── main.cpp               # Application entry point
├── main.hpp               # Common includes
├── test.cpp               # Catch2 test suite
├── test1.cpp              # Boost.Test – factorial function
├── test2.cpp              # Boost.Test – Human::Factorial
├── test3.cpp              # Boost.Test – Human::getName
├── run-ptest              # Yocto ptest runner script
└── CMakeLists.txt
```

---

## Dependencies

| Dependency | Purpose |
|---|---|
| CMake ≥ 3.10 | Build system |
| Boost (unit_test_framework) | Boost.Test suites |
| GCC / Clang (C++11) | Compiler |

---

## Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

To build **without** tests:

```bash
cmake -B build -DBUILD_TESTING=OFF
cmake --build build
```

---

## Run tests locally

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

---

## Install

```bash
cmake --install build --prefix /path/to/staging
```

This installs:

| Path | Contents |
|---|---|
| `<prefix>/bin/area51` | Main application |
| `<prefix>/lib/Area51/ptest/` | All test binaries + `run-ptest` |

---

## Yocto / BitBake usage

See the BitBake recipe in [`meta-area51/recipes-test/area51/area51_git.bb`](meta-area51/recipes-test/area51/area51_git.bb).

Add the recipe to your layer, enable `ptest` in your image, and run:

```bash
ptest-runner area51
```

on the target device.

