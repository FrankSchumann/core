# core

# Conan package manager

## Create
Build and upload package to Conan cache.

```bash
core $ conan create .
```

## Install
Install conan packages and create files for building.
Must be done before Build

### Release
```bash
core $ conan install . --output-folder=build
```

### Debug
```bash
core $ conan install . --output-folder=build -s build_type=Debug
```

# CMake
Change directory to build.

```bash
core $ cd build
```

## Release
```bash
core $ cmake .. --preset release
```

## Debug
```bash
core $ cmake .. --preset debug
```

# Build

```bash
core $ cmake --build . -- -j4
```

# Test
Build and execute GoogleTest.

```bash
runtime/build/test $ conan install . --output-folder=build
```
```bash
runtime/build/test $ cd build
runtime/build/test $ cmake .. --preset=release
```
```bash
runtime/build/test $ cmake --build . -- -j4
```
```bash
runtime/build/test $ ./runtimeTest
```

# Import Projects

## Eclipse CDT
Import the projects to Eclipse CDT based on CMake as follows:

File -> Open Projects from File System...

## Wind River Workbench
Import the projects to the Wind River Workbench based on CMake as follows:

- Create a new CMake RTP project at folder codesys
- revert changes to .gitignore
- revert changes to CMakeLists.txt

# Git
Delete all ignored/created files.

```bash
runtime $ git clean -fxd
```