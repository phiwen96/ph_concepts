#pragma once
//#include "concepts.hpp"
//#include "Array.hpp"
#include "common.hpp"

#define cexpr inline static constexpr



namespace
{
    template<typename T>
    struct type_of_string : std::false_type
    {
        
    };

    template <typename T, size_t SZ>
    struct type_of_string <T [SZ]> : std::true_type// partial specialization for arrays of known bounds
    {
        
    };

    template <typename T, size_t SZ>
    struct type_of_string <T (&) [SZ]> : std::true_type// partial spec. for references to arrays of known bounds
    {
        
    };

    template <typename T>
    struct type_of_string <T (&) []> : std::true_type // partial spec. for references to arrays of unknown bounds
    {
        
    };

    template <typename T>
    struct type_of_string <T*> : std::true_type // partial specialization for pointers
    {
        
    };
}






//template <typename T>
//concept String = requires (T& str)
//{
//    
//    requires requires (size_t& i)
//    {
//        {str [i]} -> Char;
//    };
//    
//    {str.size ()} -> convertible_to <size_t>;
//    
//    
//    
//};



namespace ph::concepts
    {
        template <typename T>
        concept String = /*Range <char>*/type_of_string <T>::value or requires (T& A, T& B, int i)
        {
            {A [i]} -> ph::concepts::convertible_to <char&>;
            //    {B [i]} -> convertible_to <char>;
            {A.size ()} -> convertible_to <std::size_t>;
            true;
        };
    }



#undef cexpr
