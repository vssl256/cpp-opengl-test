#pragma once

struct GLFWwindow;

namespace Engine {
    class Window {
        GLFWwindow* window_ {};
        const char* title_;
        int width_;
        int height_;
        void init_();
        static void framebuffer_size_callback_( GLFWwindow* window, int width, int height );
    public:
        Window( const char* title, int width, int height );
        ~Window();
        [[nodiscard]] GLFWwindow* get() const;
        [[nodiscard]] bool shouldClose() const;
        void processInput() const;
        void poll() const;
        static void clear();
        static void terminate();
    };
}
