#pragma once

namespace ph
{
    inline namespace concepts {
template <typename T>
concept Function = std::is_function_v <std::decay_t <T>>;
}
}
