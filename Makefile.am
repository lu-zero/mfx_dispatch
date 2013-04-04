ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/include -DMINGW_HAS_SECURE_API=1

dist_doc_DATA =

lib_LTLIBRARIES = libmfx.la

libmfx_la_SOURCES = \
	src/main.cpp                 \
        src/mfx_critical_section.cpp \
        src/mfx_dispatcher.cpp       \
        src/mfx_dispatcher_log.cpp   \
        src/mfx_dxva2_device.cpp     \
        src/mfx_function_table.cpp   \
        src/mfx_library_iterator.cpp \
        src/mfx_load_dll.cpp         \
        src/mfx_win_reg_key.cpp

libmfx_la_LDFLAGS = -version-info $(MFX_LT_CURRENT):$(MFX_LT_REVISION):$(MFX_LT_AGE)
libmfx_la_LIBADD = -lsupc++

pkginclude_HEADERS = \
	include/mfx_critical_section.h       \
	include/mfx_exposed_functions_list.h \
	include/mfx_dispatcher.h             \
	include/mfx_library_iterator.h       \
	include/mfx_dispatcher_log.h         \
	include/mfx_load_dll.h               \
	include/mfx_dxva2_device.h           \
	include/mfx_win_reg_key.h

pkgincludedir = $(includedir)/mfx


