# Prism

Prism is a 3D game engine currently in WIP.

## Getting Started

Start by cloning the repository with

```
git clone --recursive https://github.com/harshit2608/Prism.git
```

If the repository was cloned non-recursively previously, use
`git submodule update --init`
to clone the necessary submodules.

## How to build Prism?

After cloning the repository first download [premake](https://premake.github.io/download/)
and place it inside `vendor/premake/bin`.

<h4>Building Prism on windows</h4>

Run the `scripts\Win-GenProject.bat` which will generate a Visual Studio 2022 solution.

**MSVC**
Download MSVC from [here](https://visualstudio.microsoft.com/vs/features/cplusplus/)

<h4>Building Prism on Mac</h4>

**XCODE**

Download Xcode-toolchain and clang, and run `scripts/Mac-GenProjects.sh` which will generate make files using gmake2.
After that just run make command and build the build project.

<h4>Building Prism on Linux</h4>

**PROJECT IS UNDERDEVELOPMENT AND HASN'T BEEN TESTED ON LINUX!!**
