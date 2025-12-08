#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"

namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{
    // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了， std::tie提高代码可读性
    return std::tie(lhs.x, lhs.y, lhs.direction) == std::tie(rhs.x, rhs.y, rhs.direction);
}

// 测试套：测试用例名，清晰地描述了预期行为和测试的条件，更容易理解测试在验证什么
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // 测试遵循了 Arrange-Act-Assert (AAA) 模式，这是提高可读性和维护性的好习惯
    // given
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}));

    // when

    // then
    const Pose target_pose{0, 0, 'E'};

    ASSERT_EQ(target_pose, executor->QueryPose());
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::New());

    // when

    // then
    const Pose target_pose{0, 0, 'N'};

    ASSERT_EQ(target_pose, executor->QueryPose());
}

TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}));

    // when
    executor->Execute("M");

    // then
    const Pose target_pose{1, 0, 'E'};

    ASSERT_EQ(target_pose, executor->QueryPose());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'N'}));

    // when
    executor->Execute("M");

    // then
    const Pose target_pose{0, 1, 'N'};

    ASSERT_EQ(target_pose, executor->QueryPose());
}
TEST(ExecutorTest, should_return_direction_is_W_given_command_is_L_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'W'}));

    // when
    executor->Execute("M");

    // then
    const Pose target_pose{-1, 0, 'W'};

    ASSERT_EQ(target_pose, executor->QueryPose());
}
TEST(ExecutorTest, should_return_direction_is_S_given_command_is_L_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'S'}));

    // when
    executor->Execute("M");

    // then
    const Pose target_pose{0, -1, 'S'};

    ASSERT_EQ(target_pose, executor->QueryPose());
}
}  // namespace adas