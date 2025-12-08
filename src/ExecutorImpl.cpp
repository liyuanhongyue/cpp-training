#include "ExecutorImpl.hpp"

#include <memory>

#include "Command.hpp"

namespace adas
{
Executor* Executor::New(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose_handler(pose)
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
            command->DoOperate(pose_handler);
        }
    }
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose_handler.QueryPose();
}

}  // namespace adas
