#pragma once

namespace ph
{
    inline namespace concepts {
template <typename T>
concept Reference = std::is_reference_v <T>;
}
}
