#pragma once
#include <functional>

#include "ActionGroup.hpp"
#include "PoseHandler.hpp"

namespace adas
{
class MoveCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, CarType carType) const noexcept
    {
        ActionGroup actionGroup;
        int count = 1;
        const auto action =
            poseHandler.IsReverseMode() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.IsFastMode()) {
            count++;
        }
        if (carType == CarType::SportsCar) {
            count *= 2;
        }
        for (int i = 0; i < count; ++i) {
            actionGroup.PushAction(action);
        }
        return actionGroup;
    }
};
class TurnLeftCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, CarType carType) const noexcept
    {
        ActionGroup actionGroup;
        if (poseHandler.IsFastMode()) {
            const auto action =
                poseHandler.IsReverseMode() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }
        const auto action =
            poseHandler.IsReverseMode() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TRUNLEFT_ACTION;
        actionGroup.PushAction(action);
        if (carType == CarType::SportsCar) {
            const auto action =
                poseHandler.IsReverseMode() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }
        return actionGroup;
    }
};
class TurnRightCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, CarType carType) const noexcept
    {
        ActionGroup actionGroup;
        if (poseHandler.IsFastMode()) {
            const auto action =
                poseHandler.IsReverseMode() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }
        const auto action =
            poseHandler.IsReverseMode() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
        actionGroup.PushAction(action);
        if (carType == CarType::SportsCar) {
            const auto action =
                poseHandler.IsReverseMode() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }
        return actionGroup;
    }
};
class FastCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, CarType carType) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_FAST_ACTION);
        return actionGroup;
    }
};
class ReverseCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, CarType carType) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
        return actionGroup;
    }
};
class TurnRoundCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler, CarType carType) const noexcept
    {
        if (poseHandler.IsReverseMode()) {
            return ActionGroup();
        }
        if (poseHandler.IsFastMode()) {
            return ActionGroup({ActionType::FORWARD_1_STEP_ACTION, ActionType::TRUNLEFT_ACTION,
                                ActionType::FORWARD_1_STEP_ACTION, ActionType::TRUNLEFT_ACTION});
        }
        return ActionGroup(
            {ActionType::TRUNLEFT_ACTION, ActionType::FORWARD_1_STEP_ACTION, ActionType::TRUNLEFT_ACTION});
    }
};
}  // namespace adas