cmake_minimum_required(VERSION 3.16)
project(AC-ModKit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(texture_correct_lib STATIC
    texture_correct_lib.cpp
    texture_correct_lib.h
)

target_include_directories(texture_correct_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(WIN32)
    include(FetchContent)

    FetchContent_Declare(
        DirectXTexProject
        GIT_REPOSITORY https://github.com/microsoft/DirectXTex.git
        GIT_TAG main
    )

    FetchContent_MakeAvailable(DirectXTexProject)

    target_link_libraries(texture_correct_lib
        PUBLIC
            DirectXTex
    )
else()
    target_include_directories(texture_correct_lib
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/stubs
    )
endif()

add_library(gui_lib STATIC
    gui_lib.cpp
    gui_lib.h
)

target_compile_definitions(gui_lib
    PRIVATE
        AC_MODKIT_SOURCE_ASSETS_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/assets\"
)

target_include_directories(gui_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(gui_lib
    PUBLIC
        Qt6::Widgets
)

add_executable(ac_modkit
    main.cpp
)

target_link_libraries(ac_modkit
    PRIVATE
        gui_lib
        texture_correct_lib
        Qt6::Widgets
)

add_custom_command(
    TARGET ac_modkit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:ac_modkit>/assets
    COMMENT "Copying UI assets next to ac_modkit"
)

install(TARGETS ac_modkit)
install(DIRECTORY assets DESTINATION .)

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
