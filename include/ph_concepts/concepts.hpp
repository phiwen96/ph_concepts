#pragma once
//using namespace std;


template <typename T, typename... U>
concept same_as_any_of = (std::is_same_v <T, U> or ...);




template <char c>
concept is_digit = requires {requires (c >= '0' and c <= '9');};

template <typename A, typename B>
concept same_as = requires (){
    requires std::is_same_v <A, B>;
};


template <typename A, typename B>
concept convertible_to = requires (){
    requires std::is_convertible_v <A, B>;
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
concept String = requires (T& str)
{    
    requires (std::is_same_v <typename T::value_type, char>);
    
    requires requires (size_t& i)
    {
        {str [i]} -> same_as <char&>;
    };
    
    {str.size ()} -> convertible_to <size_t>;
    
    
    
};







