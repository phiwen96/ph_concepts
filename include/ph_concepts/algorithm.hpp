#pragma once
#include "concepts.hpp"
#include "iterator.hpp"
#include "common.hpp"
#include "types.hpp"

namespace ph
{
    auto sort (Input_iterator auto begin, Input_iterator auto end) -> void;
    
    
        ///iterating over a sequence
        //auto for_each (Input_iterator auto begin, Input_iterator auto end, decltype ([](int&){}()) fun) -> void;
    
    
    
    
    EAT ({
        function (value_a  value_b) -> new_value
        function (type_a   type_b)  -> new_type
        
    })
    
        /// Iterating over a sequence
        auto for_each (ph::Range auto&& r, auto&& callable) -> void
        requires requires (ph::element_access_type_of <decltype (r)> e) {
            callable (forward (e));
        }
        {
            for (auto&& i : r)
            {
                callable (forward (i));
            }
        }
    
    template <typename T>
    auto transform (ph::Range <T> auto&& source,
                    ph::Range <T> auto&& destination,
                    auto&& callable) -> void
    
                        requires requires //(ph::element_type_of <decltype (source)> e)
                        {
                            true;
//                            {callable (forward (e))} -> convertible_to <element_type_of <decltype (destination)>>;
                        }
    {
        assert (ph::len (source) <= ph::len (destination));
        
        Iterator auto dest = ph::begin (source);
        
        for (auto&& i : source)
        {
            *dest = forward (i);
            ++dest;
        }
    }
    
    
    template <typename T>
    auto contains (ph::Range auto&& r, auto&& element)
    requires requires (element_access_type_of <decltype (r)> e)
    {
        {e == element} -> Boolean;
    }
    {
        for (auto&& i : r)
        {
            if (i == element)
            {
                return true;
            }
        }
        
        return false;
    }
    
    auto count_if (ph::Range auto&& r, auto&& callable) -> Size auto
    requires requires (element_access_type_of <decltype (r)> e) {
        {callable (forward (e))} -> Boolean;
    }
    {
        Size auto res = size_t {0};
        
        for (auto&& i : r)
        {
            if (callable (forward (i)))
            {
                ++res;
            }
        }
        
        return res;
    }
    
    auto count (ph::Range auto&& r, auto&& element) -> Size auto
    requires requires (element_access_type_of <decltype (r)> e) {
        {e == element} -> Boolean;
    }
    {
        Size auto res = size_t {0};
        
        for (auto&& i : r)
        {
            if (i == element)
            {
                ++res;
            }
        }
        
        return res;
    }
    
    auto find (ph::Range auto&& r, auto&& element) -> ph::Iterator auto
    requires requires (element_access_type_of <decltype (r)> i) {
        {i == element} -> Boolean;
    }
    {
        Iterator auto i = ph::begin (r);
        
        for (; i < ph::end (r); ++i)
        {
            if (*i == element)
            {
                break;
            }
        }
        
        return i;
    }
    
    auto find_if (ph::Range auto&& r, auto&& callable) -> ph::Iterator auto
    requires requires (element_access_type_of <decltype (r)> i) {
        {callable (forward (i))} -> Boolean;
    }
    {
        Iterator auto i = ph::begin (r);
        
        for (; i < ph::end (r); ++i)
        {
            if (callable (forward (*i)))
            {
                break;
            }
        }
        
        return i;
    }
    
    
    
    
}

