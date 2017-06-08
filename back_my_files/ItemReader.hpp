#ifndef ITEM_READER_HPP_
#define ITEM_READER_HPP_

namespace BMF
{

class Item;
    
class ItemReader
{
public:
    ItemReader() = default;
    virtual ~ItemReader() = default;

    virtual void read_item(Item& item) final;

private:
    virtual void read_item_(Item& item) = 0;
};

}

#endif // ITEM_READER_HPP_
