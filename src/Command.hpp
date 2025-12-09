#pragma once
#include <functional>

#include "PoseHandler.hpp"

namespace adas
{
class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMode()) {
            if (poseHandler.IsReverseMode()) {
                poseHandler.Backward();
            } else {
                poseHandler.Move();
            }
            // poseHandler.Fast();  // 清除快速模式
        }
        if (poseHandler.IsReverseMode()) {
            poseHandler.Backward();

        } else {
            poseHandler.Move();
        }
    }
};
class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMode()) {
            if (poseHandler.IsReverseMode()) {
                poseHandler.Backward();
            } else {
                poseHandler.Move();
            }
            // poseHandler.Fast();  // 清除快速模式
        }
        if (poseHandler.IsReverseMode()) {
            poseHandler.TurnRight();
        } else {
            poseHandler.TurnLeft();
        }
    }
};
class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMode()) {
            if (poseHandler.IsReverseMode()) {
                poseHandler.Backward();
            } else {
                poseHandler.Move();
            }
            // poseHandler.Fast();  // 清除快速模式
        }
        if (poseHandler.IsReverseMode()) {
            poseHandler.TurnLeft();
        } else {
            poseHandler.TurnRight();
        }
    }
};
class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};
class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};
}  // namespace adas