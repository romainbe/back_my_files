#ifndef BMF_H
#define BMF_H

#include <string>
#include <vector>
#include <memory>

#include "Item.h"
#include "IFileSystem.h"
#include "ItemReaderFactory.hpp"

namespace BMF
{

class Backuper final
{
public:
    using Items = std::vector<std::unique_ptr<Item>>;
    
public:
    Backuper(const std::string& backup_dir
        , BMF::IFileSystem& fs
        , Items&& items_to_backup);
    ~Backuper() = default;

    const std::string&  backup_dir() const;
    const Items&  items_to_backup() const;
    
    void run();

private:
    BMF::IFileSystem& _fs;

    bool backup_dir_exist() const;
    bool create_backup_dir() const;
    bool is_backup_dir_usable() const;

private:
    const std::string   _backup_dir;
    Items  _items_to_backup;
    ItemReaderFactory   _item_reader_factory;
};

}

#endif // BMF_H
