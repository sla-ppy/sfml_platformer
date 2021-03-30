cmake_minimum_required(VERSION 3.17)

include_directories("sfml/include")

set(CMAKE_CXX_STANDARD 17)

project(sfml_platformer)

add_subdirectory(sfml) # this is not submodule related

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /W3")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(sfml_platformer src/main.cpp)

target_include_directories(sfml_platformer PRIVATE SYSTEM sfml/include)

target_link_libraries(sfml_platformer sfml-graphics sfml-window sfml-system)

# this here is what solves the missing .dll issues, needed to run!
add_custom_command(TARGET sfml_platformer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_BINARY_DIR}/sfml/lib"
        $<TARGET_FILE_DIR:sfml_platformer>)