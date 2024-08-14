cmake_minimum_required(VERSION 3.30)


project(PhysVis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



file (GLOB_RECURSE sources
    "${CMAKE_SOURCE_DIR}/src/*.cpp")

file (GLOB_RECURSE libs "${CMAKE_SOURCE_DIR}/lib/*.a")
file (GLOB imguisrc "${CMAKE_SOURCE_DIR}/deps/imgui/*.cpp")
file (GLOB imguisfml "${CMAKE_SOURCE_DIR}/deps/imgui-sfml/*.cpp")

set(IMGUI_DIR deps/imgui)
set(IMGUISFML_DIR deps/imgui-sfml)

add_executable(physvis ${sources} ${imguisrc} ${imguisfml})

target_include_directories(physvis PUBLIC "${CMAKE_SOURCE_DIR}/include" 
  "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/deps/imgui" "${CMAKE_SOURCE_DIR}/deps/imgui-sfml") 
target_link_libraries(physvis PRIVATE sfml-graphics sfml-system sfml-window glfw3 glut GLU GL 
  ${libs})
target_compile_features(physvis PRIVATE cxx_std_17)
include_directories("${CMAKE_SOURCE_DIR}/include")
