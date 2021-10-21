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






struct Lhs
{
    
};

constexpr auto sub = Lhs {};

auto operator < (String auto, Lhs)
{
    return Lhs {};
}

auto operator > (Lhs, int)
{
    cout << ">" << endl;

    return 2;
}





//auto operator new(size_t size) -> void* {
// void* p = std::malloc(size);
// std::cout << "allocated " << size << " byte(s)\n";
// return p;
//}

//auto operator delete(void* p) noexcept -> void {
// std::cout << "deleted memory\n";
// return std::free(p);
//}

//auto operator new[](size_t size) -> void* {
// void* p = std::malloc(size);
// std::cout << "allocated " << size << " byte(s) with new[]\n";
// return p;
//}

//auto operator delete[](void* p) noexcept -> void {
// std::cout << "deleted memory with delete[]\n";
// return std::free(p);
//}

template <int>
struct vec
{
    constexpr auto size ()
    {
        return 4;
    }
};

template <>
struct vec <1>
{
    auto size ()
    {
        return 6;
    }
};

int ii (int i)
{
    return i;
}

TEST_CASE ()
{
    int aa[] = {1, 2, 3};
//    Collection auto numbers = {1, 3, 4};
    vec <0> v0;
    vec <1> v1;
    
    using std::cout, std::endl;
    
//    cout <<
//    Constexpr auto aaa = vec <0> {};
//    cout << ph::string::size ("hej") << endl;
}
