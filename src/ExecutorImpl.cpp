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
    std::unordered_map<char, std::function<void(PoseHandler&)>> command_map;
    command_map['M'] = MoveCommand().operate;
    command_map['L'] = TurnLeftCommand().operate;
    command_map['R'] = TurnRightCommand().operate;
    command_map['F'] = FastCommand().operate;
    for (const auto cmd : commands) {
        const auto it = command_map.find(cmd);
        if (it != command_map.end()) {
            it->second(pose_handler);
        }
    }
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose_handler.QueryPose();
}

}  // namespace adas
