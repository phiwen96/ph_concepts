#pragma once
#include "concepts.hpp"
#include "common.hpp"

namespace ph::data_structures
{
    
    
    
    
    template <typename T>
    concept Array = requires ()
    {
        true;
    };
    
    template <typename T>
    concept Linked_list = requires (typename T::element_type&& element, T* t)
    {
        {T::empty_list ()} -> convertible_to <T*>;
        {T::make_list (std::move (element), t)} -> convertible_to <T*>;
        T::make_list ( std::move (element), T::empty_list ());
        {T::first ()} -> convertible_to <typename T::element_type>;
//        {T::rest ()} -> convertible_to <typename T::rest_type>;
//        true;
    };
    
    
    
    
    auto first (Linked_list auto&& l) -> Iterator auto
    requires requires
    {
        true;
    }
    {
        true;
    }
    
    template <typename T>
    concept Stack = requires ()
    {
        true;
    };
    
    template <typename T>
    concept Queue = requires ()
    {
        true;
    };
    
    template <typename T>
    concept Binary_search_tree = requires ()
    {
        true;
    };
    
    template <typename T>
    concept Heap_tree = requires ()
    {
        true;
    };
    
    template <typename T>
    concept Hash_table = requires ()
    {
        true;
    };
    
    template <typename T>
    concept Graph = requires ()
    {
        true;
    };
}





namespace ph::data_structures
{
    struct hej{
     
    };
}
