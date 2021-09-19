#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
using namespace std;
using std::cout, std::endl;

template <typename T>
concept Kuk = SAME_AS(std::string) or SAME_AS(int) or SAME_AS(char const*) or SAME_AS(T&);

TEST_CASE ()
{
    Kuk auto asa = "hej";
    Kuk auto dd = 4;
    Kuk auto& cc = dd;
    cout << "hi" << endl;
    using namespace ph::concepts;
    int a[10];
    cout << TriviallyDefaultConstructible <decltype(a)> << endl;
    vector <int> b;
    cout << TriviallyDefaultConstructible <decltype(b)> << endl;
    
    REQUIRE (Container <std::vector <int>>);
    
    REQUIRE (not Container <decltype (a)>);
    REQUIRE (DefaultConstructible <decltype (a)>);


//    Trivially
}
