#include "Backuper.h"
#include "FileReader.h"

BMF::Backuper::Backuper(const std::string& backup_dir
        , BMF::IFileSystem& fs
        , BMF::Backuper::Items&& items_to_backup)
    : _fs{fs}
    , _backup_dir{backup_dir}
    , _items_to_backup{std::move(items_to_backup)}
{
}

const std::string&  BMF::Backuper::backup_dir() const
{
    return _backup_dir;
}

const BMF::Backuper::Items&  BMF::Backuper::items_to_backup() const
{
    return _items_to_backup;
}

void BMF::Backuper::run()
{
    if (!backup_dir_exist() && !create_backup_dir())
    {
        throw std::string{"Error : Could not create backup dir"};
    }
    else if (!is_backup_dir_usable())
    {
        throw std::string{"Error : backup dir unusable"};
    }
    
    for (const auto& item : _items_to_backup)
    {
        const auto& item_type = item->type();
        auto f = _item_reader_factory.create_reader(item_type);
        f->read_item(*item.get());
    }
        
}

bool BMF::Backuper::backup_dir_exist() const
{
    return _fs.dir_exist(_backup_dir);
}

bool BMF::Backuper::create_backup_dir() const
{
    return _fs.create_dir(_backup_dir);
}

bool BMF::Backuper::is_backup_dir_usable() const
{
    return _fs.is_dir(_backup_dir);
}

