#pragma once
//import std.core;
//import std.string;
//import std.iostream;
//	#include <iostream>
//import utility;

import <iostream>;
//#include <utility>
#include <iostream>



template <typename... T>
struct Lambdas : T...
{
    constexpr Lambdas (T&&... t) noexcept : T {t}...
    {
        
    }
};






namespace ph::concepts {
    
//    template <typename T>
//    concept Constexpr = requires (T& t)
//    {
//        requires (__builtin_choose_expr (t.size (), true, false));
//    };
    
    using std::swap;
    
    template <typename T>
    concept Swappable = requires (T& a, T& b)
    {
        swap (a, b);
    };
    
    template <typename T>
    concept DefaultConstructible = std::is_default_constructible_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept MoveConstructible = std::is_move_constructible_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept CopyConstructible = std::is_copy_constructible_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept MoveAssignable = std::is_move_assignable_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept CopyAssignable = std::is_copy_assignable_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept Destructible = std::is_destructible_v <T> and requires ()
    {
        true;
    };
    
    
    
    
    
    template <typename T>
    concept TriviallyDefaultConstructible = std::is_trivially_default_constructible_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept TriviallyMoveConstructible = std::is_trivially_move_constructible_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept TriviallyCopyConstructible = std::is_trivially_copy_constructible_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept TriviallyMoveAssignable = std::is_trivially_move_assignable_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept TriviallyCopyAssignable = std::is_trivially_copy_assignable_v <T> and requires ()
    {
        true;
    };
    
    template <typename T>
    concept TriviallyDestructible = std::is_trivially_destructible_v <T> and requires ()
    {
        true;
    };
    
    
    
    
    
    template <typename T, typename U>
    concept convertible_to = requires (T& t)
    {
        (U) t;
    };
    
    template <typename T, typename U>
    concept same_as = std::is_same_v <T, U>;
        
#define SAME_AS(type) std::is_same_v <type, std::decay_t <T>>
#define CONVERTIBLE_2(type) convertible_to <type, std::decay_t <T>>

#define cexpr inline static constexpr
    
    
    
    
    
    
    
    
    
    template <typename T>
    concept Bool = SAME_AS (bool);
        
    
    
    
    
    
    
    
    
        
    template <typename T>
    concept Char =
    SAME_AS (char)
    or SAME_AS (signed char)
    or SAME_AS (unsigned char)
    or SAME_AS (char16_t)
    or SAME_AS (char32_t)
    or SAME_AS (wchar_t);
    
    
    
    
    
    
    template <typename T>
    concept Pointer = std::is_pointer_v <T>;
    
    
    
    
    
    template <typename T>
    concept Floating = SAME_AS (float) or SAME_AS (double) or SAME_AS (long double);

    
    
    
    
	template <typename T>
    concept Signed = SAME_AS (short)
    or SAME_AS (short int)
    or SAME_AS (signed short)
    or SAME_AS (signed short int)
    or SAME_AS (int)
    or SAME_AS (signed)
    or SAME_AS (signed int)
    or SAME_AS (long)
    or SAME_AS (long int)
    or SAME_AS (signed long)
    or SAME_AS (signed long int)
    or SAME_AS (long long)
    or SAME_AS (long long int)
    or SAME_AS (signed long long)
    or SAME_AS (signed long long int);


template <typename T>
concept Unsigned = SAME_AS (unsigned short)
    or SAME_AS (unsigned short int)
    or SAME_AS (unsigned)
    or SAME_AS (unsigned int)
    or SAME_AS (unsigned long)
    or SAME_AS (unsigned long int)
    or SAME_AS (unsigned long long)
    or SAME_AS (unsigned long long int);

    template <typename T>
    concept Function = std::is_function_v <std::decay_t <T>>;
        
    template <typename T>
    concept Void = std::is_same_v <void, T>;
    
    template <typename T>
    concept Integer = SAME_AS (short)
        or SAME_AS (short int)
        or SAME_AS (signed short)
        or SAME_AS (signed short int)
        or SAME_AS (int)
        or SAME_AS (signed)
        or SAME_AS (signed int)
        or SAME_AS (long)
        or SAME_AS (long int)
        or SAME_AS (signed long)
        or SAME_AS (signed long int)
        or SAME_AS (long long)
        or SAME_AS (long long int)
        or SAME_AS (signed long long)
        or SAME_AS (signed long long int)
        or SAME_AS (unsigned short)
        or SAME_AS (unsigned short int)
        or SAME_AS (unsigned)
        or SAME_AS (unsigned int)
        or SAME_AS (unsigned long)
        or SAME_AS (unsigned long int)
        or SAME_AS (unsigned long long)
        or SAME_AS (unsigned long long int);
    
