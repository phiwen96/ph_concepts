#pragma once
#include "Floating.hpp"
#include "Integer.hpp"
#include "Char.hpp"

namespace ph
{
    inline namespace concepts
    {

    template <typename T>
    concept Arithmetic = Floating <T>
        or Integer <T>
        or Char <T>;
    }
}

