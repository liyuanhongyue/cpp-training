#pragma once

namespace adas
{
class Point final
{
private:
    int x;
    int y;

public:
    Point(const int x, const int y) noexcept;
    Point(const Point& other) noexcept;
    Point& operator=(const Point& other) noexcept;
    Point& operator+=(const Point& other) noexcept;
    Point& operator-=(const Point& other) noexcept;

    int GetX(void) const noexcept;
    int GetY(void) const noexcept;
};

class Direction final
{
private:
    char heading;
    unsigned index;

public:
    Direction(const char& dir, const unsigned& idx) noexcept;
    static const Direction& GetDirection(const char& dir) noexcept;
    const char GetHeading(void) const noexcept;

    const Point& Move(void) const noexcept;
    const Direction& LeftOne(void) const noexcept;
    const Direction& RightOne(void) const noexcept;
};
}