cmake_minimum_required(VERSION 3.16)
project(MiniEngine LANGUAGES C CXX)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download SDL2 automatically from GitHub
include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON  CACHE BOOL "" FORCE)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-2.30.9
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(SDL2)

# Our program
add_executable(game src/main.cpp)

if(TARGET SDL2::SDL2main)
    target_link_libraries(game PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(game PRIVATE SDL2::SDL2-static)