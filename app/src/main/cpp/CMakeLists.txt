cmake_minimum_required(VERSION 3.22.1)
enable_language(ASM)
set(can_use_assembler TRUE)
set(CMAKE_VERBOSE_MAKEFILE on)

project("androidasm")

add_library(${CMAKE_PROJECT_NAME} SHARED
        get_number.s
        get_hello_str.s
        native_lib.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log)