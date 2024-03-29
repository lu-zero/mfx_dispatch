ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/include -DMINGW_HAS_SECURE_API=1 -DMFX_MODULES_DIR=\".\" -DMFX_PLUGINS_CONF_DIR=\".\"

dist_doc_DATA =

lib_LTLIBRARIES = libmfx.la

if WINDOWS
libmfx_la_SOURCES = \
    src/mfx_critical_section.h       \
    src/mfx_exposed_functions_list.h \
    src/mfx_dispatcher.h             \
    src/mfx_dispatcher_log.h         \
    src/mfx_library_iterator.h       \
    src/mfx_load_dll.h               \
    src/main.cpp                     \
    src/mfx_critical_section.cpp     \
    src/mfx_dispatcher.cpp           \
    src/mfx_dispatcher_log.cpp       \
    src/mfx_load_plugin.cpp          \
    src/mfx_function_table.cpp       \
    src/mfx_dxva2_device.h           \
    src/mfx_win_reg_key.h            \
    src/mfx_dxva2_device.cpp         \
    src/mfx_library_iterator.cpp     \
    src/mfx_load_dll.cpp             \
    src/mfx_win_reg_key.cpp          \
    src/mfx_plugin_hive.cpp          \
    src/mfx_driver_store_loader.h    \
    src/mfx_driver_store_loader.cpp
else
libmfx_la_SOURCES = \
    src/mfxloader.cpp                \
    src/mfxparser.cpp
endif


libmfx_la_LDFLAGS = -no-undefined -static-libgcc -static-libstdc++
libmfx_la_LDFLAGS += -version-info $(MFX_LT_CURRENT):$(MFX_LT_REVISION):$(MFX_LT_AGE)
libmfx_la_LIBADD = $(DLLIB) $(LIBVA_DRM_LIBS) $(LIBVA_X11_LIBS)
libmfx_la_CPPFLAGS = $(LIBVA_DRM_CFLAGS) $(LIBVA_X11_CFLAGS) $(AM_CPPFLAGS)

if WINDOWS_STORE
libmfx_la_SOURCES += src/mfx_dispatcher_uwp.cpp
libintel_gfx_api-x86.a: src/intel_gfx_api-x86.def
	$(DLLTOOL) --as=as --output-lib $@ --input-def $< --as-flags=--32 -m i386 
libintel_gfx_api-x64.a: src/intel_gfx_api-x64.def
	$(DLLTOOL) --as=as --output-lib $@ --input-def $< --as-flags=--64 -m i386:x86-64

if DLLTOOL_X86
lib_LTLIBRARIES += libintel_gfx_api-x86.a
endif
if DLLTOOL_X64
lib_LTLIBRARIES += libintel_gfx_api-x64.a
endif
endif


pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmfx.pc

pkginclude_HEADERS = \
	mfx/mfxadapter.h					\
	mfx/mfxastructures.h				\
	mfx/mfxaudio.h						\
	mfx/mfxaudio++.h					\
	mfx/mfxcamera.h						\
	mfx/mfxcommon.h						\
	mfx/mfxdispatcherprefixedfunctions.h\
	mfx/mfxdefs.h						\
	mfx/mfxenc.h						\
	mfx/mfxjpeg.h						\
	mfx/mfxla.h							\
	mfx/mfxmvc.h						\
	mfx/mfxpak.h						\
	mfx/mfxpcp.h						\
	mfx/mfxplugin.h						\
	mfx/mfxplugin++.h					\
	mfx/mfxsc.h							\
	mfx/mfxscd.h						\
	mfx/mfxsession.h					\
	mfx/mfxstructures.h					\
	mfx/mfxvideo.h						\
	mfx/mfxvideo++.h					\
	mfx/mfxvp8.h						\
	mfx/mfxvp9.h						\
	mfx/mfxvstructures.h				\
	mfx/mfxbrc.h						\
	mfx/mfxfei.h						\
	mfx/mfxfeihevc.h					\
	mfx/ts_ext_buffers_decl.h			\
	mfx/ts_struct_decl.h				\
	mfx/ts_typedef.h

pkgincludedir = $(includedir)/mfx
