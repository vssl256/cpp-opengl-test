#include "Shader.h"

#include <iostream>
#include <ostream>

#include "glad/glad.h"

namespace Engine {
    Shader::Shader( const char *name )
    : name_( name ) {
        init();
    }

    void Shader::init() {
        compile( &vertexShader_, GL_VERTEX_SHADER, vertexShaderSource );
        compile( &fragmentShader_, GL_FRAGMENT_SHADER, fragmentShaderSource );
        link();

        glUseProgram( shaderProgram_ );
    }

    void Shader::link() {
        shaderProgram_ = glCreateProgram();
        glAttachShader( shaderProgram_, vertexShader_ );
        glAttachShader( shaderProgram_, fragmentShader_ );
        glLinkProgram( shaderProgram_ );

        glDeleteShader( vertexShader_ );
        glDeleteShader( fragmentShader_ );

        log( &shaderProgram_, GL_PROGRAM );
    }

    void Shader::compile( unsigned int *shader, const int type, const char *shaderSource ) {
        *shader = glCreateShader( type );

        glShaderSource( *shader, 1, &shaderSource, nullptr );
        glCompileShader( *shader );

        log( shader, type );
    }

    void Shader::log( const unsigned int *ref, const int type ) {
        int success;
        if ( type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER ) {
            glGetShaderiv( *ref, GL_COMPILE_STATUS, &success );
            if ( success ) return;

            char infoLog[512];
            glGetShaderInfoLog( *ref, 512, nullptr, infoLog );
            const std::string_view shaderType{ type == GL_VERTEX_SHADER ? "Vertex" : "Fragment" };
            std::cerr << shaderType << " shader compilation failed: " << infoLog << std::endl;
        }
        if ( type == GL_PROGRAM ) {
            glGetProgramiv( *ref, GL_LINK_STATUS, &success );
            if ( success ) return;

            char infoLog[512];
            glGetProgramInfoLog( *ref, 512, nullptr, infoLog );
            std::cerr << "Program linking failed: " << infoLog << std::endl;
        }
    }
}
