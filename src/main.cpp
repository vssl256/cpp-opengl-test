#include "Window.h"
#include "Shader.h"

#include <GLFW/glfw3.h>

#include "Utils/File.h"
#include "Utils/FileType.h"

using namespace Utils;

int main() {
    {
        const auto window = Engine::Window{ "C++ GLFW Window", 640, 480 };
        const auto shader = Engine::Shader{ "a" };
        const auto file = File{ "fuckass", FileType::shader, FileExtension::vert };

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
