#pragma once
#include "concepts.hpp"
#include <numbers>




    // used as conversion from degrees (input param) to radians (returned output)
constexpr long double operator"" _deg_to_rad ( long double deg )
{
    long double radians = deg * std::numbers::pi_v<long double> / 180;
    return radians;
}
