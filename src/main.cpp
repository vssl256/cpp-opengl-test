#include "Window.h"

int main() {
    const auto window = Engine::Window{ "fuckass window", 640, 480 };

    while ( !window.shouldClose() ) {
        window.processInput();

        Engine::Window::clear();

        window.poll();
    }
    Engine::Window::terminate();

    return 0;
}
