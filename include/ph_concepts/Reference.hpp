#pragma once

namespace ph::concepts {
template <typename T>
concept Reference = std::is_reference_v <T>;
}

