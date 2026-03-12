cmake_minimum_required(VERSION 3.16)
project(basic_button)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(basic_button main.cpp)

target_link_libraries(basic_button PRIVATE
    SimpleUI
    SFML::Graphics
    SFML::Window
    SFML::System
)