#pragma once

namespace ph::concepts {
template <typename T>
concept Function = std::is_function_v <std::decay_t <T>>;
}