    template <typename T>
    concept Arithmetic = Floating <T>
        or Integer <T>
        or Char <T>;
        
    template <typename T>
    concept Fundamental = Void <T>
        or Arithmetic <T>
        or Bool <T>
        or std::is_same_v <std::nullptr_t, T>;
    
    template <typename T>
    concept Integral = Bool <T> or Char <T> or Integer <T>;
    
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
    concept Size = std::is_convertible_v <std::decay_t <T>, std::size_t>;
    
    template <typename T>
    concept Reference = std::is_reference_v <T>;
    
    
    template <typename T>
    concept Comparable = requires (T& a, T& b)
    {
        {a == b} -> Bool;
        {a != b} -> Bool;
    };
    
    template <typename T>
    concept Container =
        DefaultConstructible <T> and
        MoveConstructible <T> and
        Destructible <T> and
        Swappable <T> and
        Comparable <T> and
    
    requires (T& t)
    {
        {t [0]} -> Reference;
    };
    


}

namespace ph::string
{
    
 
    
    
    
    using namespace ph::concepts;
    
        auto size = Lambdas
        {
            [] (auto&& t) noexcept -> ph::concepts::Size auto
            requires convertible_to <decltype (t), char const*>
            {
                return strlen (t);
            },
            
            [] (auto&& t) constexpr noexcept -> Size auto
            requires requires (){
                {t.size ()} -> Size;
            }
            {
                return t.size ();
            },
            
            
            [] <Char T, Size auto n> (T [n]) constexpr noexcept -> Size auto
            {
                return n;
            },
            
            [] <Char T, Size auto n> (T (&) [n]) constexpr noexcept -> Size auto
            {
                return n;
            },
            
            [] <Char T, Size auto n> (T (&t) []) constexpr noexcept -> Size auto
            {
                strlen (t);
            },
            
            [] <Char T> (T* t) constexpr noexcept -> Size auto
            {
                strlen (t);
            }
        };
    
    auto data = Lambdas
    {
        [] (char const* t) noexcept -> Pointer auto
        {
            return (char*) t;
        },
        
        [] (auto&& t) constexpr noexcept -> Pointer auto
        requires requires (){
            {t.data ()} -> Pointer;
        }
        {
            return t.data ();
        },
        
        
        [] <Char T, Size auto n> (T (t)[n]) constexpr noexcept -> Pointer auto
        {
            return t;
        },
        
        [] <Char T, Size auto n> (T (&t) [n]) constexpr noexcept -> Pointer auto
        {
            return t;
        },
        
        [] <Char T, Size auto n> (T (&t) []) constexpr noexcept -> Pointer auto
        {
            return t;
        }
    };

        auto c_str = Lambdas
        {
            [] (auto&& t) constexpr noexcept -> char const*
            requires requires ()
            {
                (char const*) t;
            }
            {
                return t;
            },
            
            [] (auto&& t) constexpr noexcept -> char const*
            requires requires ()
            {
                {t.c_str ()} -> convertible_to <char const*>;
            }
            {
                return t.c_str ();
            }
        };
    
}
    
    




namespace ph::concepts
{
    
    
    template <typename T>
    concept String = requires (T& A, T& B)
    {
        {A [0]} -> Reference;
        {A [0]} -> Char;
        ph::string::size (A);
        ph::string::c_str (A);
//        requires requires ()
//        {
//            A = B;
////            A += B;
//            {A == B} -> Bool;
//            {A != B} -> Bool;
//        };
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
    
    
    constexpr auto begin (auto&& x) -> Iterator auto
    requires requires {
        {x.begin ()} noexcept -> Iterator;
    }
    {
        return x.begin ();
    }
    
    
    constexpr auto end (auto&& x) -> Iterator auto
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
        return p + strlen (p);
    }
    
    template <typename T, typename... U>
    concept Range = requires (T& t)
    {
        requires (sizeof... (U) == 0);
        {std::end (t)} -> Iterator;
        {std::begin (t)} -> Iterator;
        
    } or requires (T& t)
    {
        requires (sizeof... (U) == 1);
        {*std::begin (t)} -> convertible_to <std::tuple_element_t <0, std::tuple <U...>>>;
        {*std::end (t)} -> convertible_to <std::tuple_element_t <0, std::tuple <U...>>>;
    } or String <T>;
        
    
    static_assert (Range <std::string>, "");
    
//    static_assert (Range <char const*>, "");
        
        
        
    template <typename T>
    concept Number = Integer <T> or Floating <T>;
        
        
        
