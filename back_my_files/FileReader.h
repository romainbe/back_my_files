#ifndef FILE_READER_H_
#define FILE_READER_H_

#include "ItemReader.hpp"
#include "File.h"

namespace BMF
{

class FileReader final
    : public BMF::ItemReader<BMF::File>
{
public:
    FileReader();
    ~FileReader();
    
    void read_item(BMF::File& item) override;
};

}

#endif // FILE_READER_H_
