#include "window.h"
#include "Render.h"

#include <iostream>

static int fuck( const int a, const int b ) {
    return a + b;
}

using namespace Engine;

int main() {
    Window window;
    Render render;
    window.print();
    std::cout << "Hello world" << std::endl;
    fuck( 1, 1 );
    return -1;
}
