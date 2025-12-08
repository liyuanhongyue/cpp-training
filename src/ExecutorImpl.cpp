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
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose;
}

}  // namespace adas
