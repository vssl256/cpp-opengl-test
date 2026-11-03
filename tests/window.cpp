#include "window.h"

#include <iostream>
#include <ostream>

namespace Engine {
    Window::Window() {
        std::cout << "Window initialized" << std::endl;
    }

    void Window::print() {
        std::cout << "Print" << std::endl;
    }
}
