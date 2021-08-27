#pragma once

namespace ph::concepts {
template <typename T>
concept Size = std::is_convertible_v <std::decay_t <T>, std::size_t>;
}

