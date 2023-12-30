cmake_minimum_required(VERSION 3.27)

# Describe the basic project details - name, version and language used

project(
    block-breaking-game
    VERSION 0.1.0
    LANGUAGES C)

include(CTest)

# The main file to be compiled

add_executable(main
    
    "src/main.c"
    "src/game.c"
    "src/blocks.c"
    "src/movement.c"
    "src/collision.c"
    "src/image.c"
    "src/gameover.c"
)

# Include and link the SDL files

target_include_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Include SDL2 and SDL2_image headers
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Link SDL2, SDL2main, and SDL2_image libraries
target_link_libraries(main PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

target_link_libraries(main PRIVATE mingw32 SDL2main SDL2 SDL2_image)

# The game needs SDL2.dll to run, so we added a custom command
# to move the dll from src to the build directory where the
# game can use it

set(SDL2_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/SDL2.dll")
set(SDL2_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll")

set(SDL2_IMAGE_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/SDL2_image.dll")
set(SDL2_IMAGE_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/SDL2_image.dll")

add_custom_command(
    OUTPUT "${SDL2_DESTINATION}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_SOURCE}"
            "${SDL2_DESTINATION}"
    COMMENT "Copying SDL2.dll to the build directory"
    MAIN_DEPENDENCY "${SDL2_SOURCE}"
)

add_custom_command(
    OUTPUT "${SDL2_IMAGE_DESTINATION}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_IMAGE_SOURCE}"
            "${SDL2_IMAGE_DESTINATION}"
    COMMENT "Copying SDL2.dll to the build directory"
    MAIN_DEPENDENCY "${SDL2_IMAGE_SOURCE}"
)

add_custom_target(CopySDL2Dll DEPENDS "${SDL2_DESTINATION}")
add_custom_target(CopySDL2ImageDll DEPENDS "${SDL2_IMAGE_DESTINATION}")

add_dependencies(main CopySDL2Dll)
add_dependencies(main CopySDL2ImageDll)

# Later on we will add script to build for releasing to
# different platforms such as Windows, various linux distros
# and OSX
