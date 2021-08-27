#include "Range.hpp"

namespace ph::concepts
{
    static_assert (Range <std::string>, "");
    
    static_assert (Range <char const*>, "");
    
}
