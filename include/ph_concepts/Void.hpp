#pragma once

namespace ph
{
    inline namespace concepts {
template <typename T>
concept Void = std::is_same_v <void, T>;
}
}
