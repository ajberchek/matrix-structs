#pragma once

#include <string>

#include <json.hpp>

#include "mtx/identifiers.hpp"

namespace mtx {
namespace responses {

//Used to represent empty responses
struct Null{};

void
from_json(const nlohmann::json &obj, Null &response);

}
}
