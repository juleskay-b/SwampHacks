cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(scrap)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "/opt/homebrew/opt/sfml")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
add_executable(scrap main.cpp
        pet.cpp
        pet.h
        player.cpp
        player.h
        authentification.cpp
        authentification.h)
target_link_libraries(scrap sfml-system sfml-window sfml-graphics sfml-audio)