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
    ${INCLUDE_DIR}/gtkmm
    ${INCLUDE_DIR}/glib
    ${INCLUDE_DIR}/glibmm
    ${INCLUDE_DIR}/gtest
)
link_directories(
    ${LIB_DIR}/glib
    ${LIB_DIR}/gtkmm
    ${LIB_DIR}/glibmm
    ${LIB_DIR}/gtest
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
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/glibmm/libglibmm-2.68
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/giomm/libgiomm-2.68
    ${CMAKE_SOURCE_DIR}/${LIB_DIR}/glib/libglib-2.0
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
message("Make build output path is /cmd")