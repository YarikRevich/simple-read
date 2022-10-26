cmake_minimum_required(VERSION 3.16)
project(editor VERSION 0.0.1 LANGUAGES C CXX)                              

message("Enabling testing...")

include(CTest)
enable_testing()
add_subdirectory(tests)

if (WIN32) 
    set(INCLUDE_DIR "include/windows")
    set(LIB_DIR "lib/windows")
endif()

if (APPLE)
    set(INCLUDE_DIR "include/darwin")
    set(LIB_DIR "lib/darwin")

    set(CMAKE_CXX_COMPILER /usr/bin/g++)
	set(CMAKE_CXX_FLAGS "-std=c++2a -D_XOPEN_SOURCE_EXTENDED")
endif()

if (UNIX AND NOT APPLE)
    set(INCLUDE_DIR "include/linux")
    set(LIB_DIR "lib/linux")
endif()

include_directories(
    ${INCLUDE_DIR}/sigc++
    ${INCLUDE_DIR}/giomm
    ${INCLUDE_DIR}/gtkmm
    ${INCLUDE_DIR}/glib
    ${INCLUDE_DIR}/glibmm
    ${INCLUDE_DIR}/gtest
    ${INCLUDE_DIR}/gdkmm
    ${INCLUDE_DIR}/pangomm
    ${INCLUDE_DIR}/gtk
    ${INCLUDE_DIR}/gdk
    ${INCLUDE_DIR}/pango
    ${INCLUDE_DIR}/harfbuzz
)
link_directories(
    ${LIB_DIR}/sigc++
    ${LIB_DIR}/giomm
    ${LIB_DIR}/glib
    ${LIB_DIR}/gtkmm
    ${LIB_DIR}/glibmm
    ${LIB_DIR}/gtest
    ${LIB_DIR}/gdkmm
    ${LIB_DIR}/pangomm
    ${LIB_DIR}/gtk
    ${LIB_DIR}/gdk
    ${LIB_DIR}/pango
    ${LIB_DIR}/harfbuzz
)

file(GLOB src
    "**/*.h"
    "**/*.cpp"
)

add_executable(project ${src})

target_link_libraries(
    project

    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/gtest/libgtest_main.a
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/gtest/libgtest.a
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/gtkmm/libgtkmm-3.0.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/glibmm/libglibmm-2.68.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/giomm/libgiomm-2.68.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/glib/libglib-2.0.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/sigc++/libsigc-3.0.0.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/gdkmm/libgdk-3.0.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/pangomm/libpangomm-1.4.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/gtk/libgdk-3.0.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/gdk/libgtk-3.0.dylib
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/pango/libpango-1.0.a
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/harfbuzz/libharfbuzz.a
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
message("Make build output path is /cmd")