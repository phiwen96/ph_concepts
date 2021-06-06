#pragma once
#include <map>
#include <unordered_map>
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

//template <typename T>
//concept Numeric = requires (T& a) {
//    
//};


template <typename T>
concept Boolean = requires (T& t)
{
    static_cast <bool> (t);
};

template <typename T>
concept Unsigned = std::is_unsigned_v <T>;

template <typename T>
concept Signed = not Unsigned <T>;

template <typename T>
concept Float = std::is_floating_point_v <T> and requires (T& a, double& b)
{
    a = b;
    b = a;
    ++a;a++;
    --a;a--;
    
};

template <typename T>
concept Integer = std::is_integral_v <T> and requires ()
{
    true;
};




//template



template <typename T>
concept Number = Signed <T> or Unsigned <T> or

requires (T& a, T& b, float A, int B)
{
    a++;++a;
    a--;--a;
    a = b;
    {a - b} -> convertible_to <float>;
    {a + b} -> convertible_to <float>;
    {a * b} -> convertible_to <float>;
    {a / b} -> convertible_to <float>;
    {a += b} -> Reference;
    {a *= b} -> Reference;
    {a /= b} -> Reference;
    {a < b} -> Boolean;
    {a > b} -> Boolean;
    {a <= b} -> Boolean;
    {a >= b} -> Boolean;
    {a == b} -> Boolean;
    
    
    
    
};










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
concept Pointer = requires (T& t)
{
    requires (std::is_pointer_v <T>);
};



template <typename T>
concept Fundamental = std::is_fundamental_v <T>;

template <typename T>
concept Class = std::is_class_v <T>;


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

template<typename T>
concept Map =
    std::same_as<T, std::map<typename T::key_type, typename T::mapped_type, typename T::key_compare, typename T::allocator_type>> ||
    std::same_as<T, std::unordered_map<typename T::key_type, typename T::mapped_type, typename T::hasher, typename T::key_equal, typename T::allocator_type>>;





template <template <typename...> class Template, typename Class>
struct is_instantiation : std::false_type {};

template <template <typename...> class Template, typename... Args>
struct is_instantiation <Template, Template <Args...>> : std::true_type {};

template <typename Class, template <typename...> class Template>
concept is_instantiation_of = is_instantiation <Template, Class>::value;

template <typename T>
concept map_type =
    is_instantiation_of<T, std::map> || is_instantiation_of<T, std::unordered_map>;


auto map_copy (map_type auto const& a) -> map_type auto
{
    return a;
}

template <is_instantiation_of <std::map> T>
auto ordered_map_copy (T const& a) -> T
{
    return a;
}










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













