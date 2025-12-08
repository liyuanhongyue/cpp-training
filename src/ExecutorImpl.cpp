#include "ExecutorImpl.hpp"

#include <memory>

namespace adas
{
Executor* Executor::New(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands) {
        if (cmd == 'M') {
            std::unique_ptr<MoveCommand> move_command = std::make_unique<MoveCommand>();
            move_command->DoOperate(*this);
        } else if (cmd == 'L') {
            std::unique_ptr<TurnLeftCommand> turn_left_command = std::make_unique<TurnLeftCommand>();
            turn_left_command->DoOperate(*this);
        } else if (cmd == 'R') {
            std::unique_ptr<TurnRightCommand> turn_right_command = std::make_unique<TurnRightCommand>();
            turn_right_command->DoOperate(*this);
        }
    }
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose;
}

void ExecutorImpl::Move() noexcept
{
    if (pose.direction == 'E') {
        ++pose.x;

    } else if (pose.direction == 'W') {
        --pose.x;

    } else if (pose.direction == 'N') {
        ++pose.y;

    } else if (pose.direction == 'S') {
        --pose.y;
    }
}

void ExecutorImpl::TurnLeft() noexcept
{
    if (pose.direction == 'E') {
        pose.direction = 'N';

    } else if (pose.direction == 'N') {
        pose.direction = 'W';

    } else if (pose.direction == 'W') {
        pose.direction = 'S';

    } else if (pose.direction == 'S') {
        pose.direction = 'E';
    }
}

void ExecutorImpl::TurnRight() noexcept
{
    if (pose.direction == 'E') {
        pose.direction = 'S';

    } else if (pose.direction == 'S') {
        pose.direction = 'W';

    } else if (pose.direction == 'W') {
        pose.direction = 'N';

    } else if (pose.direction == 'N') {
        pose.direction = 'E';
    }
}

}  // namespace adas
