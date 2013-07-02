ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/include -DMINGW_HAS_SECURE_API=1

dist_doc_DATA =

lib_LTLIBRARIES = libmfx.la

libmfx_la_SOURCES = \
	src/mfx_critical_section.h       \
	src/mfx_exposed_functions_list.h \
	src/mfx_dispatcher.h             \
	src/mfx_library_iterator.h       \
	src/mfx_dispatcher_log.h         \
	src/mfx_load_dll.h               \
	src/mfx_dxva2_device.h           \
	src/mfx_win_reg_key.h            \
	src/main.cpp                     \
        src/mfx_critical_section.cpp     \
        src/mfx_dispatcher.cpp           \
        src/mfx_dispatcher_log.cpp       \
        src/mfx_dxva2_device.cpp         \
        src/mfx_function_table.cpp       \
        src/mfx_library_iterator.cpp     \
        src/mfx_load_dll.cpp             \
        src/mfx_win_reg_key.cpp

libmfx_la_LDFLAGS = -version-info $(MFX_LT_CURRENT):$(MFX_LT_REVISION):$(MFX_LT_AGE)
libmfx_la_LIBADD = -lsupc++

pkginclude_HEADERS = \
	mfx/mfxdefs.h                    \
	mfx/mfxplugin.h                  \
	mfx/mfxstructures.h              \
	mfx/mfxvideo.h

pkgincludedir = $(includedir)/mfx


