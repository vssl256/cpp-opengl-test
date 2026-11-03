cmake_minimum_required(VERSION 4.3)
project(CppOpenGLTest)

set(CMAKE_CXX_STANDARD 23)

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
        src/Window.h)

target_link_libraries(CppOpenGLTest PRIVATE
        glad
        glfw
)