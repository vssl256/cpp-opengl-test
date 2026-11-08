cmake_minimum_required(VERSION 3.20)

project(CppOpenGLTest LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 CONFIG REQUIRED)

add_library(glad STATIC
        third_party/glad/src/glad.c
)

target_include_directories(glad PUBLIC
        third_party/glad/include
)

add_executable(Test tests/main.cpp
        tests/window.cpp
        tests/window.h
        tests/Render.cpp
        tests/Render.h)

add_executable(CppOpenGLTest src/main.cpp
        src/stb.cpp
        src/Window.cpp
        src/Window.h
        src/Shader.cpp
        src/Shader.h
        src/Utils/File.cpp
        src/Utils/File.h
        src/Utils/File.cpp
        src/Utils/File.h
)

target_link_libraries(CppOpenGLTest PRIVATE
        glad
        glfw
)
