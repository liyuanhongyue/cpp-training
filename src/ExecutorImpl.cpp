#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

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
    std::unordered_map<char, std::unique_ptr<ICommand>> command_map;
    command_map['M'] = std::make_unique<MoveCommand>();
    command_map['L'] = std::make_unique<TurnLeftCommand>();
    command_map['R'] = std::make_unique<TurnRightCommand>();
    command_map['F'] = std::make_unique<FastCommand>();

    for (const auto cmd : commands) {
        const auto it = command_map.find(cmd);
        if (it != command_map.end()) {
            it->second->DoOperate(pose_handler);
        }
    }
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose_handler.QueryPose();
}

}  // namespace adas
