#pragma once
#include "Data.hpp"
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
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFastMode(void) const noexcept;
    void Reverse(void) noexcept;
    bool IsReverseMode(void) const noexcept;
    Pose QueryPose(void) const noexcept;

private:
    Point point;
    const Direction* facing;
    bool fast_mode{false};
    bool reverse_mode{false};
};
}  // namespace adas