#ifndef BACK_FILE_H
#define BACK_FILE_H

#include "Item.h"

namespace BMF
{

class File final : public Item
{
private:
    static const std::string    _TYPE;
    static const std::string    _DESCR;
    
public:
    File(std::map<std::string, std::string>&& conf)
        : Item {
            std::forward<
                std::map<std::string, std::string>
            >(conf)
        }
    {}

    const std::string& type() const override;
    const std::string& description() const override;
    bool is_conf_valid() const override;
};

}

#endif // BACK_FILE_H
