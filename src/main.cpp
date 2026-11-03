#include "Window.h"

#include <GLFW/glfw3.h>

int main() {
    const auto window = Engine::Window{ "C++ GLFW Window", 640, 480 };

    while ( !window.shouldClose() ) {
        window.processInput();

        Engine::Window::clear();

        window.swapBuffers();
        Engine::Window::pollEvents();
    }
    glfwTerminate();

    return 0;
}
