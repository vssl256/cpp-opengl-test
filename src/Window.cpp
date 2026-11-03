#include "Window.h"

#include <iostream>
#include <ostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine {
    Window::Window( const char* title, const int width, const int height )
        : title_( title ), width_( width ), height_( height ) {
        init_();
    }

    Window::~Window() {
        if ( window_ != nullptr ) {
            glfwDestroyWindow( window_ );
        }
    }

    void Window::init_() {
        if ( !glfwInit() ) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        createWindowHints();

        window_ = glfwCreateWindow( width_, height_, title_, nullptr, nullptr );
        if ( window_ == nullptr ) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            return;
        }
        glfwMakeContextCurrent( window_ );

        if ( !gladLoadGLLoader( reinterpret_cast<GLADloadproc>( glfwGetProcAddress ) ) ) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            return;
        }

        glViewport( 0, 0, width_, height_ );

        glfwSetFramebufferSizeCallback( window_, framebuffer_size_callback_ );
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose( window_ );
    }

    GLFWwindow* Window::get() const {
        return window_;
    }

    void Window::framebuffer_size_callback_( GLFWwindow*, const int width, const int height ) {
        glViewport( 0, 0, width, height );
    }

    void Window::processInput() const {
        if ( glfwGetKey( window_, GLFW_KEY_ESCAPE ) == GLFW_PRESS ) {
            glfwSetWindowShouldClose( window_, GLFW_TRUE );
        }
    }

    void Window::swapBuffers() const {
        glfwSwapBuffers( window_ );
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    void Window::clear() {
        glClearColor( 0.1882f, 0.0392f, 0.1412f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    }

    void Window::createWindowHints() {
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    }
}
