#include "PoseEq.hpp"
#include <tuple>

namespace adas
{
    bool operator==(const Pose& lhs, const Pose& rhs)
    {
        // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了， std::tie提高代码可读性
        return std::tie(lhs.x, lhs.y, lhs.direction) == std::tie(rhs.x, rhs.y, rhs.direction);
    }
}  // namespace adas