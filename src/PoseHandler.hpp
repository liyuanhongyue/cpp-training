#pragma once
#include "Executor.hpp"

namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFastMode(void) const noexcept;
    Pose QueryPose(void) const noexcept;

private:
    Pose pose;
    bool fast_mode{false};
};
}  // namespace adas