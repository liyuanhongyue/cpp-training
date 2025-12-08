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
        } else if (cmd == 'L') {
            if (pose.direction == 'E') {
                pose.direction = 'N';

            } else if (pose.direction == 'N') {
                pose.direction = 'W';

            } else if (pose.direction == 'W') {
                pose.direction = 'S';

            } else if (pose.direction == 'S') {
                pose.direction = 'E';
            }
        } else if (cmd == 'R') {
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
    }
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose;
}

}  // namespace adas
