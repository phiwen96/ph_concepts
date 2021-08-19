#pragma once
#include <iostream>
namespace ph
{
    inline namespace concepts {
#define EAT(...)
    
    
#define EXPAND(...) __VA_ARGS__
#define cexpr inline static constexpr
        //#define forward(x) std::forward <decltype (x)> (x)
        //#define declval(T) std::declval <T> ()
        //#define decay(T) std::decay_t <T>
    
    class ScopedTimer {
    public:
        using ClockType = std::chrono::steady_clock;
        ScopedTimer(const char* func)
        : function_name_{func}, start_{ClockType::now()} {}
        ScopedTimer(const ScopedTimer&) = delete;
        ScopedTimer(ScopedTimer&&) = delete;
        auto operator=(const ScopedTimer&) -> ScopedTimer& = delete;
        auto operator=(ScopedTimer&&) -> ScopedTimer& = delete;
        ~ScopedTimer() {
            using namespace std::chrono;
            auto stop = ClockType::now();
            auto duration = (stop - start_);
            auto ms = duration_cast<milliseconds>(duration).count();
            std::cout << ms << " ms " << function_name_ << '\n';
        }
        
    private:
        const char* function_name_{};
        const ClockType::time_point start_{};
    };
    
    
    template <typename T, typename... U>
    concept same_as_any_of = (std::is_same_v <T, U> or ...);

    template <typename A, typename B>
    concept same_as = requires (){
        requires std::is_same_v <A, B>;
    };


    template <typename From, typename To>
    concept convertible_to = requires (){
        requires std::is_convertible_v <From, To>;
    };
    
}

}




