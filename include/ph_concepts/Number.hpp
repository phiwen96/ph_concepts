#pragma once
#include "Integer.hpp"
#include "Floating.hpp"

#define SAME_AS(type) std::is_same_v <type, std::decay_t <T>>
namespace ph::concepts {
template <typename T>
concept Number = Integer <T> or Floating <T>;
}

#undef SAME_AS

