#pragma once
#include <string>

namespace adas
{
enum class CarType : uint16_t {
    Normal = 0,
    SportsCar = 1,
    Bus = 2,
};

struct Pose {
    int x;
    int y;
    char direction;
};

class Executor
{
public:
    // Caller should delete *executor when it is no longer needed.
    static Executor* New(const Pose& pose = {0, 0, 'N'}, const CarType& type = CarType::Normal) noexcept;

    Executor(void) = default;
    virtual ~Executor(void) = default;
    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;

    virtual void Execute(const std::string& commands) noexcept = 0;
    virtual Pose QueryPose(void) const noexcept = 0;
};
}  // namespace adas