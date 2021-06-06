#pragma once
#include "concepts.hpp"


template <typename T>
concept String = requires (T& str)
{
    requires (std::is_same_v <typename T::value_type, char>);
    
    requires requires (size_t& i)
    {
        {str [i]} -> same_as <char&>;
    };
    
    {str.size ()} -> convertible_to <size_t>;
    
    
    
};

