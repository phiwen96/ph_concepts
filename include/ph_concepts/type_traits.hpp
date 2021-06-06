#pragma once
#include "common.hpp"
#include "concepts.hpp"
/**
 A C++ type trait is an interface (functions, types, values), parametrized on a type:
 
 Traits class: A class used in place of template parameters. As a class, it aggregates
 useful types and constants; as a template, it provides an avenue for that “extra level of
 indirection” that solves all software problems.
 */


//template <typename T>
//concept Boolean = requires () {
//    {T::value} -> same_as <bool>;
////    {typename T::value_type} -> same_as <int>;
//};

struct AA
{
    
    static inline bool value = 10;
    
};

//static_assert (concepts::type_traits::Boolean <AA>, "");





//template <typename T>
//concept Type_trait

