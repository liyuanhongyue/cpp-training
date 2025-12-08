#include "ExecutorImpl.hpp"

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
            Move();
        } else if (cmd == 'L') {
            TurnLeft();
        } else if (cmd == 'R') {
            TurnRight();
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
