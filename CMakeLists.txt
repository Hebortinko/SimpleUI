cmake_minimum_required(VERSION 3.16)
project(SimpleUI)

add_library(SimpleUI INTERFACE)
target_include_directories(SimpleUI INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/SimpleUI>
    $<INSTALL_INTERFACE:include>
    $<INSTALL_INTERFACE:include/SimpleUI>
)

option(SIMPLEUI_BUILD_EXAMPLES "Build examples" OFF)

if(SIMPLEUI_BUILD_EXAMPLES)
    #add_subdirectory(examples/basic_button)
    add_subdirectory(examples/basic_slider)
endif()