#pragma once

#include "concepts.hpp"
#include "common.hpp"


template <typename T, typename... U>
union uni
{
    T t;
    uni <U...> rest;
    
    constexpr uni (auto&& e) noexcept
    requires requires () {T {forward (e)};}
    : t {forward (e)}
    {
        
    }
    
    
    constexpr uni (auto&& e) noexcept
    requires (... or std::is_constructible_v <U, decltype (e)>)
    : rest {std::forward <decltype (e)> (e)}
    {

    }
    
    constexpr uni () noexcept
    requires (std::is_trivially_default_constructible_v<T>)
    = default;
    
    
    constexpr uni () noexcept
    requires (not std::is_trivially_default_constructible_v<T>)
    : t {}
    {
        
    }
    
    ~uni () noexcept
    requires (not std::is_trivially_destructible_v<T>)
    {
        
    }

};

template <typename T>
union uni <T>
{
    T t;
    
    constexpr uni (auto&& e) requires requires () {T {forward (e)};}
    {
        
    }
    
    constexpr uni () requires (std::is_trivially_default_constructible_v<T>) = default;
    
    
    constexpr uni () requires (not std::is_trivially_default_constructible_v<T>)
    {
        
    }
    
    ~uni () requires (not std::is_trivially_destructible_v<T>)
    {
        
    }
};
