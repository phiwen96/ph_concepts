#pragma once

namespace ph::concepts {
template <typename T>
concept Void = std::is_same_v <void, T>;
}

