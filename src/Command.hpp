#pragma once
#include "ExecutorImpl.hpp"

namespace adas
{
class ICommand
{
public:
    virtual ~ICommand(void) = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
};
class MoveCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.IsFastMode()) {
            executor.Move();
            executor.Fast();  // 清除快速模式
        }
        executor.Move();
    }
};
class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.IsFastMode()) {
            executor.Move();
            executor.Fast();  // 清除快速模式
        }
        executor.TurnLeft();
    }
};
class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.IsFastMode()) {
            executor.Move();
            executor.Fast();  // 清除快速模式
        }
        executor.TurnRight();
    }
};
class FastCommand final : public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        executor.Fast();
    }
};
}