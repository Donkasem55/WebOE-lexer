#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& in) {
    std::string result = "";
    for (const auto& s : in) {
        result += s;
    }
    return result;
}