#pragma once

struct GLFWwindow;

namespace Engine {
    class Window {
        GLFWwindow *window_{};
        const char *title_;
        int width_;
        int height_;
        void init_();
        static void framebuffer_size_callback_( GLFWwindow *window, int width, int height );
        static void createWindowHints();

    public:
        Window( const Window & ) = delete;
        Window &operator=( const Window & ) = delete;
        [[nodiscard]] Window( const char *title, int width, int height );
        ~Window();
        [[nodiscard]] GLFWwindow *get() const;
        [[nodiscard]] bool shouldClose() const;
        void processInput() const;
        void swapBuffers() const;
        static void pollEvents();
        static void clear();
    };
}
