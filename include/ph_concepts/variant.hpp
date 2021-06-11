#pragma once
#include "concepts.hpp"
#include "common.hpp"






template <typename T, typename... U>
union _uni
{
    T t;
    _uni <U...> rest;
    
    constexpr _uni (auto&& e)
    requires requires () {T {forward (e)};}
    : t {forward (e)}
    {
        
    }
    
    
    constexpr _uni (auto&& e)
    requires (... or std::is_constructible_v <U, decltype (e)>)
    : rest {forward (e)}
    {

    }
    
    constexpr _uni ()
    requires (std::is_trivially_default_constructible_v<T>)
    = default;
    
    
    constexpr _uni ()
    requires (not std::is_trivially_default_constructible_v<T>)
    : t {}
    {
        
    }
    
    ~_uni ()
    requires (not std::is_trivially_destructible_v<T>)
    {
        
    }

};

template <typename T>
union _uni <T>
{
    T t;
    
    constexpr _uni (auto&& e) requires requires () {T {forward (e)};}
    {
        
    }
    
    constexpr _uni () requires (std::is_trivially_default_constructible_v<T>) = default;
    
    
    constexpr _uni () requires (not std::is_trivially_default_constructible_v<T>)
    {
        
    }
    
    ~_uni () requires (not std::is_trivially_destructible_v<T>)
    {
        
    }
};





