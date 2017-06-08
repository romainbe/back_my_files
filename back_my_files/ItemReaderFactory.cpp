#include "ItemReaderFactory.hpp"
#include "FileReader.h"

namespace BMF {


std::unique_ptr<BMF::ItemReader> 
BMF::ItemReaderFactory::create_reader(const std::string& type)
{
    if (type == "file")
    {
        return std::make_unique<BMF::FileReader>();
    }
    return nullptr;
}

}
