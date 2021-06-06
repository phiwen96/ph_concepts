#pragma once

#include "common.hpp"
#include "concepts.hpp"


template <typename T>
concept Type = requires (T& t)
{
    T (reinterpret_cast <T const&> (t));
};




