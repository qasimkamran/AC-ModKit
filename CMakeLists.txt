cmake_minimum_required(VERSION 3.16)
project(AC-ModKit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(texture_correct_lib STATIC
    texture_correct_lib.cpp
    texture_correct_lib.h
)

target_include_directories(texture_correct_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(NOT WIN32)
    target_include_directories(texture_correct_lib
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/stubs
    )
endif()

add_executable(ac_modkit
    main.cpp
)

target_link_libraries(ac_modkit
    PRIVATE
        texture_correct_lib
)

add_executable(texture_correct_tests
    tests/texture_correct_tests.cpp
)

target_link_libraries(texture_correct_tests
    PRIVATE
        texture_correct_lib
)

add_executable(directxtex_load_harness
    tests/directxtex_load_harness.cpp
)

target_link_libraries(directxtex_load_harness
    PRIVATE
        texture_correct_lib
)
