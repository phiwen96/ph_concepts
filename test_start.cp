#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
#include <ph_concepts/platform.hpp>
#include <ph_concepts/common.hpp>
#include <ph_concepts/memory.hpp>
#include <ph_concepts/algorithm.hpp>
#include <ph_concepts/start.hpp>






namespace ph::app
{
    
    inline namespace concepts
    {
        template <typename T>
        concept Code = requires (T& t)
        {
            true;
        };
    }
    
    
    struct Object
    {
        enum
        {
            TYPE_
        };
        
        union
        {
            
        } value;
        
        
    };
    
    
    
    auto vm (Range auto&& code)
    {
        for (auto instruction = ph::begin (code);
             instruction < ph::end (code);
             ++instruction)
        {
            
        }
    }
    
//    auto vm (Kis 3)
//    {
//
//    }



    TEST_CASE ("")
    {
//        Kis  auto ph::Range auto;
        using namespace std;
        cout << "hik" << endl;
    //    start ();
    }
}

TEST_CASE ("")
{
//        Kis  auto ph::Range auto;
    using namespace std;
}
