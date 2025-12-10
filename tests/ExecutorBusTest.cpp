#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
TEST(BusTest, should_return_x_plus_1_when_instruction_is_M_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("M");
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_N_and_x_plus_1_when_instruction_is_L_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("L");
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_S_and_x_plus_1_when_instruction_is_R_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("R");
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_x_plus_2_when_instruction_is_FM_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FM");
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_N_and_x_plus_2_when_instruction_is_FL_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FL");
    const Pose target{2, 0, 'N'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_S_and_x_plus_2_when_instruction_is_FR_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FR");
    const Pose target{2, 0, 'S'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_x_plus_1_when_instruction_is_FFM_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FFM");
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_x_minus_1_when_instruction_is_BM_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("BM");
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_S_and_x_minus_1_when_instruction_is_BL_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("BL");
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_N_and_x_minus_1_when_instruction_is_BR_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("BR");
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_y_plus_1_when_instruction_is_BBM_and_heading_is_N)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'N'}, CarType::Bus));
    executor->Execute("BBM");
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_x_minus_2_when_instruction_is_FBM_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FBM");
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_S_and_x_minus_2_when_instruction_is_FBL_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FBL");
    const Pose target{-2, 0, 'S'};
    ASSERT_EQ(executor->QueryPose(), target);
}
TEST(BusTest, should_return_N_and_x_minus_2_when_instruction_is_FBR_and_heading_is_E)
{
    std::unique_ptr<Executor> executor(Executor::New({0, 0, 'E'}, CarType::Bus));
    executor->Execute("FBR");
    const Pose target{-2, 0, 'N'};
    ASSERT_EQ(executor->QueryPose(), target);
}
}  // namespace adas