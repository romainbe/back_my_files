#include "Item.h"

namespace BMF
{

Item::Item(std::map<std::string, std::string>&& conf)
    : _conf{std::move(conf)}
{
}

const std::map<std::string, std::string>& Item::conf() const
{
    return _conf;
}

}