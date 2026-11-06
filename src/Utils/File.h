#pragma once
#include "FileExtension.h"

namespace Utils {
    enum class FileType;
}

namespace Utils {
    class File {
        const char *name_;
        FileType type_;
        FileExtension extension_;
    public:
        File( const char *name, FileType type, FileExtension extension );
    };
}
