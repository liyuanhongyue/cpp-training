#include "ExecutorImpl.hpp"

#include <memory>

#include "Command.hpp"

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
        std::unique_ptr<ICommand> command;

        if (cmd == 'M') {
            command = std::make_unique<MoveCommand>();
        } else if (cmd == 'L') {
            command = std::make_unique<TurnLeftCommand>();
        } else if (cmd == 'R') {
            command = std::make_unique<TurnRightCommand>();
        } else if (cmd == 'F') {
            command = std::make_unique<FastCommand>();
        }

        if (command) {
            command->DoOperate(*this);
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

void ExecutorImpl::Fast() noexcept
{
    fast_mode = !fast_mode;
}

bool ExecutorImpl::IsFastMode() const noexcept
{
    return fast_mode;
}

}  // namespace adas
