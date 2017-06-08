#include <gmock/gmock.h>
#include "Helpers.hpp"

#include "ItemReader.hpp"

using namespace BMF;

namespace ItemReader_tests
{

class ItemReaderMock final : public ItemReader
{
public:
    MOCK_METHOD1(read_item_, void(Item&));
};  


TEST(ItemReaderBehaviour, read_item__called_on_valid_conf)
{
    TESTS_HELPERS_::MockItem item;
    ItemReaderMock reader;

    using ::testing::Return;
    using ::testing::_;

    EXPECT_CALL(item, is_conf_valid())
        .Times(1)
        .WillOnce(Return(true));
    
    EXPECT_CALL(reader, read_item_(_))
        .Times(1);
    
    reader.read_item(item);
}    
 
TEST(ItemReaderBehaviour, read_item__not_called_on_invalid_conf)
{
    TESTS_HELPERS_::MockItem item;
    ItemReaderMock reader;
    
    using ::testing::Return;
    using ::testing::_;

    EXPECT_CALL(item, is_conf_valid())
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_CALL(reader, read_item_(_))
        .Times(0);

    reader.read_item(item);
}

}   