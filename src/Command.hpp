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
            poseHandler.Move();
            poseHandler.Fast();  // 清除快速模式
        }
        poseHandler.Move();
    };
};
class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMode()) {
            poseHandler.Move();
            poseHandler.Fast();  // 清除快速模式
        }
        poseHandler.TurnLeft();
    };
};
class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFastMode()) {
            poseHandler.Move();
            poseHandler.Fast();  // 清除快速模式
        }
        poseHandler.TurnRight();
    };
};
class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    };
};
}  // namespace adas