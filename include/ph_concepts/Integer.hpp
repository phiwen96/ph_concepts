#pragma once

#define SAME_AS(type) std::is_same_v <type, std::decay_t <T>>
namespace ph
{
    inline namespace concepts {
template <typename T>
concept Integer = SAME_AS (short)
    or SAME_AS (short int)
    or SAME_AS (signed short)
    or SAME_AS (signed short int)
    or SAME_AS (int)
    or SAME_AS (signed)
    or SAME_AS (signed int)
    or SAME_AS (long)
    or SAME_AS (long int)
    or SAME_AS (signed long)
    or SAME_AS (signed long int)
    or SAME_AS (long long)
    or SAME_AS (long long int)
    or SAME_AS (signed long long)
    or SAME_AS (signed long long int)
    or SAME_AS (unsigned short)
    or SAME_AS (unsigned short int)
    or SAME_AS (unsigned)
    or SAME_AS (unsigned int)
    or SAME_AS (unsigned long)
    or SAME_AS (unsigned long int)
    or SAME_AS (unsigned long long)
    or SAME_AS (unsigned long long int);
}
}
#undef SAME_AS
