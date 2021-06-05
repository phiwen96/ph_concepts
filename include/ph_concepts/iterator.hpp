#pragma once

#include "concepts.hpp"
//#include "platform.asm"
//#include "ph_concepts/platform.asm"
//#include <ph_concepts/platform.asm>

template <typename T>
concept Iterator =
    Copy_constructible <T> and
    Copy_assignable <T> and
    Destructible <T> and
    Incrementable <T>;

template <typename T>
concept Input_iterator = Iterator <T> and requires ()
{
    true;
};


template <typename T>
concept Output_iterator = requires ()
{
    true;
};

template <typename T>
concept Forward_iterator = requires ()
{
    true;
};

template <typename T>
concept Bidirectional_iterator = requires ()
{
    true;
};

template <typename T>
concept Random_access_iterator = requires ()
{
    true;
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
