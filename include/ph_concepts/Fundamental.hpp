#pragma once
#include "Void.hpp"
#include "Arithmetic.hpp"
#include "Bool.hpp"
namespace ph
{
    inline namespace concepts {
template <typename T>
concept Fundamental = Void <T>
    or Arithmetic <T>
    or Bool <T>
    or std::is_same_v <std::nullptr_t, T>;
}
}
