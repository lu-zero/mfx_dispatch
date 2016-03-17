project( libmfx )

# FIXME Adds support for using system/other install of intel media sdk
find_path ( INTELMEDIASDK_PATH mfx/mfxvideo.h
  HINTS "${CMAKE_SOURCE_DIR}"
)

if (INTELMEDIASDK_PATH_NOTFOUND)
  message( FATAL_ERROR "Intel MEDIA SDK include not found" )
else (INTELMEDIASDK_PATH_NOTFOUND)
  message(STATUS "Intel Media SDK is here: ${INTELMEDIASDK_PATH}")
endif (INTELMEDIASDK_PATH_NOTFOUND)


set(SOURCES
  src/main.cpp
  src/mfx_dispatcher.cpp
  src/mfx_dispatcher_log.cpp
  src/mfx_function_table.cpp
)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
  add_definitions(-fPIC)
  list(APPEND SOURCES
    src/mfx_library_iterator_linux.cpp
    src/mfx_load_dll_linux.cpp
    src/mfx_critical_section_linux.cpp
  )
endif (CMAKE_SYSTEM_NAME MATCHES "Linux")

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
  add_definitions(-DWIN32)
  list(APPEND SOURCES
    src/mfx_critical_section.cpp
    src/mfx_dxva2_device.cpp
    src/mfx_library_iterator.cpp
    src/mfx_load_dll.cpp
    src/mfx_load_plugin.cpp
    src/mfx_plugin_hive.cpp
    src/mfx_win_reg_key.cpp
  )
endif (CMAKE_SYSTEM_NAME MATCHES "Windows")

include_directories(
  ${INTELMEDIASDK_PATH}
  ${INTELMEDIASDK_PATH}/mfx
)

add_definitions(
  -DMFX_VA
  -D_LIB
)

configure_file (${CMAKE_SOURCE_DIR}/libmfx.pc.cmake ${CMAKE_BINARY_DIR}/libmfx.pc @ONLY)

add_library( mfx STATIC ${SOURCES} )
file(GLOB MFX_HEADERS "${CMAKE_SOURCE_DIR}/mfx/*.h")
install (FILES ${MFX_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install (FILES ${CMAKE_BINARY_DIR}/libmfx.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
install (TARGETS mfx ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
cmake_minimum_required(VERSION 2.6)
