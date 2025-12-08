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
    }
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose;
}

}  // namespace adas
