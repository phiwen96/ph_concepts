#include "concepts.hpp"
#include "common.hpp"

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













