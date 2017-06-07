#include <gmock/gmock.h>

#include "Item.h"

class MockItem final : public BMF::Item
{
public:
    MockItem()
        : BMF::Item{ {
              { "k1", "v1" },
              { "k2", "v2" },
          } }
    {
    }

    MOCK_CONST_METHOD0(type, const std::string&());
    MOCK_CONST_METHOD0(description, const std::string&());
    MOCK_CONST_METHOD0(is_conf_valid, bool());
};

using ::testing::ReturnRef;

TEST(item_test, type)
{
    const static std::string name{ "item" };

    MockItem m;

    EXPECT_CALL(m, type()).WillOnce(ReturnRef(name));
    ASSERT_EQ(name, m.type());
}

TEST(item_test, description)
{
    const static std::string descr{ "some text" };

    MockItem m;

    EXPECT_CALL(m, description()).WillOnce(ReturnRef(descr));
    ASSERT_EQ(descr, m.description());
}

TEST(item_conf_test, description)
{
    MockItem m;

    ASSERT_EQ(2, static_cast<int>(m.conf().size()));
    ASSERT_EQ("v1", m.conf().at("k1"));
    ASSERT_EQ("v2", m.conf().at("k2"));
}