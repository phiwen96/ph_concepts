/// While parsers read text formats, generators write them

#pragma once
//#include <boost/spirit/include/qi.hpp> /// classes and functions to develop parsers
//#include <boost/spirit/home/x3.hpp>
#include <experimental/coroutine>
#include "typeinfo.hpp"
#include "concepts.hpp"
#include "experimenting.hpp"

using namespace std::experimental;

//#include <boost/spirit/include/karma.hpp> /// classes and functions to develop generators can be found in boost::spirit::karma
//#include <boost/spirit/include/lex.hpp> /// can be used to develop lexers

//using namespace boost::spirit;

#include "start.hpp"


#define EAT(...)
#define EAT_NOT(...) __VA_ARGS__




    //template <typename T>
    //concept Registers_snapshot = requires ()
    //{
    //    true;
    //};
    //
    //
    //auto call (auto&& return_address)
    //{
    //
    //}



template <typename T>
concept Stack_pointer = requires ()
{
    true;
};




template <typename T>
concept Instruction = requires ()
{
    true;
};


template <typename T>
concept Cpu = requires (T& t)
{
    t.execute_next_instruction ();
        //    typename T::
    true;
};


/*
 A program contains a sequence of instructions that the CPU executes
 */
template <typename T>
concept Program = ph::Range <T> and Instruction <ph::typeinfo::range::element_type <T>> and requires ()
{
    true;
};


struct machine
{
    struct memory
    {
        std::byte mem [4096];
    };
    
    
    struct cpu
    {
        std::byte * pc;
        
    };
    
};


struct program
{
    
};


template <typename T>
concept Register = requires ()
{
    true;
};

template <typename T>
concept Memory = requires ()
{
    true;
};

template <typename T>
concept Constant = requires ()
{
    true;
};

auto push (Register auto&&)
{
    
}

    //auto hushållande_av_

template <typename T>
concept Computer = requires ()
{
    requires(int k) {
        4+3;
        k++;
    };
};


struct computer
{
    
};



    ////////////////////////////////////////////////////
    ///  Arithmetic instructions:
    ///
    ///  Performs only one operation and must have
    ///  exactly 3 variables
    ///////////////////////////////////////////////////////
auto _add (Register auto&& dst, Register auto&& op_0, Register auto&& op_1) -> void
{
    
}

auto _sub (Register auto&& dst, Register auto&& op_0, Register auto&& op_1) -> void
{
    
}


    ////////////////////////////////////////////////////
    ///  @brief Data transfer instructions
    ///
    /// @param dst
    ///
    ///  instructions that transfer data between
    ///  memory and registers
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    /// @brief copies data from memory to a register
    ////////////////////////////////////////////////////
auto _load (Register auto&& dst, Memory auto&& src) -> void
{
    
}

auto _store (Memory auto&& dst, Register auto&& src) -> void
{
    
}



    ////////////////////////////////////////////////////
    ///  Logical instructions
    ///////////////////////////////////////////////////////
auto _and (Register auto&& dst, Register auto&& op_0, Register auto&& op_1) -> void
{
    
}

auto _and (Register auto&& dst, Register auto&& op_0, Constant auto&& op_1) -> void
{
    
}

auto _or (Register auto&& dst, Register auto&& op_0, Register auto&& op_1) -> void
{
    
}

auto _xor (Register auto&& dst, Register auto&& op_0, Register auto&& op_1) -> void
{
    
}




    ////////////////////////////////////////////////////
    ///  conditional branch instructions
    ///
    ///  Performs only one operation and must have
    ///  exactly 3 variables
    ///////////////////////////////////////////////////////
auto branch_if_equal (Register auto&& op_0, Register auto&& op_1, ph::Unsigned auto&& pc_index) -> void
{
    
}

auto branch_if_not_equal (Register auto&& op_0, Register auto&& op_1, ph::Unsigned auto&& pc_index) -> void
{
    
}

auto branch_if_less_than (Register auto&& op_0, Register auto&& op_1, ph::Unsigned auto&& pc_index) -> void
{
    
}

auto branch_if_grater_or_equal_than (Register auto&& op_0, Register auto&& op_1, ph::Unsigned auto&& pc_index) -> void
{
    
}



    ////////////////////////////////////////////////////
    ///  uconditional branch instructions
    ///
    /// @param dst is a register holding the return address
    /// @param procedure is the procedure to jump to
    ///
    /// An
    // instruction that branches
    // to an address and
    // simultaneously saves the
    // address of the following
    // instruction in a register
    // (usually x1 in RISC-V).
///
///jal x1, ProcedureAddress // jump to ProcedureAddress and write return address to x1
    ///////////////////////////////////////////////////////
auto jump_and_link (Register auto&& ret_addr_reg, auto&& procedure) -> void
{
    
}

auto jump_and_link_register (Register auto&& op_0, ph::Unsigned auto&& pc_index) -> void
{
    
}






    //static_assert (Computer <computer>, "");


struct memory
{
    
};

/**
 The word size is 64 bits on a 64-bit architecture,
 32 bits on a 32-bit architecture, and so forth.
 
 assert(std::has_single_bit(alignment)); // Power of 2
 */






/**
 instruction takes exactly 64 bits
 */


/**
 64 bits
 */
struct alignas (8) registeer
{
    
    auto& operator= (registeer const& other)
    {
        flag = 0b00;
        value = other.value;
        return *this;
    }
    
