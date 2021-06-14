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
//#include <ph_concepts/variant.hpp>

//#include <ph_concepts/types.hpp>



//#include <ph_concepts/algorithm.hpp>
//#include <ph_concepts/Type.hpp>
//#include <ph_concepts/common.hpp>

//#include <ranges>

#define two
#ifdef two
template <typename Comp>
concept Compiler = requires (Comp& comp)
{
//    {String auto res = Comp {"hej"}};
    true;
};
#endif

//auto tes (ph::Darwin auto d)
//{
//    
//}

TEST_CASE ()
{
//    std::cout << "bajs" << std::endl;
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






auto fun () -> ph::Number auto
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
auto func (ph::Signed auto i){}


//[[using CC: opt(1), debug]]
//struct

struct AA {
    inline static int times {0};
    int i {times++};
};

struct
{
    int i = 0;
} kiss;

#define cout std::cout
#define endl std::endl;





template <ph::Token token_type>
auto lex (ph::String auto source) -> ph::Range <token_type> auto
{
//    std::vector <>
}


//5 + 4 - (3 + 2);



//- 4 * 5 + 6 - ( 7 + 8 ) / 9


using namespace ph;

template <typename T>
concept Symbol = requires ()
{
    true;
};

template <typename T, typename U>
concept Stack = requires (T& t, U& u)
{
    {t.push (u)} -> same_as <void>;
    {t.pop ()} -> same_as <U&&>;
    {t.top ()} -> same_as <U&>;
};


template <typename T>
struct stack
{
    
    auto push (int) {
        
    }
    auto pop () {
        return 5;
    }
};

template <typename T>
concept Production_rule = requires ()
{
    true;
};

template <typename T>
concept Grammar = requires ()
{
    true;
};




//template <Grammar G>
//auto parse (Range auto r)
//{
//
//    for (auto const& tok : r)
//    {
//
//    }
//}

auto match (Range auto) -> Boolean auto;


enum TOKEN : uint8_t
{
    PLUS, MINUS, STAR,
    NUMBER, STRING, LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, LEFT_BRACKET, RIGHT_BRACKET
};

enum OPCODE : uint8_t
{
    ADD,
    CONSTANT,
    RETURN
};

auto parse (Range <TOKEN>  auto a)
{
    
}

auto vm (Range <OPCODE> auto a)
{
    
}


//auto push_bytes () {
//    
//}




template <typename>
concept teee = true;

template <teee>
struct tee {};




TEST_CASE ("memory")
{
    ph::Pointer auto p = ph::memory::allocate (1);
    ph::memory::reallocate (p, 10);
    ph::memory::deallocate (p);
}

struct pstack
{
    
};

struct shift_reduce_parser
{
    std::vector <TOKEN> tokens;
    
};


template <typename T>
concept Shift_reduce_parser = requires (T& t)
{
    typename T::token_type;
    {T::shift_in}; /// read one symbol from the input and pushing it onto the stack
    true;
};





TEST_CASE ("app")
{
    std::string str = "foobar";
    
    cout << str.starts_with("foo") << endl; // true
//    cout << *p << endl;
//    String auto inp = "
    
//    auto tokens = {NUMBER, PLUS, NUMBER};
    
    auto arr = std::vector <int> {3, 4, 5};
    auto arr2 = std::vector <int>{3, 4, 5};
//    cout << len(arr) << endl;
    REQUIRE(len(arr) == 3);
    assert(len(arr) == len(arr2));
//    cout << same_as <element_type_of<decltype(arr)>, int&> << endl;

    
    
//    for (auto i : arr)cout<<i<<endl;
    
    
//    ph::transform (arr, arr2, [](auto&& i){return forward (i);});
//    ph::for_each (arr, [](auto&& t){cout<<t<<"::"<<endl;});

    auto tokens = std::vector {NUMBER, PLUS, NUMBER};

    
    
    
    
    auto chunk = std::vector <uint8_t> {};
    auto constants = std::vector <uint8_t> {};
    
    chunk.push_back (OPCODE::CONSTANT);
    
    int constant_index = 0;
    
    chunk.push_back (constant_index);
    
    parse (tokens);
    
    
    
//    for (auto i : tokens)
//        cout << i << endl;
    
    auto scanner = [] (String auto source) -> Range <char> auto
    {
        for (auto c : source)
        {
//            cout << c << endl;
        }
//        return str;
    };
    
//    scanner ("hej");
//    cout << "hi" << endl;
    

//    std::cout << kiss.i << std::endl;
//    int x = 1, y = 1;
//    std::cout << x << " " << y << '\n';
//    const auto foo = [&x, y]() { ++x; };
//    foo();
//    std::cout << x << " " << y << '\n';
//    foo();
//    std::cout << x << " " << y << '\n';
//    using namespace std;
//    int i = 1;
//    cout << (i == true) << endl;
    
//    func (true);
//    unsigned i = -3;
    
    ph::Signed auto ii = 4;
    
    
    
//    cout << i << endl;
//    cout << Self << endl;
    
//    R i;
//    R i2 {i};
    ph::Number auto a = fun ();
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
