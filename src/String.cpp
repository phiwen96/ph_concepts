#include "String.hpp"
namespace concepts{

struct string
{
    using value_type = char;
    char c;
    auto& operator[](int) {return c;}
    auto size () const{return 2;}
    
};

static_assert (String <string>, "");
static_assert (String <std::string>, "");
static_assert (String <std::vector <char>>, "");
}
