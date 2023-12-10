cmake_minimum_required(VERSION 3.27)

project(
    block-breaking-game
    VERSION 0.1.0
    LANGUAGES C)

include(CTest)

add_executable(main "src/main.c")

target_include_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
target_link_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/lib")

target_link_libraries(main PRIVATE mingw32 SDL2main SDL2)

set(SDL2_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/SDL2.dll")
set(SDL2_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll")

add_custom_command(
    OUTPUT "${SDL2_DESTINATION}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_SOURCE}"
            "${SDL2_DESTINATION}"
    COMMENT "Copying SDL2.dll to the build directory"
    MAIN_DEPENDENCY "${SDL2_SOURCE}"
)

add_custom_target(CopySDL2Dll DEPENDS "${SDL2_DESTINATION}")

add_dependencies(main CopySDL2Dll)

# Later on we will add script to build for releasing
