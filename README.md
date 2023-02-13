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
core/test $ conan install . --output-folder=build
```
```bash
core/test $ cd build
core/test/build $ cmake .. --preset release
```
```bash
core/test/build $ cmake --build . -- -j4
```
```bash
core/test/build $ ./runtimeTest
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