AC_PREREQ([2.53])

AC_INIT([libmfx], [1.23])
AC_CONFIG_SRCDIR([src/mfx_dispatcher.cpp])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CANONICAL_HOST

AS_CASE([${host_os}],
    [*linux*], [
        AC_DEFINE([MFX_HAVE_LINUX])
        AM_CONDITIONAL([WINDOWS], [false])
        DLLIB="-ldl"
    ],
    [*mingw*], [
        AC_DEFINE([MFX_HAVE_WINDOWS])
        AM_CONDITIONAL([WINDOWS], [true])
        DLLIB=""
    ],
    [AC_MSG_ERROR([${host_os} not supported.])]
)

PKG_HAVE_DEFINE_WITH_MODULES(LIBVA_DRM, [libva-drm])
PKG_HAVE_DEFINE_WITH_MODULES(LIBVA_X11, [libva-x11])

MFX_LT_CURRENT=1
MFX_LT_AGE=0
MFX_LT_REVISION=0

AC_SUBST(MFX_LT_CURRENT)
AC_SUBST(MFX_LT_AGE)
AC_SUBST(MFX_LT_REVISION)
AC_SUBST(DLLIB)

AC_PROG_CXX

AC_MSG_CHECKING(whether fPIC compiler option is accepted)
SAVED_CXXFLAGS="$CXXFLAGS"
CXXFLAGS="$CXXFLAGS -fPIC -Werror"
AC_LANG_PUSH(C++)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [return 0;])],
    [AC_MSG_RESULT(yes)
     CXXFLAGS="$SAVED_CXXFLAGS -fPIC"],
    [AC_MSG_RESULT(no)
     CXXFLAGS="$SAVED_CXXFLAGS"])
AC_LANG_POP(C++)

LT_INIT([disable-shared])

AC_CONFIG_MACRO_DIR([m4])

AC_OUTPUT([
libmfx.pc
Makefile
])
