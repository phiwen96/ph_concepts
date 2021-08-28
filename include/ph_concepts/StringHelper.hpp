#pragma once
#include <ph_concepts/Char.hpp>
#include <ph_concepts/Size.hpp>

#define cexpr inline static constexpr


namespace ph::concepts
{
    
   
    
    template <typename>
    struct StringHelper
    {
        cexpr bool is_string = false;
        cexpr bool known_bounds = false;
        cexpr bool dynamic = false;
    };
    
    template <Char T, Size auto n>
    struct StringHelper <T [n]>// partial specialization for arrays of known bounds
    {
        cexpr bool is_string = true;
        cexpr bool known_bounds = true;
        cexpr bool dynamic = false;
        
        static inline constexpr auto size () noexcept -> Size auto
        {
            return n;
        }
    };
    
    template <Char T, Size auto n>
    struct StringHelper <T (&) [n]>// partial spec. for references to arrays of known bounds
    {
        cexpr bool is_string = true;
        cexpr bool known_bounds = true;
        cexpr bool dynamic ()
        {
            return false;
        }
        
        static inline constexpr auto size () noexcept -> Size auto
        {
            return n;
        }
        
    };
    
    template <Char T>
    struct StringHelper <T (&) []> // partial spec. for references to arrays of unknown bounds
    {
        cexpr bool is_string = true;
        cexpr bool known_bounds = false;
        cexpr bool dynamic = true;
    };
    
    template <Char T>
    struct StringHelper <T*> // partial specialization for pointers
    {
        cexpr bool is_string = true;
        cexpr bool known_bounds = false;
        cexpr bool dynamic = true;
        
        static inline constexpr auto size (T* t) noexcept -> Size auto
        {
            return strlen (t);
        }
    };
    
    template <>
    struct StringHelper <std::string> // partial specialization for pointers
    {
        cexpr bool is_string = true;
        cexpr bool known_bounds = true;
        cexpr bool dynamic = true;
        
        static inline constexpr auto size (std::string& s) noexcept -> Size auto
        {
            return s.size ();
        }
    };
    
    template <typename T>
    inline constexpr auto string_helper (T t) noexcept -> StringHelper <T>
    {
        return {};
    }
    
}




#undef cexpr
