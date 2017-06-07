#include <gmock/gmock.h>

#include "File.h"
#include "Backuper.h"

using namespace BMF;

namespace Backuper_tests
{
class FSMock : public BMF::IFileSystem
{
public:
    MOCK_CONST_METHOD1(dir_exist, bool(const std::string&));
    MOCK_CONST_METHOD1(create_dir, bool(const std::string&));
    MOCK_CONST_METHOD1(is_dir, bool(const std::string&));
};

BMF::Backuper& build_backuper(FSMock & m)
{
    BMF::Backuper::Items  items;
   
    static BMF::Backuper   b{
        "path", m, std::move(items)
    };
    return b;
}

}

using namespace Backuper_tests;

TEST(bmf_run, ok_no_throw)
{
    FSMock m;
    
    using ::testing::Return;
    using ::testing::_;
    
    auto& b = build_backuper(m);
    
    EXPECT_CALL(m, dir_exist(_))
        .Times(1)
        .WillOnce(Return(true));
    
    EXPECT_CALL(m, create_dir(_))
        .Times(0);
    
    EXPECT_CALL(m, is_dir(_))
        .Times(1)
        .WillOnce(Return(true));
    
    EXPECT_NO_THROW(b.run());
} 

TEST(bmf_run, ok_no_throw_create_ok)
{
    FSMock m;
    
    using ::testing::Return;
    using ::testing::_;

    auto& b = build_backuper(m);

    EXPECT_CALL(m, dir_exist(_))
        .Times(1)
        .WillOnce(Return(false));
    
    EXPECT_CALL(m, create_dir(_))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(m, is_dir(_))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_NO_THROW(b.run());
} 

TEST(bmf_run, create_fail_throw)
{
    FSMock m;
    
    using ::testing::Return;
    using ::testing::_;

    auto& b = build_backuper(m);

    EXPECT_CALL(m, dir_exist(_))
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_CALL(m, create_dir(_))
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_CALL(m, is_dir(_))
        .Times(0);

    EXPECT_THROW(b.run(), std::string);
} 
    
TEST(bmf_run, unusable_dir_throw_throw)
{
    FSMock m;
    
    using ::testing::Return;
    using ::testing::_;
    
    auto& b = build_backuper(m);
    
    EXPECT_CALL(m, dir_exist(_))
        .Times(1)
        .WillOnce(Return(true));
    
    EXPECT_CALL(m, create_dir(_))
        .Times(0);
    
    EXPECT_CALL(m, is_dir(_))
        .Times(1)
        .WillOnce(Return(false));
    
    EXPECT_THROW(b.run(), std::string);
}
