#include "File.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <cerrno>
#include <utility>

namespace Utils {
    File::File( std::filesystem::path path, const char *name ) : path_( std::move( path ) ) {
        path_ += name;
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