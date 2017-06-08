#ifndef ITEM_READER_HPP_
#define ITEM_READER_HPP_

namespace BMF
{

class Item;
    
template <typename ITEM_TYPE>
class ItemReader
{
public:
    ItemReader() = default;
    virtual ~ItemReader() = default;
    
    typedef ITEM_TYPE   type;
    virtual void read_item(ITEM_TYPE& item) = 0;
};

}

#endif // ITEM_READER_HPP_
