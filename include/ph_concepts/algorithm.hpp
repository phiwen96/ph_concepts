#pragma once
#include "concepts.hpp"
#include "iterator.hpp"
#include "common.hpp"

namespace ph::algorithm
{
    auto sort (Input_iterator auto begin, Input_iterator auto end) -> void;
    
    
        ///iterating over a sequence
        //auto for_each (Input_iterator auto begin, Input_iterator auto end, decltype ([](int&){}()) fun) -> void;
    
    
    
    
    EAT ({
        function (value_a  value_b) -> new_value
        function (type_a   type_b)  -> new_type
        
    })
    
    template <typename T>
    auto transform (ph::Range <T> auto&& source, ph::Range <T> auto&& destination, auto&& lambda)
    {
        
    }
    
    
    
    auto contains (ph::Range auto&&)
    {
        
    }
    
    auto count_if (ph::Range auto&&)
    {
        
    }
    
}

