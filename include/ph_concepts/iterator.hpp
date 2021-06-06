#pragma once

#include "concepts.hpp"
//#include "platform.asm"
//#include "ph_concepts/platform.asm"
//#include <ph_concepts/platform.asm>

template <typename T>
concept Iterator = requires (T& a, T& b)
{
    T {a};
    a = b;
    a++;
    ++a;
};



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
    {a > b} -> same_as <bool>;
    {a < b} -> same_as <bool>;
    {a >= b} -> same_as <bool>;
    {a <= b} -> same_as <bool>;
    a += b;
    a -= b;
};





namespace {

//template <typename>
//struct _Iterator;
//
//template <Class T>
//struct _Iterator <T>
//{
//
//};

//template <Pointer T>
//struct _Iterator <T>
//{
//
//};









}



template <typename T>
concept Iterable = requires (T& t)
{
    requires requires ()
    {
        {t.begin ()} -> Iterator;
        {t.end ()} -> Iterator;
        
    }
//    or requires ()
//    {
//        {t.begin ()} -> Pointer;
//        {t.end ()} -> Pointer;
//
//    }
    or requires (size_t& i)
    {
        t [i];
        {t.size ()} -> convertible_to <size_t>;
    };
};
