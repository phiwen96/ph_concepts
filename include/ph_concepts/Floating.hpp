#pragma once

#define SAME_AS(a) std::is_same_v <a, std::decay_t <T>>
namespace ph::concepts {
template <typename T>
concept Floating = SAME_AS (float) or SAME_AS (double) or SAME_AS (long double);
}


#undef SAME_AS


