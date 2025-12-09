#include "Data.hpp"

namespace adas
{
// Point Class Implementation
Point::Point(const int x, const int y) noexcept : x(x), y(y)
{
}
Point::Point(const Point& other) noexcept : x(other.x), y(other.y)
{
}
Point& Point::operator=(const Point& other) noexcept
{
    x = other.x;
    y = other.y;
    return *this;
}
Point& Point::operator+=(const Point& other) noexcept
{
    x += other.x;
    y += other.y;
    return *this;
}
int Point::GetX(void) const noexcept
{
    return x;
}
int Point::GetY(void) const noexcept
{
    return y;
}

// Direction Class Implementation
static const Direction directions[] = {
    Direction('E', 0),
    Direction('S', 1),
    Direction('W', 2),
    Direction('N', 3),
};
Direction::Direction(const char& dir, const unsigned& idx) noexcept : heading(dir), index(idx)
{
}
const Direction& Direction::GetDirection(const char& dir) noexcept
{
    for (const auto& direction : directions) {
        if (direction.GetHeading() == dir) {
            return direction;
        }
    }
    return directions[3];  // 默认返回'N'
}
const Point& Direction::Move(void) const noexcept
{
    static const Point move_points[] = {
        Point(1, 0),   // E
        Point(0, -1),  // S
        Point(-1, 0),  // W
        Point(0, 1),   // N
    };
    return move_points[index];
}
const char Direction::GetHeading(void) const noexcept
{
    return heading;
}
const Direction& Direction::LeftOne(void) const noexcept
{
    const unsigned new_index = (index + 3) % 4;  // 左转即逆时针转90度
    return directions[new_index];
}
const Direction& Direction::RightOne(void) const noexcept
{
    const unsigned new_index = (index + 1) % 4;  // 右转即顺时针转90度
    return directions[new_index];
}
}  // namespace adas