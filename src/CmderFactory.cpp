#include "CmderFactory.hpp"

namespace adas
{
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept
{
    CmderList cmders;
    for (const auto cmd : commands) {
        const auto it = command_map.find(cmd);
        if (it != command_map.end()) {
            cmders.push_back(it->second);
        }
    }
    return cmders;
}
}  // namespace adas