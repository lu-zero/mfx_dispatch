Autotooled/Cmakified version of the opensource Intel media sdk dispatcher.

The dispatcher provided by Intel only works on MS visual studio builds
due the fact it is written in C++ and mingw64 isn't ABI and library
compatible.
This set of build systems let you easily build a mingw-w64 one.
Currently only windows support is provided, the package is made just
to ease the testing of the QuickSync support in Libav/VLC.


BEWARE it is draft code and history will be rewritten many times.

## Linux



## Requirements

* MediaSDK drivers from Intel (in order to use it)
* mingw-w64 toolchain
* autotools or cmake (pick your poison)

## Building using autotools

`# autoreconf -i`

`# ./configure --host=x86_64-w64-mingw32`

`# make -j`

`# make install DESTDIR=/usr/x86_64-w64-mingw32`

## Building with Cmake

`# mkdir build && cd build`

For cross-compiling to win32/64:

`# cmake . -DCMAKE_INSTALL_PREFIX=/usr/x86_64-w64-mingw32 -DCMAKE_TOOLCHAIN_FILE=../Toolchain-cross-mingw32-linux.cmake`

For regular linux build:

`# cmake . -DCMAKE_INSTALL_PREFIX=/usr/local`

`# make -j`

`# make install`



