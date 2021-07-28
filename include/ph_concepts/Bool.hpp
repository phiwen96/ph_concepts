#pragma once

#define SAME_AS(type) std::is_same_v <type, std::decay_t <T>>

namespace ph
{
    inline namespace concepts {
template <typename T>
concept Bool = SAME_AS (bool);
    }}
#undef SAME_AS
