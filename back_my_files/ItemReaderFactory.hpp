#ifndef ITEM_READER_FACTORY_H_
#define ITEM_READER_FACTORY_H_

#include <string>
#include <memory>

#include "ItemReader.hpp"

namespace BMF
{

class ItemReaderFactory
{
public:
    ItemReaderFactory() = default;
    ~ItemReaderFactory() = default;
    
    std::unique_ptr<BMF::ItemReader> create_reader(const std::string& type = "file");
};

}

#endif // ITEM_READER_FACTORY_H_
