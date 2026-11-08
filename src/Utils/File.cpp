#include "File.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <cerrno>

#include "FileExtension.h"
#include "FileType.h"

namespace Utils {
    File::File( const char *name, const FileType type, const FileExtension extension ) : name_( name ), type_( type ), extension_( extension ) {
        path_ = "/home/vessel/CLionProjects/cpp-opengl-test/assets/" + typeName[ static_cast<int>( type_ ) ] + "/" + name_ + "." + extensionName[ static_cast<int>( extension_ ) ];
        std::clog << path_ << std::endl;
    }

    std::string File::read() const {
        std::ifstream file( path_.c_str(), std::ios::binary );
        if ( !file.is_open() ) {
            std::cerr << "Could not open " << path_ << " " << strerror( errno ) << " " << path_ << std::endl;
            return "";
        }

        const size_t size = std::filesystem::file_size( path_ );

        std::string buffer;
        buffer.resize( size );
        file.read( buffer.data(), size );
        file.close();

        return buffer;
    }
}