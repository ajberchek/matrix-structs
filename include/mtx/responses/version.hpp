#pragma once

#include <json.hpp>
#include <regex>
#include <string>

using json = nlohmann::json;

static std::regex VERSION_REGEX("r(\\d+)\\.(\\d+)\\.(\\d+)");

namespace mtx {
namespace responses {

struct Versions
{
        std::vector<std::string> versions;
};

inline void
from_json(const json &obj, Versions &response)
{
        response.versions = obj.at("versions").get<std::vector<std::string>>();

        for (auto &version : response.versions) {
                if (!std::regex_match(version, VERSION_REGEX))
                        throw std::invalid_argument(version + ": invalid version");
        }
}
}
}
