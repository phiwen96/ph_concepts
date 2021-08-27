//#pragma once
//#include "concepts.hpp"
////#include "Size.hpp"
//
//
//namespace ph::memory
//{
////    template <bool mallocator = true>
//    auto const allocate = []<bool mallocator = true>(Size auto n_bytes) -> Pointer auto
//    {
//        if constexpr (mallocator)
//        {
//            return std::malloc (n_bytes);
//
//        } else
//        {
//            return ::operator new (n_bytes);
//        }
//    };
//
//    auto const deallocate = []<bool mallocator = true>(Pointer auto p) -> void
//    {
//        if constexpr (mallocator)
//        {
//            std::free (p);
//
//        } else
//        {
//            ::operator delete (p);
//        }
//    };
//
//    auto const reallocate = [](Pointer auto p, Size auto n_bytes) -> Pointer auto
//    {
//        return std::realloc (p, n_bytes);
//    };
//}
//
//
//
//
//
//
//
//namespace ph
//{
//    template <typename T>
//    concept Can_allocate = requires (T&& lambda, size_t n)
//    {
//        {lambda (n)} -> Pointer;
//    };
//    static_assert (Can_allocate <decltype (memory::allocate)>, "");
//
//    template <typename T>
//    concept Can_deallocate = requires (T&& lambda, void* p)
//    {
//        {lambda (p)};
//    };
//    static_assert (Can_deallocate <decltype (memory::deallocate)>, "");
//
//    template <typename T>
//    concept Can_reallocate = requires (T&& lambda, void* pointer, size_t n_bytes)
//    {
//        {lambda (pointer, n_bytes)} -> Pointer;
//    };
//    static_assert (Can_reallocate <decltype (memory::reallocate)>, "");
//
//
//    template <typename T>
//    concept Allocator = Can_allocate <T> and Can_deallocate <T> and Can_reallocate <T> and requires ()
//    {
//        true;
//    };
//}
