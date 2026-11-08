#include <iostream>
#include <ostream>

#include "Window.h"
#include "Shader.h"

#include <GLFW/glfw3.h>

#include "Utils/File.h"

using namespace Utils;

int main() {
    {
        const Engine::Window window{ "C++ GLFW Window", 640, 480 };
        const Engine::Shader shader{ "a" };

        while ( !window.shouldClose() ) {
            window.processInput();

            Engine::Window::clear();

            window.swapBuffers();
            Engine::Window::pollEvents();
        }
    }

    glfwTerminate();

    return 0;
}
