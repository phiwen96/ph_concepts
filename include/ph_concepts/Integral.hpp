#pragma once

#include "Bool.hpp"
#include "Char.hpp"
#include "Integer.hpp"
namespace ph
{
    inline namespace concepts {
template <typename T>
concept Integral = Bool <T> or Char <T> or Integer <T>;
}
}


