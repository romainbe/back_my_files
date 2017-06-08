#ifndef I_FILE_SYSTEM
#define I_FILE_SYSTEM

#include <string>

namespace BMF
{
class IFileSystem
{
public:
    IFileSystem() = default;
    virtual ~IFileSystem() = default;

    virtual bool dir_exist(const std::string& dir_name) const = 0;
    virtual bool create_dir(const std::string& dir_name) const = 0;
    virtual bool is_dir(const std::string& dir_name) const = 0;
};

}

#endif // I_FILE_SYSTEM
