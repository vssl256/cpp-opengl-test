#pragma once

#include <string>
#include <filesystem>

namespace Utils {
    enum class FileType;
}

namespace Utils {
    class File {
        std::filesystem::path path_;
    public:
        File( std::filesystem::path path, const char *name );

        [[nodiscard]] std::string read() const;
    };
}
