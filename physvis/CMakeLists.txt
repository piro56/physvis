cmake_minimum_required(VERSION 3.30)

include(FetchContent)

project(PhysVis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(IMGUI_VERSION 1.91)


file (GLOB_RECURSE sources
    "${CMAKE_SOURCE_DIR}/src/*.cpp")

file (GLOB_RECURSE libs "${CMAKE_SOURCE_DIR}/lib/*.a")


FetchContent_Declare(
  imgui
  URL "https://github.com/ocornut/imgui/archive/refs/tags/v${imgui_version}.zip"
)


FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
  GIT_TAG        2.6.x
)


FetchContent_MakeAvailable(imgui)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
FetchContent_MakeAvailable(imgui-sfml)


add_executable(physvis ${sources})

target_include_directories(physvis PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(physvis PRIVATE sfml-graphics sfml-system sfml-window glfw3 ${libs} PUBLIC ImGui-SFML::ImGui-SFML)
target_compile_features(physvis PRIVATE cxx_std_17)
include_directories("${CMAKE_SOURCE_DIR}/include")
