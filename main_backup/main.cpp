#include <iostream>

#include "File.h"
#include "Backuper.h"
#include "FileSystem.h"

int main(int argc, char **argv)
{
    // avoid compilation warning
    (void)argc; (void)argv;
    
    BMF::Backuper::Items  items;
    items.push_back(
        std::make_unique<BMF::File>
            (BMF::File{{
                {"filename", "copy.txt"},
                {"directory", "/home/r0m1/Travail/Code/c++/backup"}
            }}
        ));
    
    
    BMF::FileSystem fs;
    BMF::Backuper    bmf{
        "/home/r0m1/Travail/Code/c++/backup/backups",
        fs, 
        {std::move(items)}
    };

    try {
        bmf.run();
    } catch (...)
    {
        std::cerr << "Unknown catch main" << std::endl;
    }

    return 0;
}
