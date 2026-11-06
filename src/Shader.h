#pragma once

namespace Engine {
    class Shader {
        const char *name_;
        unsigned int vertexShader_{};
        unsigned int fragmentShader_{};
        unsigned int shaderProgram_{};
        const char *vertexShaderSource{"#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"};
        const char *fragmentShaderSource{"#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0"};
        void init();
        void link();
        static void compile( unsigned int *shader, int type, const char *shaderSource );
        static void log( const unsigned int *ref, int type );
    public:
        Shader( const char *name );
    };
}
