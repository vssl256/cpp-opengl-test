#include "Shader.h"

#include <iostream>
#include <ostream>

#include "glad/glad.h"

namespace Engine {
    Shader::Shader( const char *name )
    : name_( name ) {
        logInit( init() );
    }

    Shader::~Shader() {
        glDeleteProgram( shaderProgram_ );
    }

    int Shader::init() {
        const int vsStatus = compile( &vertexShader_, GL_VERTEX_SHADER, vertexShaderSource );
        const int fsStatus = compile( &fragmentShader_, GL_FRAGMENT_SHADER, fragmentShaderSource );
        if ( vsStatus + fsStatus != 0 ) return 1;
        if ( link() != 0 ) return -1;

        glUseProgram( shaderProgram_ );
        return 0;
    }

    int Shader::link() {
        shaderProgram_ = glCreateProgram();
        glAttachShader( shaderProgram_, vertexShader_ );
        glAttachShader( shaderProgram_, fragmentShader_ );
        glLinkProgram( shaderProgram_ );

        glDeleteShader( vertexShader_ );
        glDeleteShader( fragmentShader_ );

        if ( logProgram( &shaderProgram_ ) != 0 ) return -1;
        return 0;
    }

    int Shader::compile( unsigned int *shader, const int type, const char *shaderSource ) {
        *shader = glCreateShader( type );

        glShaderSource( *shader, 1, &shaderSource, nullptr );
        glCompileShader( *shader );

        return logShader( shader, type );
    }

    void Shader::logInit( const int status ) {
        switch ( status ) {
            case 0: std::clog << "Program linkage SUCCESS\n"; break;
            case 1: std::cerr << "Shader compilation FAILED" << std::endl; break;
            case -1: std::cerr << "Program linkage FAILED" << std::endl; break;
            default: std::cerr << "Something is really fucked" << std::endl; break;
        }
    }

    int Shader::logShader( const unsigned int *shader, const int type ) {
        int success;

        glGetShaderiv( *shader, GL_COMPILE_STATUS, &success );
        if ( success ) return 0;

        char infoLog[512];
        glGetShaderInfoLog( *shader, 512, nullptr, infoLog );
        const std::string_view shaderType{ type == GL_VERTEX_SHADER ? "Vertex" : "Fragment" };
        std::cerr << shaderType << " shader compilation failed: " << infoLog << std::endl;
        return 1;
    }

    int Shader::logProgram( const unsigned int *program ) {
        int success;

        glGetProgramiv( *program, GL_LINK_STATUS, &success );
        if ( success ) return 0;

        char infoLog[512];
        glGetProgramInfoLog( *program, 512, nullptr, infoLog );
        std::cerr << "Program linking failed: " << infoLog << std::endl;
        return 1;
    }
}
