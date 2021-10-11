#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
using namespace std;
using std::cout, std::endl;
using namespace ph::concepts;

struct const_str
{
    
};


constexpr const_str operator"" _str (char const*, size_t)
{
    return {};
}

TEST_CASE()
{
    constexpr auto s = "hem"_str;
}

TEST_CASE ("Char")
{
    Char auto c0 = char {'h'};
    Char auto c1 = 'h';
    
    REQUIRE (not Char <int>);
}

TEST_CASE ("String")
{
    String auto s0 = std::string {"hej"};
    String auto s1 = "hej";

}










TEST_CASE ()
{
    
    
    
    
    cout << ph::concepts::size ("hej") << endl;
}
