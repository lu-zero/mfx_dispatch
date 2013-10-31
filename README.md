Autotooled/Cmakified version of the opensource Intel media sdk dispatcher.

The dispatcher provided by Intel only works on MS visual studio builds
due the fact it is written in C++ and mingw64 isn't ABI and library
compatible.
This set of build systems let you easily build a mingw-w64 one.
Currently only windows support is provided, the package is made just
to ease the testing of the QuickSync support in Libav/VLC.


BEWARE it is draft code and history will be rewritten many times.



## Requirements

* MediaSDK drivers from Intel. You have to either :
    * link/copy the 'include' folder of the SDK into your regular mingw include path under the 'mfx' name (e.g. /usr/x86_64-w64-mingw32/mfx) or
    * create a symbolic link named 'mfx' in this project's include folder pointing to the intel media sdk include folder.
* mingw-w64 toolchain
* autotools or cmake (pick your poison)

## Building using autotools

`# autoreconf -i`

`# ./configure --host=x86_64-w64-mingw32`

`# make -j`

`# make install DESTDIR=/usr/x86_64-w64-mingw32`

## Building with Cmake

`# mkdir build && cd build`

`# cmake . -DCMAKE_INSTALL_PREFIX=/usr/x86_64-w64-mingw32 -DCMAKE_TOOLCHAIN_FILE=../Toolchain-cross-mingw32-linux.cmake`

`# make -j`

`# make install`


# Building on Linux

The linux version currently leverages libva, thus either libva-drm or libva-x11 is required.
Only autotools is tested currently.

