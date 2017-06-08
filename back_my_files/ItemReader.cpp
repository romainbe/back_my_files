#include <iostream>

#include "ItemReader.hpp"
#include "Item.h"

void BMF::ItemReader::read_item(Item& item)
{
    if (item.is_conf_valid())
    {
        read_item_(item);
    }
    else
    {
        std::cerr << "Invalid conf" << std::endl;
    }
}