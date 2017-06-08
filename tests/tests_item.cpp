#include <gmock/gmock.h>

#include "Item.h"
#include "Helpers.hpp"

using ::testing::ReturnRef;

TEST(item_test, type)
{
    const static std::string name{ "item" };

    TESTS_HELPERS_::MockItem m;

    EXPECT_CALL(m, type()).WillOnce(ReturnRef(name));
    ASSERT_EQ(name, m.type());
}

TEST(item_test, description)
{
    const static std::string descr{ "some text" };

    TESTS_HELPERS_::MockItem m;

    EXPECT_CALL(m, description()).WillOnce(ReturnRef(descr));
    ASSERT_EQ(descr, m.description());
}

TEST(item_conf_test, description)
{
    TESTS_HELPERS_::MockItem m;

    ASSERT_EQ(2, static_cast<int>(m.conf().size()));
    ASSERT_EQ("v1", m.conf().at("k1"));
    ASSERT_EQ("v2", m.conf().at("k2"));
}