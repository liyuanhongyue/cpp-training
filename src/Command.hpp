#pragma once
#include "PoseHandler.hpp"

namespace adas
{
class ICommand
{
public:
    virtual ~ICommand(void) = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};
class MoveCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.IsFastMode()) {
            poseHandler.Move();
            poseHandler.Fast();  // 清除快速模式
        }
        poseHandler.Move();
    }
};
class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.IsFastMode()) {
            poseHandler.Move();
            poseHandler.Fast();  // 清除快速模式
        }
        poseHandler.TurnLeft();
    }
};
class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.IsFastMode()) {
            poseHandler.Move();
            poseHandler.Fast();  // 清除快速模式
        }
        poseHandler.TurnRight();
    }
};
class FastCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        poseHandler.Fast();
    }
};
}  // namespace adas