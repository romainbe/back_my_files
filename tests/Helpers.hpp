#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <gmock/gmock.h>

#include "Item.h"

namespace TESTS_HELPERS_
{

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

}

#endif // HELPERS_HPP
