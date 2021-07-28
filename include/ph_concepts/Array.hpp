#pragma once

//#include "concepts.hpp"

#define cexpr inline static constexpr

namespace ph
{
    inline namespace concepts{
template <typename T>
struct type_of_array
{
    cexpr bool value = false;
};

template <typename T, std::size_t N>
struct type_of_array <T[N]>// partial specialization for arrays of known bounds
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = false;
};

template <typename T, std::size_t N>
struct type_of_array <T(&)[N]>// partial spec. for references to arrays of known bounds
{
    using element_type = T;
    cexpr bool value = true;
    cexpr std::size_t size = N;
    cexpr bool dynamic = false;

};

template <typename T>
struct type_of_array <T[]>// partial specialization for arrays of unknown bounds
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = true;

};

template <typename T>
struct type_of_array <T(&)[]>// partial spec. for references to arrays of unknown bounds
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = true;
};

template <typename T>
struct type_of_array <T*>// partial specialization for pointers
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = true;
};

template <typename T>
struct type_of_array <std::initializer_list <T>>// partial specialization for pointers
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = true;
};

template <typename T, std::size_t N>
struct type_of_array <std::array <T, N>>// partial specialization for pointers
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = false;
};

template <typename T>
struct type_of_array <std::vector <T>>// partial specialization for pointers
{
    using element_type = T;
    cexpr bool value = true;
    cexpr bool dynamic = true;
};

#undef cexpr




template <typename T>
concept Array = type_of_array <T>::value;
}
}
