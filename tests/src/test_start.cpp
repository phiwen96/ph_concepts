#include <catch2/catch.hpp>
#include <ph_concepts/concepts.hpp>
#include <ph_concepts/platform.hpp>
#include <ph_concepts/common.hpp>
#include <ph_concepts/memory.hpp>
#include <ph_concepts/algorithm.hpp>
#include <experimental/coroutine>
using namespace std::experimental;
    //#include <ph_concepts/start.hpp>






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
    
    
    
    
    
        //    template <typename Opcode>
    struct alignas (8) Instruction
    {
        enum //: uint_fast8_t
        {
            TYPE_OPCODE,
            TYPE_FLOAT,
            TYPE_BOOLEAN
            
        } type : 2;
        
        union alignas (4)
        {
            uint_fast8_t opcode;
            float value_float;
            bool value_boolean;
            
        } unknown;
        
        operator float& ()
        {
            type = TYPE_FLOAT;
            return unknown.value_float;
        }
        
        operator bool& ()
        {
            type = TYPE_BOOLEAN;
            return unknown.value_boolean;
        }
        
        operator uint_fast8_t& ()
        {
            type = TYPE_OPCODE;
            return unknown.opcode;
        }
        
        friend std::ostream& operator<< (std::ostream& os, Instruction const& i)
        {
            switch (i.type)
            {
                case TYPE_OPCODE:
                    return os << "TYPE_OPCODE " << i.unknown.opcode;;
                    
                case TYPE_FLOAT:
                    return os << "TYPE_FLOAT" << i.unknown.value_float;
                    
                case TYPE_BOOLEAN:
                    return os << "TYPE_BOOLEAN " << i.unknown.value_boolean;
                    
                default:
                    throw "TYPE_ERROR???";
                    break;
            }
            
        }
        
    private:
        
    };
    
    struct Token
    {
        enum
        {
            MINUS,
            PLUS,
            NUMBER
        } type;
    };
    
    
    auto lex (Range auto&& source)
    {
        
    }
    
    
    auto parse (Range auto&& code, auto&& callable)
    {
        for (auto pc = ph::begin (code);
             pc < ph::end (code);
             ++pc)
        {
            
            callable (pc);
        }
    }
    
    
    
    
    enum class Opcode : uint_fast8_t
    {
        OP_
    };
    
    
    template <auto>
    struct TT {};
    
    
    struct parser
    {
        struct promise_type
        {
            Token token;
            auto get_return_object ()
            {
                return parser {coroutine_handle<promise_type>::from_promise(*this)};
            }
            auto initial_suspend () noexcept {
                return suspend_never {};
            }
            auto final_suspend () noexcept {
                struct awaiter
                {
                    auto await_ready () noexcept {
                        return false;
                    }
                    auto await_suspend (coroutine_handle <promise_type> c) noexcept// -> coroutine_handle<>
                    {
//                        if (auto coro)
//                        {
//                            coro.promise().set_child({});
//                            return coro;
//
//                        } else
//                        {
//                            return noop_coroutine();
//                        }
                    }
                    auto await_resume () noexcept {
                        
                    }
                };
                return awaiter {};
            }
            auto unhandled_exception () {
                std::terminate ();
            }
            auto return_void () {
                
            }
            auto await_transform (char cc) {
                
//                cc = c;
                struct awaiter
                {
                    promise_type& p;
//                    char& c;
                    
                    auto await_ready () -> bool
                    {
                            //                    cout << "await_ready" << endl;
                        return false;
                    }
                    
                    auto await_suspend (coroutine_handle<> c) -> auto
                    {
                            //                    cout << "await_suspend" << endl;
                            //        return c;
                        return true;
                    }
                    
                    auto await_resume () -> Token&
                    {
                            //                    cout << "await_resume" << endl;
                        return p.token;
                    }
                };
                    //            cout << "await_transform (get_char g)" << endl;
                return awaiter {*this};
            }
//            auto await_transform (parser const& t) {
//
//
//            }
    
//
        };
        
        
        coroutine_handle <promise_type> m_handle;
        
        parser () = delete;
        parser (parser const&) = delete;
        parser (parser&& o) : m_handle {std::exchange (o.m_handle, {})} {}
        explicit parser (coroutine_handle <promise_type> handle) : m_handle {handle} {}
        ~parser () {
            if (m_handle)
                m_handle.destroy();
        }
        
        
        auto& operator() (Token& token) {
            m_handle.promise().token = token;
            m_handle.resume();
            return *this;
        }
        
        auto done () {
            return m_handle.done();
        }

        
        
    };
    
    
    
    inline auto begin_parse () -> parser
    {
        Token& token = co_await char {};
        
        
        switch (token.type)
        {
            case Token::NUMBER:
                goto Number;
                
            default:
                break;
        }
        
        
        Number:
        
        
        
        
        for (;;)
        {
//            c = co_await char {};
        }
//        std::cout << "tjoi" << std::endl;
        co_return;
    }
    
    
    
    
    
    
    inline auto parse (ph::Range auto&& str)
    {
        auto p = begin_parse ();
        
        
        
        for (auto i = ph::begin (str); i < ph::end (str); ++i)
        {
//            p (*i);
        }
    }
        //
    
    TEST_CASE ("")
    {
            //        Kis  auto ph::Range auto;
        using namespace std;
        parse (std::string {"hej "});
            //        cout << sizeof (Instruction<Opcode>) << endl;
        
            //        auto fun = ;
            //        fun.operator ()<Instruction::TYPE_OPCODE> ();
        
        parse (std::string {"hej"}, [] (auto&& iter){
            
            switch (*iter)
            {
                    
            }
            
        });
        
        
            //    start ();
    }
}

    //TEST_CASE ("")
    //{
    ////        Kis  auto ph::Range auto;
    //    using namespace std;
    //}
