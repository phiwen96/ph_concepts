#include "concepts.hpp"
#include "common.hpp"
#include <catch2/catch.hpp>


#define Concept same_as_any_of
static_assert (Concept <int, char, std::string, int>, "");
static_assert (not Concept <int, char, std::string, double>, "");
#undef Concept

#define Concept same_as
static_assert (Concept <int, int>, "");
static_assert (not Concept <int, double>, "");
static_assert (not Concept <int, double>, "");
#undef Concept

#define Concept convertible_to
static_assert (Concept <int, float>, "");
static_assert (Concept <float, int>, "");
static_assert (Concept <int, double>, "");
static_assert (Concept <double, int>, "");
#undef Concept

#define Concept Reference
static_assert (Concept <int&>, "");
static_assert (Concept <int const&>, "");
static_assert (not Concept <int>, "");
static_assert (not Concept <int*>, "");
#undef Concept

#define Concept Pointer
static_assert (Concept <const char*>, "");
static_assert (Concept <char const*>, "");
static_assert (Concept <int*>, "");
static_assert (Concept <int**>, "");
static_assert (Concept <int const*>, "");
static_assert (Concept <int * const>, "");
static_assert (Concept <int const * const>, "");
static_assert (not Concept <int>, "");
static_assert (not Concept <int&>, "");
#undef Concept

#define Concept Constant
static_assert (not Concept <int&>, "");
static_assert (Concept <int const&>, "");
static_assert (Concept <int const>, "");
static_assert (not Concept <int>, "");
static_assert (not Concept <int*>, "");
#undef Concept

#define Concept Boolean
static_assert (Concept <bool>, "");
static_assert (Concept <bool const>, "");
static_assert (Concept <bool const&>, "");
static_assert (not Concept <int>, "");
static_assert (not Concept <int*>, "");
static_assert (Concept <bool>, "");
static_assert (Concept <bool>, "");


#define Self boolean
struct Self {};
static_assert (not Concept <Self>, "");
#undef Self
struct Self {auto operator== (bool) -> bool;};
static_assert (not Concept <Self>, "");
#undef Concept


#define Concept Unsigned
static_assert (Concept <unsigned>, "");
static_assert (Concept <unsigned const>, "");
static_assert (Concept <unsigned const&>, "");
static_assert (not Concept <int>, "");
static_assert (not Concept <float>, "");
static_assert (Concept <unsigned int>, "");
#undef Concept


#define Concept Signed
static_assert (not Concept <unsigned int>, "");
static_assert (Concept <int>, "");
static_assert (Concept <int const>, "");
static_assert (Concept <int const&>, "");
static_assert (Concept <float>, "");
#undef Concept


#define Concept Number
static_assert (Concept <unsigned int>, "");
static_assert (Concept <int>, "");
static_assert (Concept <int const>, "");
static_assert (Concept <int const&>, "");
static_assert (Concept <float>, "");
static_assert (Concept <uint8_t>, "");
#undef Concept


#define Concept Floating
static_assert (Concept <double>, "");
static_assert (Concept <double const>, "");
static_assert (Concept <double const&>, "");
static_assert (Concept <double&>, "");
static_assert (Concept <float>, "");
static_assert (Concept <float const>, "");
static_assert (Concept <float const&>, "");
static_assert (Concept <float&>, "");
static_assert (not Concept <int>, "");
static_assert (not Concept <int const>, "");
static_assert (not Concept <int const&>, "");
static_assert (not Concept <int&>, "");
#undef Concept

#define Concept Integer
static_assert (Concept <int>, "");
static_assert (Concept <int const>, "");
static_assert (Concept <int const&>, "");
static_assert (Concept <int&>, "");
static_assert (not Concept <double>, "");
static_assert (not Concept <double const>, "");
static_assert (not Concept <double const&>, "");
static_assert (not Concept <double&>, "");
#undef Concept


#define Concept Char
static_assert (Concept <char>, "");
static_assert (Concept <char const>, "");
static_assert (Concept <char16_t const&>, "");
static_assert (Concept <char32_t&>, "");
static_assert (not Concept <char*>, "");
static_assert (not Concept <int>, "");
#undef Concept


#define Self default_constructible
struct Self
{
    Self ();
    Self (Self &&) = delete;
    Self (Self const&) = delete;
    Self& operator= (Self &&) = delete;
    Self& operator= (Self const&) = delete;
};
static_assert (Default_constructible <Self>, "");
static_assert (not Copy_constructible <Self>, "");
static_assert (not Move_constructible <Self>, "");
static_assert (not Copy_assignable <Self>, "");
static_assert (not Move_assignable <Self>, "");
#undef Self




