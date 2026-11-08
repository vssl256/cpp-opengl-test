#pragma once

#include <string>
#include "FileExtension.h"


namespace Utils {
    enum class FileType;
}

namespace Utils {
    class File {
        const char *name_;
        FileType type_;
        FileExtension extension_;
        std::string path_;
        std::string typeName[2]{ "shaders", "textures" };
        std::string extensionName[2]{ "vert", "frag" };
    public:
        File( const char *name, FileType type, FileExtension extension );

        [[nodiscard]] std::string read() const;
    };
}
