#ifndef BACK_ITEM_H__
#define BACK_ITEM_H__

#include <string>
#include <map>

namespace BMF
{

class Item
{
public:
    Item(std::map<std::string, std::string>&& conf);

    virtual ~Item() = default;
    
    virtual const std::string& type() const= 0;
    virtual const std::string& description() const = 0;
    virtual bool    is_conf_valid() const = 0;

    virtual const std::map<std::string, std::string>& conf() const final;

private:
    std::map<std::string, std::string>   _conf;
};

}

#endif // BACK_ITEM_H__
