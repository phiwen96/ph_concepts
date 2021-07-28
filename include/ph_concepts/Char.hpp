#pragma once

#define SAME_AS(type) std::is_same_v <type, std::decay_t <T>>
namespace ph
{
    inline namespace concepts {
template <typename T>
concept Char =
SAME_AS (char)
or SAME_AS (signed char)
or SAME_AS (unsigned char)
or SAME_AS (char16_t)
or SAME_AS (char32_t)
or SAME_AS (wchar_t);
    }
    
}
#undef SAME_AS

