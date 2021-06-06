#include "concepts.hpp"
#include "common.hpp"





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













