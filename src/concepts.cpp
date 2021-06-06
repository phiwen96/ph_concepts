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


struct A
{
    int i;
    A &  operator*();
    A& operator= (A const&) = delete;
//    A& operator= (A&&){}
};

//static_assert (Dereferenceable <A>, "");







