#include "ExecutorImpl.hpp"

#include <algorithm>
#include <functional>
#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
Executor* Executor::New(const Pose& pose, const CarType& car_type) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose, car_type);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, const CarType& car_type) noexcept : pose_handler(pose), car_type(car_type)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const auto& cmder) { cmder(pose_handler, car_type).DoOperate(pose_handler); });
}

Pose ExecutorImpl::QueryPose(void) const noexcept
{
    return pose_handler.QueryPose();
}

}  // namespace adas
