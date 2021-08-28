#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
#include <ph_concepts/StringHelper.hpp>

namespace ph::concepts
{
    
    TEST_CASE ("[String, Helper]")
    {
        SECTION ("different types of string")
        {
            GIVEN ("default")
            {
                String auto str = "hej";
                static_assert (StringHelper <decltype (str)>::dynamic, "");
                static_assert (not StringHelper <decltype (str)>::known_bounds, "");
                REQUIRE (StringHelper <decltype (str)>::size (str) == 3);
            }
            
            GIVEN ("std::string")
            {
                String auto str = std::string {"foo"};
                static_assert (StringHelper <std::string>::dynamic, "");
                static_assert (StringHelper <std::string>::known_bounds, "");
                REQUIRE (StringHelper <std::string>::size (str) == 3);

            }
            
            
            
//            REQUIRE (string_helper (str).)
        }
    }
    
    TEST_CASE("[String]")
    {
        REQUIRE (String <std::string>);
        REQUIRE (String <char const*>);
        REQUIRE (String <char (&) []>);
        REQUIRE (String <char (&) [10]>);

        
        
        GIVEN ("std::string")
        {
            
        }
    }
}
