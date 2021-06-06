//#include "testlib.hpp"
#define RUN_CATCH
#ifdef RUN_CATCH

//#include "test.hpp"
#include <catch2/catch.hpp>
//#include <philip/philip.hpp>
//#include <ph_file/file.hpp>
#include <ph_concepts/concepts.hpp>
#include <ph_concepts/platform.hpp>
//#include <ranges>

auto tes (Darwin auto d)
{
    
}

using namespace std;


struct A
{
    int i;
    A  operator*();//{return *this;}
    A& operator= (A const&) = delete;
//    A& operator= (A&&){}
};

template <typename T>
concept AA = requires (T& t1, T& t2)
{
    {static_cast <T&> (*t1)} -> Reference;
};




//template <typename T, template <typename, typename> typename U>
//concept Dereferenceable = std::is_same_v <int, U> and requires (T& t1)
//{
////    {reinterpret_cast <T&> (*t1)} -> Reference;
//    true;
//};
//
template <typename T>
struct AAA
{

};

TEST_CASE ("app")
{
//    auto values = std::vector{9, 2, 5, 3, 4};
//    std::ranges::sort(values);
//    char* source = ph::file::read (TEST_FILE);
//    free (source);
    cout << "hi" << endl;
}


/**
 
 
 
 */

#endif
