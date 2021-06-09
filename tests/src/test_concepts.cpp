//#include "testlib.hpp"
#define RUN_CATCH
#ifdef RUN_CATCH

//#include "test.hpp"
#include <catch2/catch.hpp>
//#include <philip/philip.hpp>
//#include <ph_file/file.hpp>
#include <ph_concepts/concepts.hpp>
#include <ph_concepts/platform.hpp>
//#include <ph_concepts/algorithm.hpp>
//#include <ph_concepts/Type.hpp>
//#include <ph_concepts/common.hpp>

//#include <ranges>

auto tes (Darwin auto d)
{
    
}

//using namespace std;


struct A
{
    int i;
    A  operator*();//{return *this;}
    A& operator= (A const&) = delete;
    //    A& operator= (A&&){}
};

//template <typename T>
//concept AA = requires (T& t1, T& t2)
//{
////    {static_cast <T&> (*t1)} -> concepts::Reference;
//};




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

auto dist (auto p1, auto p2)
{
    auto a = p1.x() - p2.x();
    auto b = p1.y() - p2.y();
    return std::sqrt (a*a + b*b);
}

template <typename T>
class Point2D {
public:
    Point2D(T x, T y) : x_{x}, y_{y} {}
    auto x() { return x_; }
    auto y() { return y_; }
    // ...
private:
    T x_{};
    T y_{};
};






auto fun () -> Number auto
{
    return 3;
}

#define Concept kuk
//#define Self BOOST_PP_STRINGIZE (Test, Concept)
//#define Self BOOST_PP_STRINGIZE (Test, __FILE__)


//template <auto a, decltype (a)>
//concept Numeric = true;//std::is_same_v <T, U> and requires (T& a) {
////    true;
////};


//template <typename T>
//concept Numeric = true;//std::is_same_v <T, U> and requires (T& a) {
//    true;
//};


//template <bool T>
//concept Ja = true;
auto func (Signed auto i){}


TEST_CASE ("begin")
{
    GIVEN ("char []")
    {
        char str[] {"hej"};
//        std::cout << "hej" << std::endl;
//        REQUIRE (*begin (str) == 'h');
//        std::cout << "då" << std::endl;

    }
    
    GIVEN ("char [4]")
    {
        char str[4] {"hej"};
//        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("char const*")
    {
        char const* str {"hej"};
//        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("std::string")
    {
        std::string str {"hej"};
//        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("std::vector")
    {
        std::vector<int> str {1, 2, 3};
        REQUIRE (*begin (str) == 1);
    }
    
    GIVEN ("std::array")
    {
        std::array<int, 3> str {1, 2, 3};
        REQUIRE (*begin (str) == 1);
    }
}

TEST_CASE ("end")
{
    GIVEN ("char []")
    {
        char str[] {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("char [4]")
    {
        char str[4] {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("char const*")
    {
        char const* str {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("int []")
    {
        int str[] {1, 2};
//        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("int [4]")
    {
        int str[4] {1, 2, 3, 4};
//        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("std::string")
    {
        std::string str {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("std::vector")
    {
        std::vector<int> str {1, 2, 3};
        REQUIRE (*(end (str) - 1) == 3);
    }
    
    GIVEN ("std::array")
    {
        std::array<int, 3> str {1, 2, 3};
        REQUIRE (*(end (str) - 1) == 3);
    }
}

TEST_CASE ("app")
{
//    using namespace std;
    int i = 1;
//    cout << (i == true) << endl;
    
//    func (true);
//    unsigned i = -3;
    
    Signed auto ii = 4;
    
    
    
//    cout << i << endl;
//    cout << Self << endl;
    
//    R i;
//    R i2 {i};
    Number auto a = fun ();
    bool s = true;
//    ++s;
//    cout << s << endl;
    
    
    auto p1 = Point2D{2, 2};
    auto p2 = Point2D{6, 5};
    auto d = dist(p1, p2);
//    std::cout << d << endl;
    //    auto values = std::vector{9, 2, 5, 3, 4};
    //    std::ranges::sort(values);
    //    char* source = ph::file::read (TEST_FILE);
    //    free (source);
//    cout << "hi" << endl;
}


/**
 
 
 
 */

#endif
