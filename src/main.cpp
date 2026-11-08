#include <iostream>
#include <ostream>

#include "Window.h"
#include "Shader.h"

#include <GLFW/glfw3.h>

#include "Utils/File.h"
#include "Utils/FileType.h"

using namespace Utils;

int main() {
    {
        const Engine::Window window{ "C++ GLFW Window", 640, 480 };
        const Engine::Shader shader{ "a" };
        const File file{ "a", FileType::shader, FileExtension::vert };

        std::cout << file.read().c_str() << std::endl;

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
