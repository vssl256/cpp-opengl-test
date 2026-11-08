#pragma once

#include "Utils/File.h"

namespace Engine {
    class Shader {
        std::string name_;
        unsigned int vertexShader_{};
        unsigned int fragmentShader_{};
        unsigned int shaderProgram_{};
        const char *shaderPath_{ "assets/shaders/" };
        std::string vertexShaderSource;
        std::string fragmentShaderSource;
        int init();
        [[nodiscard]] std::string readShader( const std::string& ext ) const;
        int link();
        void deleteShaders() const;
        static int compile( unsigned int *shader, int type, const char *shaderSource );
        static int logShader(const unsigned int *shader, int type);
        static int logProgram(const unsigned int *program);
        static void logInit(int status);
    public:
        Shader( std::string name );

        ~Shader();
        Shader( const Shader& ) = delete;
        Shader& operator=( const Shader & ) = delete;
    };
}
