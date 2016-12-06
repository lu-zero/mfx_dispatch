Autotooled version of the opensource Intel media sdk dispatcher.

# Linux

## Requirements

* A C/C++ compiler
* autotools
* libva

## Building

```
autoreconf -i
./configure --prefix=/usr
make -j$(nproc)
make install
```

# Windows

The dispatcher provided by Intel only works on MS visual studio builds due the fact it is written in C++ and mingw64 isn't ABI and library compatible.
This set of build systems let you easily build a mingw-w64 one.

## Requirements

* MediaSDK drivers from Intel
* mingw-w64 toolchain
* autotools or cmake (pick your poison)

## Building using autotools

### Cross compile
``` sh
autoreconf -i
./configure --host=x86_64-w64-mingw32
make -j$(nproc)
make install DESTDIR=/usr/x86_64-w64-mingw32
```

### Building on a native mingw-w64 environment
``` sh
autoreconf -i
./configure --prefix=/mingw64
make -j$(nproc) install
```

**NOTE**: Make sure you set the `prefix` to the correct one for your environment otherwise it will fail to link.
