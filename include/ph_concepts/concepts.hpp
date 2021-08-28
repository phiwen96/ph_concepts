#pragma once
    //#include <map>
    //#include <unordered_map>
    //#include "common.hpp"
    //using namespace std;

#include "Arithmetic.hpp"
#include "Bool.hpp"
#include "Char.hpp"
#include "Floating.hpp"
#include "Fundamental.hpp"
#include "Iterator.hpp"
#include "Integer.hpp"
#include "Integral.hpp"
#include "Number.hpp"
#include "Range.hpp"
#include "Signed.hpp"
#include "Unsigned.hpp"
#include "Void.hpp"
#include "Pointer.hpp"
#include "Size.hpp"
#include "Function.hpp"
#include "Reference.hpp"
#include "Array.hpp"
#include "String.hpp"
#include "Size.hpp"
#include "StringHelper.hpp"

#include "common.hpp"


namespace ph::concepts {
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
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
        concept Destructible = std::is_destructible_v <T>;
        
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




