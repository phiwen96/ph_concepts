//#include "testlib.hpp"
#define RUN_CATCH
#ifdef RUN_CATCH

//#include "test.hpp"
#include <catch2/catch.hpp>
//#include <philip/philip.hpp>
//#include <ph_file/file.hpp>
#include <ph_concepts/concepts.hpp>
#include <ph_concepts/platform.hpp>
#include <ph_concepts/common.hpp>
#include <ph_concepts/memory.hpp>
#include <ph_concepts/algorithm.hpp>
#include <ph_concepts/uni.hpp>
#include "common.hpp"
#include <cstddef>

struct
{
    std::byte i : 1 {0b0};
    std::byte i2 : 1 {0b0};
} bitfield;



union byte
{
    std::byte i : 8;
    std::byte j : 8;
};

TEST_CASE ("")
{
    byte b0;
    b0.i = {0b11111111};
    cout << std::to_integer <int> (b0.i) << endl;
    cout << std::to_integer <int> (b0.j) << endl;
    b0.j = {0b01111111};
    cout << std::to_integer <int> (b0.i) << endl;
    cout << std::to_integer <int> (b0.j) << endl;
    
//    std::byte b {0b11111111};
    
//    cout << std::to_integer <int> (b) << endl;
    
//    cout << b << endl;
//    cout << sizeof (bitfield) << endl;
//    cout << bitfield.i << endl;
    
    auto v0 = uni <std::string, int, double> {"hej"};
//    cout << v0 << endl;
    auto v1 = uni <std::string, float, std::string> {6.8f};
//    cout << "uni" << endl;
}


#endif
