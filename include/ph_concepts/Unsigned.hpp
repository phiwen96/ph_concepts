#pragma once

#define SAME_AS(type) std::is_same_v <type, std::decay_t <T>>
namespace ph::concepts {
template <typename T>
concept Unsigned = SAME_AS (unsigned short)
    or SAME_AS (unsigned short int)
    or SAME_AS (unsigned)
    or SAME_AS (unsigned int)
    or SAME_AS (unsigned long)
    or SAME_AS (unsigned long int)
    or SAME_AS (unsigned long long)
    or SAME_AS (unsigned long long int);
}

#undef SAME_AS
