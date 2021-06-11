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



TEST_CASE ("")
{
    auto v0 = uni <std::string, int, double> {"hej"};
    auto v1 = uni <std::string, float, std::string> {6.8f};
    cout << "uni" << endl;
}


#endif
