#pragma once

namespace ph
{
    inline namespace concepts {
template <typename T>
concept Pointer = std::is_pointer_v <T>;
}
}
