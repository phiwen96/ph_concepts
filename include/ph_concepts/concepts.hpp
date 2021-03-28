using namespace std;
using namespace experimental;


 

namespace ph::concepts{

template <class T, class U>
concept convertible = requires (T t, U u) {//std::is_convertible_v <T, U>;
    {t = u};
};

template <class T, class U>
concept same = std::is_same_v <T, U>;

template <class T>
concept copy_constructible = requires (T const& t) {
    T (t);
};

template <class T>
concept move_constructible = requires (T&& t) {
    T ((T&&) t);
};

template <class T>
concept copy_assignable = requires (T& t1, T const& t2) {
    t1 = t2;
};

template <class T>
concept move_assignable = requires (T& t1, T&& t2) {
    t1 = (T&&) t2;
};







template <typename T>
concept coroutine = move_constructible <T> and not copy_constructible <T> and requires (typename T::promise_type promise) {

    {promise.get_return_object()} -> convertible<T>;
    promise.initial_suspend();
    {promise.final_suspend()} noexcept;
//    {promise.return_void()} -> same <void>;
    {promise.unhandled_exception()} -> same <void>;
};



template <typename T>
concept coroutine_awaitable = requires (T t) {
    {t.await_ready()} noexcept -> same <bool>;
    {t.await_suspend()} noexcept -> same <void>;
    {t.await_resume()} noexcept -> same <void>;
};

template <typename T>
concept fast_awaitable = requires (T const t) {
    {t.await_ready()} noexcept -> same <bool>;
    t.await_ready() == true;
    {t.await_suspend()} noexcept -> same <void>;
    {t.await_resume()} noexcept -> same <void>;
};


template <class T>
concept is_lazy_coroutine = coroutine <T> and requires (typename T::promise_type p) {
    {p.initial_suspend ()} -> convertible <suspend_always>;
    
    /**
     user of the coroutine gets
     a chance to read the value
     when "yield 6"
     */
    {p.yield_value (declval <typename T::value_type> ())} -> convertible <suspend_always>;
};



static_assert(same <int, double> == false, "");
static_assert(same <int, int> == true, "");
static_assert(convertible <int, double> == true, "");
static_assert(convertible <double, int> == true, "");
static_assert(convertible <int, string> == false, "");






} // ph::concepts
