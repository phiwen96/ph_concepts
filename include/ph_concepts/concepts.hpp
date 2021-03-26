using namespace std;
using namespace experimental;
namespace ph::concepts{

template <class T, class U>
concept convertible = std::is_convertible_v<T, U>;

template <class T, class U>
concept same = std::is_same_v<T, U>;






template <typename T>
concept coroutine = requires (typename T::promise_type promise) {

    {promise.get_return_object()} -> convertible<T>;
    promise.initial_suspend();
    {promise.final_suspend()} noexcept;
    {promise.return_void()} -> same <void>;
    {promise.unhandled_exception()} -> same <void>;
};

template <typename T>
concept awaitable = requires (T const t) {
    {t.await_ready()} noexcept -> same <bool>;
    {t.await_suspend()} noexcept -> same <void>;
    {t.await_resume()} noexcept -> same <void>;
};











} // ph::concepts
