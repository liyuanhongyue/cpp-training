#pragma once
#include <functional>

#include "PoseHandler.hpp"

namespace adas
{
class MoveCommand final
{
public:
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
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
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
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
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
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
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
        poseHandler.Fast();
    };
};
}  // namespace adas