    auto& operator= (double v)
    {
        flag = 0b00;
        value = v;
        return *this;
    }
    
    auto& operator= (std::byte* p)
    {
        flag = 0b01;
        pointer = p;
        return *this;
    }
    
    
    auto operator== (registeer const& other) -> bool
    {
        if (flag == 0)
        {
            if (other.flag == 1)
            {
                return false;
            }
            
            return value == other.value;
            
        } else
        {
            if (other.flag == 0)
            {
                return false;
            }
            
            return pointer == other.pointer;
        }
    }
    
private:
    
    union
    {
        double value {0};
        std::byte* pointer;
    };
    
    signed flag : 2 = 0b00;
};

/**
 64 bits
 */



struct alignas (8/*64 bits*/) instruction
{
    
//    int a : 1 = 0;
    
    /**
     2 bits
     */
    enum
    {
        OP_ADD,
        OP_SUB,
        OP_MULT
    } type : 2;
    
    
};







template <size_t N_bytes, size_t align = 1>
struct arena
{
    
    
    template <typename T>
    operator T* ()
    {
        return static_cast <T*> (allocate (sizeof (T)));
    }
    
    auto operator -= (size_t n)
    {
        deallocate (n);
    }
    
    
private:
    auto allocate (size_t n_bytes) -> void*
    {
        i += n_bytes;
        return std::exchange (current, current + n_bytes);
    }
    
    auto deallocate (size_t n_bytes)
    {
        i -= n_bytes;
        current -= n_bytes;
    }
    
    alignas (align) std::byte buffer [N_bytes];
    std::byte* current {buffer};
    size_t i {0};
};



struct stack
{
//    auto push ()
    
private:
    std::byte buffer [10];
    std::byte* current {buffer};
};


namespace ph::experimenting
{
    template <int>
    auto test (signed);
    
    template <>
    auto test <0> (signed loops)
    {
        ph::common::ScopedTimer t {"test 0"};
        
        for (int i = 0; i < loops; ++i)
        {
            auto lhs = new NumberExpression {10};
            auto rhs = new NumberExpression {10};
            auto expr = new AdditionExpression {lhs, rhs};
            
            delete lhs;
            delete rhs;
            delete expr;
        }
    }
    
    EAT ({
        struct next
        {
            next (int i) : i {i}, j {i}
            {

            }
            operator size_t ()
            {
                if (++i == j)
                {
                    throw std::runtime_error ("");
                }
                return i;
            }
        private:
            int i;
            int j;
        };
    })
    
#define TEST_FUNCTION [] (int o) {return o + 1;}
    
    template <>
    auto test <1> (signed loops)
    {
        ph::common::ScopedTimer t {"test 0"};


        auto next = [i = 30] (auto&&...) mutable
        {
            if (i == 0)
                throw;
            
            return 30 - std::exchange (i, i - 1);
        };
//            std::cout << next() << std::endl;
//            std::cout << next() << std::endl;
        
//            next
        
        for (int i = 0; i < loops; ++i)
        {
            int a[30];
//                a
    //        a[0] = Instruction::PUSH_INDENT;
            a[next()] = Instruction::PUSH_VALUE;
            a[next()] = 20;
            a[next()] = Instruction::INC_VALUE;
            a[next()] = Instruction::PRINT_VALUE;
            
            a[next()] = Instruction::PUSH_VALUE;
            a[next()] = -20;
            a[next()] = Instruction::INC_VALUE;
            a[next()] = Instruction::NEGATE_VALUE;
            a[next()] = Instruction::PRINT_VALUE;
//
            a[next()] = Instruction::ADD_VALUES;
            a[next()] = Instruction::PRINT_VALUE;
            
            a[next()] = Instruction::DONE;
//            a[4] = Instruction::DONE;
            
            
            auto da = ph::experimenting::VM {a};
//                int* k = new int {6};
//                delete k;
        
        }
        
    }
    
    template <>
    auto test <2> (signed loops)
    {
        auto a = ph::experimenting::scanner {"2+3"};
        
        auto b = (std::vector <ph::experimenting::Token>) a;
        
        for (auto& i : b)
        {
//            std::cout << i << std::endl;
        }
    }
    
    
    template <>
    auto test <3> (signed)
    {
        auto scanner = ph::experimenting::scanner {"5-(2+3)+4-7"};
        
        auto tokens = (std::vector <ph::experimenting::Token>) scanner;
//        tokens.push_back (ph::experimenting::Token::)
//        std::cout << b.size()<<std::endl;
        
        
        
        auto parser = ph::experimenting::parser {tokens};
        
        while (parser.code.stackSize > 0)
        {
            std::cout << parser.code.top() << std::endl;
            parser.code.pop();
        }
//        auto vm = ph::experimenting::VM {parser.code.stack};
        
        return;

        
    }
    
    
    
   
    
    auto start () -> int
    {
        test <3> (1);
        
        
        return 0;
    }
}



auto start () -> int
{
    ph::experimenting::start ();
    
    
    using namespace std;
//    cout << "" << setw (5) << "hej" << endl;
//    cout << "" << setw (10) << "hej" << endl;

    return 0;
}
#undef EAT_NOT
#undef EAT





/**
 auto* memory = std::malloc(sizeof(User));
 auto* user = ::new (memory) User("john");
 
 user->~User();
 std::free(memory);
 */
