#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
using namespace std;
using std::cout, std::endl;
using namespace ph;

template <typename T>
concept Kuk = SAME_AS(std::string) or SAME_AS(int) or SAME_AS(char const*) or SAME_AS(T&);


template <typename T, typename U>
concept TA = true;//same_as<T, int>;

struct A
{
    operator char const* (){
        return "j";
    }
};






TEST_CASE ()
{
    
    
    
    
    cout << ph::size ("hej") << endl;
}
