#pragma once
#include "concepts.hpp"
#include "common.hpp"

#define forward(x) std::forward <decltype (x)> (x)
#define declval(T) std::declval <T> ()
#define decay(T) std::decay_t <T>

namespace ph::typeinfo
{
    template <typename T>
    using add_pointer = T*;
    
    template<typename T>
    struct plain_array; // primary template
    template<typename T, std::size_t SZ>
    struct plain_array<T[SZ]> // partial specialization for arrays of known bounds
    {
    static void print() { std::cout << "print() for T[" << SZ << "]\n"; }
    };
    template<typename T, std::size_t SZ>
    struct plain_array<T(&)[SZ]> // partial spec. for references to arrays of known bounds
    {
    static void print() { std::cout << "print() for T(&)[" << SZ << "]\n"; }
    };
    template<typename T>
    struct plain_array<T[]> // partial specialization for arrays of unknown bounds
    {
    static void print() { std::cout << "print() for T[]\n"; }
    };
    template<typename T>
    struct plain_array<T(&)[]> // partial spec. for references to arrays of unknown bounds
    {
    static void print() { std::cout << "print() for T(&)[]\n"; }
    };
    template<typename T>
    struct plain_array<T*> // partial specialization for pointers
    {
    static void print() { std::cout << "print() for T*\n"; }
    };
    
    
    
    
//    template <ph::Range R>
    namespace range
    {
        template <ph::Range R>
        using iterator_type = decltype (ph::begin (declval (R)));
        
        template <ph::Range R>
        using access_type = decltype (*ph::begin (declval (R)));
        
        template <ph::Range R>
        using element_type = decay (access_type <R>);
    };
    
    
    
//    template <ph::Range R>
//    using element_access_type_of = typename range <R>::access_type;
    
//    template <ph::Range R>
//    using element_type_of = typename range <R>::element_type;
    
//    template <ph::Iterator I>
//    using element_type_of = typename range <I>::element_type;
    
//    template <ph::Range R>
//    using iterator_type_of = typename range <R>::iterator_type;
    
    
    
}

#undef forward
#undef declval
#undef decay
