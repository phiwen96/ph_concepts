#define RUN_CATCH
#ifdef RUN_CATCH

#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
//#include <ph_concepts/platform.hpp>
//#include <ph_concepts/common.hpp>
//#include <ph_concepts/memory.hpp>
//#include <ph_concepts/algorithm.hpp>

using namespace ph;

template <typename T>
concept Symbol = requires ()
{
    true;
};











//TEST_CASE ("memory")
//{
//    ph::Pointer auto p = ph::memory::allocate (1);
//    ph::memory::reallocate (p, 10);
//    ph::memory::deallocate (p);
//}





TEST_CASE ("app")
{

//    auto arr = std::vector <int> {3, 4, 5};
//    auto arr2 = std::vector <int>{3, 4, 5};
////    cout << len(arr) << endl;
//    REQUIRE(len(arr) == 3);
//    assert(len(arr) == len(arr2));
//    cout << same_as <element_type_of<decltype(arr)>, int&> << endl;

 
}


/**
 
 
 
 */

#endif
