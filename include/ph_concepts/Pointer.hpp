#pragma once

namespace ph::concepts {
template <typename T>
concept Pointer = std::is_pointer_v <T>;
}

