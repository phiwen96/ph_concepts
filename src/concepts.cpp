#include "concepts.hpp"

static_assert (same_as_any_of <int, double, float, int>, "");
static_assert (not same_as_any_of <int, double, float, std::string>, "");
//static_assert (Iterable <std::vector <int>>, "");


struct iter
{
    using reference = int&;
    using value_type = int;
    int i;
    int* begin(){return &i;}
    int* end(){return &i;}
    auto& operator++(){return *this;}
    auto& operator++(int){return *this;}
    auto& operator--(){return *this;}
    auto& operator--(int){return *this;}
    auto operator*(){return i;}
};



//static_assert (Iterator <iter>, "");






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
