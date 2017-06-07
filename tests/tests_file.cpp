#include <gmock/gmock.h>

#include "File.h"

TEST(file, type)
{
    BMF::File f{ {} };

    ASSERT_EQ("file", f.type());
}

TEST(file, description)
{
    BMF::File f{ {} };

    ASSERT_EQ("file", f.type());
}

TEST(is_conf_valid, valid_conf)
{
     BMF::File f{ {
         {"directory", "/foo/bar/"},
         {"filename", "example.txt"},
    } };
    
    ASSERT_TRUE(f.is_conf_valid());
}

TEST(is_conf_valid, invalid_conf)
{
    BMF::File f{ {} };
    
    ASSERT_FALSE(f.is_conf_valid());
}

TEST(is_conf_valid, invalid_conf_no_input_dir)
{
    BMF::File f{ {
         {"filename", "example.txt"},
    } };

    ASSERT_FALSE(f.is_conf_valid());
}

TEST(is_conf_valid, invalid_conf_no_input_file)
{
    BMF::File f{ {
         {"directory", "/foo/bar/"},
    } };
    
    ASSERT_FALSE(f.is_conf_valid());
}
