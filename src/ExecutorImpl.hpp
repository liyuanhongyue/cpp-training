#pragma once
#include "Executor.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl(void) override = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

    void Execute(const std::string& commands) noexcept override;
    Pose QueryPose(void) const noexcept override;

private:
    Pose pose;
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;

    class MoveCommand final
    {
    public:
        void DoOperate(ExecutorImpl& executor) noexcept
        {
            executor.Move();
        }
    };
    class TurnLeftCommand final
    {
    public:
        void DoOperate(ExecutorImpl& executor) noexcept
        {
            executor.TurnLeft();
        }
    };
    class TurnRightCommand final
    {
    public:
        void DoOperate(ExecutorImpl& executor) noexcept
        {
            executor.TurnRight();
        }
    };
};
}  // namespace adas