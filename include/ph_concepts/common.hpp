#pragma once
namespace ph
{
    
#define EAT(...)
    
    
#define EXPAND(...) __VA_ARGS__
#define cexpr inline static constexpr
//#define forward(x) std::forward <decltype (x)> (x)
//#define declval(T) std::declval <T> ()
//#define decay(T) std::decay_t <T>
}
