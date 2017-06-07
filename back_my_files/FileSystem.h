#ifndef FILE_SYSTEM_H_
#define FILE_SYSTEM_H_

#include "IFileSystem.h"

namespace BMF
{

class FileSystem final : public BMF::IFileSystem
{
public:
    FileSystem();
    ~FileSystem();

public:
    bool create_dir(const std::string& dir_name) const override;
    bool dir_exist(const std::string& dir_name) const override;
    bool is_dir(const std::string& dir_name) const override;
};

}

#endif // FILE_SYSTEM_H_
