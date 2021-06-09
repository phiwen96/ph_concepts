#pragma once
//#include <map>
//#include <unordered_map>
//#include "common.hpp"
    //using namespace std;


template <typename T, typename... U>
concept same_as_any_of = (std::is_same_v <T, U> or ...);

template <typename A, typename B>
concept same_as = requires (){
    requires std::is_same_v <A, B>;
};


template <typename A, typename B>
concept convertible_to = requires (){
    requires std::is_convertible_v <A, B>;
};

template <typename T>
concept Reference = std::is_reference_v <T>;


template <typename T>
concept Pointer = std::is_pointer_v <T>;

template <typename T>
concept Constant = std::is_const_v <std::remove_reference_t <T>>;






template <typename T>
concept Unsigned = std::is_unsigned_v <std::decay_t <T>>;

template <typename T, bool...>
concept Signed = not Unsigned <T>;

template <typename T>
concept Number = (Signed <T> or Unsigned <T>) and requires (T t){
    true;
};


template <typename T>
concept Function = std::is_function_v <std::decay_t <T>>;

#define X(type) same_as <type, std::decay_t <T>> or

#define INTEGER_SIGNED_TYPES \
X (short) \
X (short int) \
X (signed short) \
X (signed short int) \
X (int) \
X (signed) \
X (signed int) \
X (long) \
X (long int) \
X (signed long) \
X (signed long int) \
X (long long) \
X (long long int) \
X (signed long long) \
X (signed long long int)

#define INTEGER_UNSIGNED_TYPES \
X (unsigned short) \
X (unsigned short int) \
X (unsigned) \
X (unsigned int) \
X (unsigned long) \
X (unsigned long int) \
X (unsigned long long) \
X (unsigned long long int)

#define INTEGER_TYPES \
INTEGER_SIGNED_TYPES \
INTEGER_UNSIGNED_TYPES

template <typename T>
concept Integer =
INTEGER_TYPES
false;

#define FLOATING_SIGNED_TYPES \
X (float) \
X (double) \
X (long)

#define FLOATING_TYPES \
FLOATING_SIGNED_TYPES

template <typename T, bool...>
concept Floating =
FLOATING_TYPES
false;

#define BOOL_TYPES \
X (bool)

template <typename T>
concept Boolean =
BOOL_TYPES
false;

#define CHAR_TYPES \
X (char) \
X (signed char) \
X (unsigned char) \
X (char16_t) \
X (char32_t) \
X (wchar_t)

template <typename T>
concept Char =
CHAR_TYPES
false;

#define INTEGRAL_TYPES \
BOOL_TYPES \
CHAR_TYPES \
INTEGER_SIGNED_TYPES \
INTEGER_UNSIGNED_TYPES \

template <typename T>
concept Integral =
INTEGRAL_TYPES
false;


#define ARITHMETIC_TYPES \
FLOATING_TYPES \
INTEGRAL_TYPES \

template <typename T>
concept Arithmentic =
ARITHMETIC_TYPES
false;




#define FUNDAMENTAL_TYPES \
X (void) \
X (std::nullptr_t) \
ARITHMETIC_TYPES

template <typename T>
concept Fundamental =
FUNDAMENTAL_TYPES
false;


template<typename T>
constexpr T pi{3.1415926535897932385};


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
concept Iterator_begin = requires (T& t)
{
    {t.begin ()} -> Iterator;
};
template <typename T>
concept Iterator_end = requires (T& t)
{
    {t.end ()} -> Iterator;
};


template <template <typename> typename T>
concept Not = requires ()
{
    true;
};

//auto begin (Not <Pointer> auto p) -> Iterator auto
//{
//    return forward (p);
//};




    //auto len (void)

//constexpr auto begin (Pointer auto p) -> Iterator auto
//{
//    std::cout << "pointer" << std::endl;
//    return forward (p);
//};

//auto begin (Iterator auto x) -> Iterator auto
//{
//    std::cout << "iterator" << std::endl;
//    return x.begin ();
//}


auto end (auto&& x) -> Iterator auto
requires requires ()
{
#if Debug
    
#else
    
#endif
    
    {x.end ()} -> Iterator;
}
{
    return x.end ();
}


auto end (Char auto* p) -> Iterator auto
{
    return p + std::strlen (p);
}

auto end (auto&& x) -> Iterator auto
requires requires ()
{
    true;
}
{
    return x.end ();
}

    //template <typename T, size_t N>
    //auto end (T (&))

    //template<typename T, std::size_t N>
    //auto end (T (a) [N]) -> Iterator auto
    //{
    //    return forward (a + N);
    //}
    //
    //template<typename T, std::size_t N>
    //auto end (T (&a) [N]) -> Iterator auto
    //{
    //    return forward (a + N);
    //}







template <typename T>
concept Input_iterator = Iterator <T> and requires (T& t1, T& t2)
{
    t1 == t2;
    t1 != t2;
    *t1;
};


template <typename T>
concept Output_iterator = Input_iterator <T> and requires (T& t1, T& t2)
{
    *t1 = *t2;
    *t1++ = *t2;
};

template <typename T>
concept Forward_iterator = Output_iterator <T> and requires (T& a, T& b)
{
    T {};
    a = b;
};

template <typename T>
concept Bidirectional_iterator = Forward_iterator <T> and requires (T& a, T& b)
{
    --a;
    a--;
    *a--;
};

template <typename T>
concept Random_access_iterator = Bidirectional_iterator <T> and requires (T& a, T& b, size_t& n)
{
    {a + n} -> same_as <T>;
    {a - n} -> same_as <T>;
    {a - b} -> same_as <T>;
    {a > b} -> Boolean;
    {a < b} -> Boolean;
    {a >= b} -> Boolean;
    {a <= b} -> Boolean;
    a += b;
    a -= b;
};


/**
 A Container is an object used to store other objects and taking care of the
 management of the memory used by the objects it contains.
 */
template <typename T>
concept Container = requires ()
{
    true;
};

template <typename T>
concept Range = requires ()
{
    requires requires (T& a)
    {
        {a.begin ()} -> Iterator;
        {a.end ()} -> Iterator;
        
    } or requires (T const& a)
    {
        {a.begin ()} -> Iterator;
        {a.end ()} -> Iterator;
    };
};

template <typename T>
struct typeinfo
{
    constexpr auto fundamental () -> bool
    {
        return true;//requires
    }
};

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


template <typename T>
concept Object = Fundamental <T> or Class <T> or requires ()
{
    requires (false);
};



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
concept Type = requires ()
{
    true;
};












