#pragma once
//#include "concepts.hpp"
//#include "Array.hpp"
#include "common.hpp"
#include "StringHelper.hpp"
#define cexpr inline static constexpr






namespace ph::concepts
    {
        template <typename T>
        concept String = /*Range <char>*/StringHelper <T>::is_string or requires (T& A, T& B, int i)
        {
            {A [i]} -> ph::concepts::convertible_to <char&>;
            //    {B [i]} -> convertible_to <char>;
            {A.size ()} -> convertible_to <std::size_t>;
            true;
        };
    }


template <typename T>
concept Fittan = requires ()
{
    true;
};

#undef cexpr
