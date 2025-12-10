#include "ExecutorImpl.hpp"

#include <algorithm>
#include <functional>
#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Singleton.hpp"

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
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const auto& cmder) { cmder(pose_handler).DoOperate(pose_handler); });
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose_handler.QueryPose();
}

}  // namespace adas
