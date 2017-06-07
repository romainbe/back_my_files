#include <cstdint>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

#include "FileSystem.h"

BMF::FileSystem::FileSystem()
{
}

BMF::FileSystem::~FileSystem()
{
}

bool BMF::FileSystem::create_dir(const std::string& dir_name) const
{
    return fs::create_directory(dir_name);
}

bool BMF::FileSystem::dir_exist(const std::string& dir_name) const
{
    return fs::exists(dir_name);
}

bool BMF::FileSystem::is_dir(const std::string& dir_name) const
{
    return fs::is_directory(dir_name);
}

