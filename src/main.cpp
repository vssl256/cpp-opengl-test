#include <iostream>
#include <stb/stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
    const char* title_;
    int width_;
    int height_;

public:
    GLFWwindow* window {};

    Window( const char *title, const int width, const int height )
    : title_( title ), width_( width ), height_( height ) {
        init();
    }

    void init() {
        glfwInit();

        window = glfwCreateWindow( width_, height_, title_, nullptr, nullptr );
        if ( window == nullptr ) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent( window );

        if ( !gladLoadGLLoader( ( GLADloadproc )glfwGetProcAddress ) ) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
        }

        glViewport( 0, 0, width_, height_ );

        glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );
    }

    void clear() {
        glClearColor( 0.1882f, 0.0392f, 0.1412f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    }

private:
    static void framebuffer_size_callback( GLFWwindow* window, int width, int height ) {
        glViewport( 0, 0, width, height );
    }

    static void processInput( GLFWwindow* window ) {
        if ( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
            glfwSetWindowShouldClose( window, GLFW_TRUE );
    }
};

int main() {
    const auto window = Window{ "fuckass window", 640, 480 };

    while ( !glfwWindowShouldClose( window.window ) ) {
        glClearColor( 0.1882f, 0.0392f, 0.1412f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        glfwSwapBuffers( window.window );
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
