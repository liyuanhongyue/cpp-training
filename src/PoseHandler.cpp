#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
void PoseHandler::Move() noexcept
{
    if (pose.direction == 'E') {
        ++pose.x;
    } else if (pose.direction == 'W') {
        --pose.x;
    } else if (pose.direction == 'N') {
        ++pose.y;
    } else if (pose.direction == 'S') {
        --pose.y;
    }
}
void PoseHandler::TurnLeft() noexcept
{
    if (pose.direction == 'E') {
        pose.direction = 'N';
    } else if (pose.direction == 'N') {
        pose.direction = 'W';
    } else if (pose.direction == 'W') {
        pose.direction = 'S';
    } else if (pose.direction == 'S') {
        pose.direction = 'E';
    }
}
void PoseHandler::TurnRight() noexcept
{
    if (pose.direction == 'E') {
        pose.direction = 'S';
    } else if (pose.direction == 'S') {
        pose.direction = 'W';
    } else if (pose.direction == 'W') {
        pose.direction = 'N';
    } else if (pose.direction == 'N') {
        pose.direction = 'E';
    }
}
void PoseHandler::Fast() noexcept
{
    fast_mode = !fast_mode;
}
bool PoseHandler::IsFastMode() const noexcept
{
    return fast_mode;
}
Pose PoseHandler::QueryPose() const noexcept
{
    return pose;
}
}  // namespace adas