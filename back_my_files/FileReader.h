#ifndef FILE_READER_H_
#define FILE_READER_H_

#include "ItemReader.hpp"
#include "File.h"

namespace BMF
{

class FileReader final
    : public BMF::ItemReader
{
public:
    FileReader();
    ~FileReader();

private:
    void read_item_(BMF::Item& item) override;
};

}

#endif // FILE_READER_H_
