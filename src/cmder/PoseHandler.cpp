#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.direction))
{
}
void PoseHandler::Forward() noexcept
{
    point += facing->Move();
}
void PoseHandler::Backward() noexcept
{
    point -= facing->Move();
}
void PoseHandler::TurnLeft() noexcept
{
    facing = &facing->LeftOne();
}
void PoseHandler::TurnRight() noexcept
{
    facing = &facing->RightOne();
}
void PoseHandler::ReverseTurnLeft() noexcept
{
    facing = &facing->RightOne();
}
void PoseHandler::ReverseTurnRight() noexcept
{
    facing = &facing->LeftOne();
}
void PoseHandler::Fast() noexcept
{
    fast_mode = !fast_mode;
}
bool PoseHandler::IsFastMode() const noexcept
{
    return fast_mode;
}
void PoseHandler::Reverse() noexcept
{
    reverse_mode = !reverse_mode;
}
bool PoseHandler::IsReverseMode() const noexcept
{
    return reverse_mode;
}
Pose PoseHandler::QueryPose() const noexcept
{
    return Pose{point.GetX(), point.GetY(), facing->GetHeading()};
}
}  // namespace adas