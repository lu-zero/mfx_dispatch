AC_PREREQ([2.53])

AC_INIT([libmfx], [1.31])
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
    [*cygwin*], [
        AC_DEFINE([MFX_HAVE_WINDOWS])
        AC_DEFINE([_MAX_PATH], [MAX_PATH])
        AM_CONDITIONAL([WINDOWS], [true])
        DLLIB=""
    ],
    [AC_MSG_ERROR([${host_os} not supported.])]
)

AS_CASE([${host_os}],
    [mingw32uwp], [
        AM_CONDITIONAL([WINDOWS_STORE], [true])
        DLLIB="$(DLLIB) -ldxgi"
    ],
    [mingw32winrt], [
        AM_CONDITIONAL([WINDOWS_STORE], [true])
        DLLIB="$(DLLIB) -ldxgi"
    ],
    [
        AM_CONDITIONAL([WINDOWS_STORE], [false])
    ]
)

IMPORT_GFX_X86=false
IMPORT_GFX_X64=false
AS_IF([test -z "${WINDOWS_STORE_TRUE}"],[
    AS_CASE([${host_cpu}],
        [i?86],[
            IMPORT_GFX_X86=true
            DLLIB="$(DLLIB) -lintel_gfx_api-x86"
        ],
        [x86_64],[
            IMPORT_GFX_X64=true
            DLLIB="$(DLLIB) -lintel_gfx_api-x64"
        ]
)
])
AM_CONDITIONAL([DLLTOOL_X86], [test "${IMPORT_GFX_X86}" = "true"])
AM_CONDITIONAL([DLLTOOL_X64], [test "${IMPORT_GFX_X64}" = "true"])

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
