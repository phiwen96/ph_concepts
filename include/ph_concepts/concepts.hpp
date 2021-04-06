#pragma once
using namespace std;
#include <experimental/coroutine>
using namespace experimental;


 

namespace ph::concepts{

template <class T, class U>
concept convertible = is_convertible_v <T, U>;

template <class T, class U>
concept same = std::is_same_v <T, U>;

template <class T>
concept copy_constructible = std::is_copy_constructible_v <T>;

template <class T>
concept move_constructible = std::is_move_constructible_v <T>;

template <class T>
concept copy_assignable = requires (T& t1, T const& t2) {
    t1 = t2;
};

template <class T>
concept move_assignable = requires (T& t1, T&& t2) {
    t1 = (T&&) t2;
};







//template <typename T>
//concept coroutine = move_constructible <T> and not copy_constructible <T> and requires (typename T::promise_type promise) {
//
//    {promise.get_return_object()} -> convertible<T>;
//    promise.initial_suspend();
//    {promise.final_suspend()} noexcept;
////    {promise.return_void()} -> same <void>;
//    {promise.unhandled_exception()} -> same <void>;
//};



//template <typename T>
//concept coroutine_awaitable = requires (T t) {
//    {t.await_ready()} noexcept -> same <bool>;
//    {t.await_suspend()} noexcept -> same <void>;
//    {t.await_resume()} noexcept -> same <void>;
//};
//
//template <typename T>
//concept fast_awaitable = requires (T const t) {
//    {t.await_ready()} noexcept -> same <bool>;
//    t.await_ready() == true;
//    {t.await_suspend()} noexcept -> same <void>;
//    {t.await_resume()} noexcept -> same <void>;
//};


//template <class T>
//concept is_lazy_coroutine = coroutine <T> and requires (typename T::promise_type p) {
//    {p.initial_suspend ()} -> convertible <suspend_always>;
//
//    /**
//     user of the coroutine gets
//     a chance to read the value
//     when "yield 6"
//     */
//    {p.yield_value (declval <typename T::value_type> ())} -> convertible <suspend_always>;
//};



static_assert(same <int, double> == false, "");
static_assert(same <int, int> == true, "");
static_assert(convertible <int, double> == true, "");
static_assert(convertible <double, int> == true, "");
static_assert(convertible <int, string> == false, "");



namespace coroutines
{
//template <typename T>
//concept awaitable = requires (T t)
//{
//
//}
template <typename promise>
concept promise_type = requires (promise t)
{
    typename promise::interface_type;
    typename promise::value_type;
    typename promise::awaitable::initial_type;
    typename promise::awaitable::final_type;
    typename promise::awaitable::transform_type;
};

namespace awaitables
{
template <typename T>
concept initial_type = requires (T t)
{
    {t.await_ready ()} -> same <bool>;
    {t.await_suspend (coroutine_handle<>{})};
    {t.await_resume ()};
};

template <typename T>
concept final_type = requires (T t)
{
    {t.await_ready ()} noexcept -> same <bool>;
    {t.await_suspend (coroutine_handle<>{})} noexcept;
    {t.await_resume ()} noexcept;
};
template <typename T>
concept transform_type = requires (T t)
{
    {t.await_ready ()} -> same <bool>;
    {t.await_suspend (coroutine_handle<>{})} -> convertible <coroutine_handle <>>;
    {t.await_resume ()};
};
}


template <typename interface>
concept interface_type = requires (interface i)
{
    typename interface::interface_type;
    typename interface::value_type;
    typename interface::awaitable::initial_type;
    typename interface::awaitable::final_type;
    typename interface::awaitable::template transform_type <>;
    
//    requires awaitable::initial_type <typename interface::awaitable::initial_type>;
//    requires awaitable::final_type <typename interface::awaitable::final_type>;
//    requires awaitable::transform_type <typename interface::awaitable::transform_type>;
    
};

}



} // ph::concepts
