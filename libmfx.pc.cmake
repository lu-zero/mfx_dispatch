prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=${prefix}/lib
includedir=${prefix}/include

Name: libmfx
Description: Intel Media SDK Dispatched static library
Version: 2013
Requires:
Requires.private:
Conflicts:
Libs: -L${libdir} -lsupc++ ${libdir}/libmfx.a
Libs.private:
Cflags: -I${includedir} -I@INTELMEDIASDK_PATH@
