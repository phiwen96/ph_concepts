#pragma once

#include "Pointer.hpp"
#include "Reference.hpp"
#include "Char.hpp"
#include "Pointer.hpp"


#define fwd(x) std::forward <decltype (x)> (x)

namespace ph
{
    inline namespace concepts
    {
        template <typename T>
        concept Iterator = Pointer <T> or requires (T& a, T& b)
        {
            T {a};
            a = b;
            a++;
            ++a;
            a == b;
            a != b;
            *a;
        };
        
        
        
        
        template <typename T>
        concept Input_iterator = Iterator <T> and requires (T& t1, T& t2)
        {
            /// Supports read only and step forward (once)
            {*t1};
            ++t1;
            t1++;
            //        t1 == t2;
            //        t1 != t2;
            //        *t1;
        };
        
        
        template <typename T>
        concept Output_iterator = Input_iterator <T> and requires (T& t1, T& t2)
        {
            /// Supports write only and step forward (once)
            *t1 = *t2;
            ++t1;
            t1++;
        };
        
        template <typename T>
        concept Forward_iterator = Output_iterator <T> and requires (T& a, T& b)
        {
            /// Supports read and write and step forward
            true;
        };
        
        template <typename T>
        concept Bidirectional_iterator = Forward_iterator <T> and requires (T& a, T& b)
        {
            /// Supports read, write, step forward, and step backward.
            --a;
            a--;
        };
        
        
        
        template <typename T>
        concept Random_access_iterator = Bidirectional_iterator <T> and requires (T& a, T& b, size_t& i)
        {
            /// : Supports read, write, step forward, step backward, and jump to an arbitrary position in constant time
            {a [i]} -> Reference;
        };
        
        template <typename T>
        concept Contiguous_iterator = Random_access_iterator <T> and requires (T& a, T& b, size_t& i)
        {
            /// The same as random access iterators, but also guarantees that the underlying data is a contiguous block of memory, such as std::string, std::vector, std::array, std::span, and the (rarely used) std::valarray.
            true;
        };
        
        
        
        constexpr auto begin (Pointer auto p) noexcept (true) -> Iterator auto
        {
            return fwd (p);
        };
        
        
        constexpr auto begin (auto&& x) noexcept (x.begin ()) -> Iterator auto
        requires requires {
            {x.begin ()} noexcept -> Iterator;
        }
        {
            return x.begin ();
        }
        
        
        constexpr auto end (auto&& x) noexcept (x.end ()) -> Iterator auto
        requires requires ()
        {
            {x.end ()} -> Iterator;
        }
        {
            return x.end ();
        }
        
        const wchar_t* str = L"爆ぜろリアル！弾けろシナプス！パニッシュメントディス、ワールド！";
        
        constexpr auto end (Char auto* p) noexcept -> Iterator auto
        {
            return p + std::strlen (p);
        }
    }
}


#undef fwd