#define Concept Floating
static_assert (Concept <float>, "");
static_assert (Concept <float>, "");

#undef Concept

#define Self copy_constructible
struct Self
{
    Self () = delete;
    Self (Self &&) = delete;
    Self (Self const&);
    Self& operator= (Self &&) = delete;
    Self& operator= (Self const&) = delete;
};
static_assert (not Default_constructible <Self>, "");
static_assert (Copy_constructible <Self>, "");
static_assert (not Move_constructible <Self>, "");
static_assert (not Copy_assignable <Self>, "");
static_assert (not Move_assignable <Self>, "");
#undef Self





#define Self move_constructible
struct Self
{
    Self () = delete;
    Self (Self &&);
    Self (Self const&) = delete;
    Self& operator= (Self &&) = delete;
    Self& operator= (Self const&) = delete;
};
static_assert (not Default_constructible <Self>, "");
static_assert (not Copy_constructible <Self>, "");
static_assert (Move_constructible <Self>, "");
static_assert (not Copy_assignable <Self>, "");
static_assert (not Move_assignable <Self>, "");
#undef Self




#define Self copy_assignable
struct Self
{
    Self () = delete;
    Self (Self &&) = delete;
    Self (Self const&) = delete;
    Self& operator= (Self &&) = delete;
    Self& operator= (Self const&);
};
static_assert (not Default_constructible <Self>, "");
static_assert (not Copy_constructible <Self>, "");
static_assert (not Move_constructible <Self>, "");
static_assert (Copy_assignable <Self>, "");
static_assert (not Move_assignable <Self>, "");
#undef Self




#define Self move_assignable
struct Self
{
    Self () = delete;
    Self (Self &&) = delete;
    Self (Self const&) = delete;
    Self& operator= (Self &&);
    Self& operator= (Self const&) = delete;
};
static_assert (not Default_constructible <Self>, "");
static_assert (not Copy_constructible <Self>, "");
static_assert (not Move_constructible <Self>, "");
static_assert (not Copy_assignable <Self>, "");
static_assert (Move_assignable <Self>, "");
#undef Self



#define Concept Iterator
static_assert (Iterator <int*>, "");
static_assert (Iterator <char const*>, "");
static_assert (Iterator <std::string::iterator>, "");
static_assert (Iterator <std::vector <int>::iterator>, "");
static_assert (Iterator <std::vector <int>::const_iterator>, "");
static_assert (not Iterator <int>, "");
#undef Concept

#define Concept Output_iterator
static_assert (Concept <std::vector<int>::iterator>, "");
static_assert (not Concept <std::vector<int>::const_iterator>, "");
#undef Concept

#define Concept Range
#define Self range
struct Self
{
    char s[10];
    
    auto begin () -> auto*
    {
        return s;
    }
    auto end () -> auto*
    {
        return s + 10;
    }
};
static_assert (Concept <Self>, "");
#undef Self
#undef Concept









TEST_CASE ("begin")
{
    GIVEN ("char []")
    {
        char str[] {"hej"};
//        std::cout << "hej" << std::endl;
//        REQUIRE (*begin (str) == 'h');
//        std::cout << "då" << std::endl;

    }
    
    GIVEN ("char [4]")
    {
        char str[4] {"hej"};
//        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("char const*")
    {
        char const* str {"hej"};
//        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("std::string")
    {
        std::string str {"hej"};
//        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("std::vector")
    {
        std::vector<int> str {1, 2, 3};
        REQUIRE (*begin (str) == 1);
    }
    
    GIVEN ("std::array")
    {
        std::array<int, 3> str {1, 2, 3};
        REQUIRE (*begin (str) == 1);
    }
}

TEST_CASE ("end")
{
    GIVEN ("char []")
    {
        char str[] {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("char [4]")
    {
        char str[4] {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("char const*")
    {
        char const* str {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("int []")
    {
        int str[] {1, 2};
//        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("int [4]")
    {
        int str[4] {1, 2, 3, 4};
//        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("std::string")
    {
        std::string str {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("std::vector")
    {
        std::vector<int> str {1, 2, 3};
        REQUIRE (*(end (str) - 1) == 3);
    }
    
    GIVEN ("std::array")
    {
        std::array<int, 3> str {1, 2, 3};
        REQUIRE (*(end (str) - 1) == 3);
    }
}
