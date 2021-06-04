//#include "testlib.hpp"

#ifdef RUN_CATCH

//#include "test.hpp"
#include <catch2/catch.hpp>
#include <philip/philip.hpp>
#include <ph_file/file.hpp>



using namespace std;

TEST_CASE ("app")
{
    char* source = ph::file::read (TEST_FILE);
    free (source);
}




#endif