        template <typename T>
        concept Constant = std::is_const_v <std::remove_reference_t <T>>;
        
        
        
        
        
        
     
        
        
        
        

        
        
        template<typename T>
        constexpr T pi{3.1415926535897932385};
        


        
        
        
        
        
        
        
        
        auto len (Range auto const& r) -> Size auto
        {
            return static_cast <size_t> (ph::concepts::end (r) - ph::concepts::begin (r));
        }
        
    //    constexpr auto len (auto&&... a) -> Size auto
    //    {
    //        return sizeof... (a);
    //    }
         
        
    //    template <typename T>
    //    concept String = Range <char> and requires (T& str)
    //    {
    //        true;//        true;
    //    };
    //    template <typename T>
    //    concept Number = std::is_integral_v <T>;

        
        
        
        
        template <typename key>
        concept Key = requires (key& k_0, key& k_1)
        {
            {k_0 == k_1} -> Char;
        };
        
        
        
        
        
        /**
         A Container is an object used to store other objects and taking care of the
         management of the memory used by the objects it contains.
         */
    //    template <typename C, typename... U>
    //    concept Container = Range <C> and requires (C& c, size_t i)
    //    {
    //        same_as <std::decay_t <decltype (c[19])>, <#typename B#>>
    //        true;
    //    };
        
        
        
        
        
        
        
     
        
        template <typename T>
        concept Token = requires ()
        {
            true;
        };
        
        
        
        
      
        
        
        
    //    template <typename
        
        
        template <typename T>
        struct Get
        {
            
        };
        
        template <typename T, size_t N>
        struct Get <T [N]>
        {
            
        };
        
        template <Range R>
        struct Get <R>
        {
            
        };
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
            //template
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        template <typename T>
        concept Type_information = requires () {
                /// Type traits that return information about a type as a boolean or an integer value.
            {T::value} -> same_as <bool>;
                //    {typename T::value_type} -> same_as <int>;
        };
        
        
        
        template <typename T>
        concept Type_transformation = requires () {
                /// Type traits that return a new type
            {T::value} -> same_as <bool>;
                //    {typename T::value_type} -> same_as <int>;
        };
        
        
        
        template <char c>
        concept is_digit = requires {requires (c >= '0' and c <= '9');};
        
        
        
        
        
        
        
        
            //struct copy_constructible
            //{
            //
            //};
        
        
        

        
        template <typename T>
        concept Incrementable = requires (T& t)
        {
            t++;
            ++t;
        };
        
        template <typename T>
        concept Decrementable = requires (T& t)
        {
            t--;
            --t;
        };
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        template <typename T>
        concept Class = std::is_class_v <std::decay_t <T>>;
        
        
    //    template <typename T>
    //    concept Object = Fundamental <T> or Class <T> or requires ()
    //    {
    //        requires (false);
    //    };
        
        
        
        template <typename T>
        concept Rvalue_reference = std::is_rvalue_reference_v <T>;
        
        template <typename T>
        concept Lvalue_reference = std::is_lvalue_reference_v <T>;
        
        
        
        template <typename T>
        concept Dereferenceable = requires (T& t1, T& t2)
        {
            {reinterpret_cast <T&> (*t1)} -> Reference;
        };
        
            //template<typename T>
            //concept Map =
            //std::same_as<T, std::map<typename T::key_type, typename T::mapped_type, typename T::key_compare, typename T::allocator_type>> ||
            //std::same_as<T, std::unordered_map<typename T::key_type, typename T::mapped_type, typename T::hasher, typename T::key_equal, typename T::allocator_type>>;
        
        
        
        
        
        template <template <typename...> class Template, typename Class>
        struct is_instantiation : std::false_type {};
        
        template <template <typename...> class Template, typename... Args>
        struct is_instantiation <Template, Template <Args...>> : std::true_type {};
        
        template <typename Class, template <typename...> class Template>
        concept is_instantiation_of = is_instantiation <Template, Class>::value;
        
            //template <typename T>
            //concept map_type =
            //is_instantiation_of<T, std::map> || is_instantiation_of<T, std::unordered_map>;
        
        
            //auto map_copy (map_type auto const& a) -> map_type auto
            //{
            //    return a;
            //}
        
            //template <is_instantiation_of <std::map> T>
            //auto ordered_map_copy (T const& a) -> T
            //{
            //    return a;
            //}
        
        
        
        
        
        
        
        
        
        
        
        
        
        template <typename T>
        concept Default_constructible = requires ()
        {
            T {};
        };
        
        template <typename T>
        concept Copy_constructible = requires (T const& a)
        {
            T {a};
        };
        
