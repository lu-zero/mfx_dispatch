project( libmfx )

find_path ( INTELMEDIASDK_PATH mfx/mfxvideo.h
  HINTS "${CMAKE_SOURCE_DIR}/include"
  HINTS "${CMAKE_SOURCE_DIR}/mfx"
)

set(SOURCES
  src/main.cpp
  src/mfx_critical_section.cpp
  src/mfx_dispatcher.cpp
  src/mfx_dispatcher_log.cpp
  src/mfx_dxva2_device.cpp
  src/mfx_function_table.cpp
  src/mfx_library_iterator.cpp
  src/mfx_load_dll.cpp
  src/mfx_win_reg_key.cpp
)

include_directories(
  include
)

add_definitions(
  -DDISPATCHER_LOG_REGISTER_FILE_WRITER
  -DMFX_DISPATCHER_LOG
  -DMFX_VA
  -DWIN32
  -D_DEBUG
  -D_LIB
)

configure_file (${CMAKE_SOURCE_DIR}/libmfx.pc.cmake ${CMAKE_BINARY_DIR}/libmfx.pc @ONLY)

add_library( mfx STATIC ${SOURCES} )
install (FILES ${CMAKE_SOURCE_DIR}/mfx/*
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/mfx)
install (FILES ${CMAKE_BINARY_DIR}/libmfx.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
install (TARGETS mfx ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
cmake_minimum_required(VERSION 2.6)
