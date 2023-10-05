# How to build #

To build this project you will need [cmake](https://cmake.org/) (minimum version required is 3.27.0)

```shell

git clone https://github.com/AutoPilot2004/TIC-TAC-TOE.git
cd TIC-TAC-TOE
mkdir build
cd build

```

## Windows ##

For multi-config generators:

```shell

cmake .. [-G <"Visual Studio 17 2022", ...>]
cmake --build . [--config <Debug/Release/RelWithDebInfo>]

```

For single-config generators:

```shell

cmake .. [-DCMAKE_BUILD_TYPE=<Debug/Release/RelWithDebInfo>] [-G <"Ninja", ...>]
cmake --build .

```