        template <typename T>
        concept Move_constructible = requires (T && a)
        {
            T {std::move (a)};
        };
        
        template <typename T>
        concept Copy_assignable = requires (T& a, T const& b)
        {
            a = b;
        };
        
        template <typename T>
        concept Move_assignable = requires (T& a, T&& b)
        {
            a = std::move (b);
        };
        

        
        template <typename T>
        concept Lexer = requires (T& t)
        {
            true;
        };
        
        
        
        
        
        
        
        
        template <typename T>
        concept Grammar = requires ()
        {
            
            typename T::non_terminal_symbols_type;
            typename T::terminal_symbols_type;
            typename T::start_symbol_type;
            true;
        };
        
        
    
}





#define operator Operator

namespace ph::operators::bitwise {

    template <typename T>
    concept And = requires ()
    {
        true;
    };
}
#undef operator





    //library code
    namespace B { //library name the user knows
        inline namespace A { //ABI version the user doesn't know about
            template<class T> class myclass{int a;};
        }
    }

    // user code
    namespace B { //user thinks the library uses this namespace
        template<> class myclass<int> {};
    }







constexpr long double operator"" _deg_to_rad ( long double deg )
{
    long double radians; // = deg * std::numbers::pi_v<long double> / 180;
    return radians;
}





template <typename T, typename... U>
union uni
{
    T t;
    uni <U...> rest;
    
    constexpr uni (auto&& e) noexcept
    requires requires () {T {forward (e)};}
    : t {forward (e)}
    {
        
    }
    
    
//    constexpr uni (auto&& e) noexcept
//    requires (... or std::is_constructible_v <U, decltype (e)>)
//    : rest {std::forward <decltype (e)> (e)}
//    {
//
//    }
    
    constexpr uni () noexcept
    requires (std::is_trivially_default_constructible_v<T>)
    = default;
    
    
    constexpr uni () noexcept
    requires (not std::is_trivially_default_constructible_v<T>)
    : t {}
    {
        
    }
    
    ~uni () noexcept
    requires (not std::is_trivially_destructible_v<T>)
    {
        
    }

};

template <typename T>
union uni <T>
{
    T t;
    
    constexpr uni (auto&& e) requires requires () {T {forward (e)};}
    {
        
    }
    
    constexpr uni () requires (std::is_trivially_default_constructible_v<T>) = default;
    
    
    constexpr uni () requires (not std::is_trivially_default_constructible_v<T>)
    {
        
    }
    
    ~uni () requires (not std::is_trivially_destructible_v<T>)
    {
        
    }
};




    



    
    
//    static_assert (Collection <int>, "");
    
    
    
    
 




//template <typename T>
//struct Type
//{
//    using value_type = T;
//
//
//};

//template <typename T>
//constexpr auto type = Type <T> {};

    
//template <int>
//auto allocate ();

//template <0>
//Pointer auto allocate ()

auto sizeoof (auto... t)
{
    return sizeof... (t);
}

template <typename T>
struct collection
{
    using type = T;
//    cexpr bool dynamic = N == 0;
    
    collection (T t...) noexcept
    {
        
        m_size = sizeoof (t);
        std::cout << m_size << std::endl;
//        m_begin = (type*) malloc (m_size * sizeof (T));
    }
    
    
    
//    auto operator += (type&&) noexcept requires (dynamic)
//    {
//        return *this;
//    }
    
private:
    type* m_begin;
    std::size_t m_size;
};


    
namespace ph::collections
{
    using namespace ph::concepts;
    
    
    

    template <typename T>
    concept Collection = same_as <T, int[]>;
    
    template <typename T>
    struct bounds
    {
        int i = __builtin_choose_expr (2+3, 0, 1);
        int k;
        int j = true;
    };
    

    
    template <typename T, std::size_t N>
    struct bounds <T [N]>
    {
        cexpr std::size_t value = N;
    };
    
    template <typename T, std::size_t N>
    struct bounds <T (&) [N]>
    {
        cexpr std::size_t value = N;
    };
    
    template <typename T>
    struct bounds <T []>
    {
        
    };
    
    template <typename T>
    struct bounds <T (&) []>
    {

    };
    
    template <typename T>
    struct bounds <T*>
    {
        [[no_unique_address]] int i;
        
    };
    
//    void list(int* n)
    
//    template <typename T>
//    struct bounds <T*>
//    {
//
//    };
    
    
    
    
    

//    template <typename T>
//    concept Bounded = Collection <T> and requires (T t)
//    {
//        {t.size ()};
//    };
//
//
//    template <typename T>
//    concept Numbers = Collection <T> and requires ()
//    {
//        true;
//    };


}
