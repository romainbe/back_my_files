#include "File.h"

namespace BMF
{

const std::string File::_TYPE = "file";
const std::string File::_DESCR = "Backup standard files."; 
    
const std::string& File::type() const
{
    return _TYPE;
}

const std::string& File::description() const
{
    return _DESCR;
}

bool File::is_conf_valid() const
{
    const auto& found_filename = conf().find("filename");
    if (found_filename == conf().end())
    {
        return  false;
    }
 
    const auto& found_directory = conf().find("directory");
    if (found_directory == conf().end())
    {
        return  false;
    }
 
    return true;
}

}