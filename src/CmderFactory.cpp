#include "CmderFactory.hpp"

namespace adas
{
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept
{
    CmderList cmders;
    for (const auto cmd : ParseCommandString(commands)) {
        const auto it = command_map.find(cmd);
        if (it != command_map.end()) {
            cmders.push_back(it->second);
        }
    }
    return cmders;
}
std::string CmderFactory::ParseCommandString(const std::string_view commands) const noexcept
{
    std::string res(commands);
    ReplaceAll(res, "TR", "Z");
    return res;
}
void CmderFactory::ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept
{
    for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length()) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
}
}  // namespace adas