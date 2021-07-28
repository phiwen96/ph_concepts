#pragma once
#include "common.hpp"
#include "Iterator.hpp"
#include "String.hpp"
namespace ph
{
    inline namespace concepts {
template <typename T, typename... U>
concept Range = requires (T& t)
{
    requires (sizeof... (U) == 0);
    {std::end (t)} -> Iterator;
    {std::begin (t)} -> Iterator;
    
} or requires (T& t)
{
    requires (sizeof... (U) == 1);
    {*std::begin (t)} -> convertible_to <std::tuple_element_t <0, std::tuple <U...>>>;
    {*std::end (t)} -> convertible_to <std::tuple_element_t <0, std::tuple <U...>>>;
} or String <T>;
}
}
