#include "File.h"

#include <iostream>
#include <ostream>
#include <cstring>
#include <cerrno>

#include "FileExtension.h"
#include "FileType.h"

namespace Utils {
    File::File( const char *name, const FileType type, const FileExtension extension ) : name_( name ), type_( type ), extension_( extension ) {
    }
}