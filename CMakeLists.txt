project( libmfx )

find_path ( INTELMEDIASDK_PATH mfx/mfxvideo.h
  HINTS "${CMAKE_SOURCE_DIR}/include"
  # ENV INTELMEDIASDK_PATH
  )

if (INTELMEDIASDK_PATH)
  message("Intel Media SDK include folder found ! (${INTELMEDIASDK_PATH})")
else (INTELMEDIASDK_PATH)
  message(FATAL_ERROR "Intel Media SDK include folder required, but not found !")
endif (INTELMEDIASDK_PATH)

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
  ${INTELMEDIASDK_PATH}
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

configure_file (${CMAKE_SOURCE_DIR}/libmfx.pc ${CMAKE_BINARY_DIR}/libmfx.pc @ONLY)


add_library( mfx STATIC ${SOURCES} )
install (FILES ${CMAKE_SOURCE_DIR}/include/mfx_dispatcher.h
  ${CMAKE_SOURCE_DIR}/include/mfx_dispatcher.h
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install (FILES ${CMAKE_BINARY_DIR}/libmfx.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
install (TARGETS mfx ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
cmake_minimum_required(VERSION 2.6)
