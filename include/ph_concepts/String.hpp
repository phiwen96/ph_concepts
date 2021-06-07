#pragma once
#include "concepts.hpp"
#include "iterator.hpp"


template <typename T>
concept String = requires (T& str)
{
    
    requires requires (size_t& i)
    {
        {str [i]} -> Char;
    };
    
    {str.size ()} -> convertible_to <size_t>;
    
    
    
};

