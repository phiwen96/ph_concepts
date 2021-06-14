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
    ///  Performs only one operation and must have
    ///  exactly 3 variables
    ///////////////////////////////////////////////////////
auto jump_and_link (Register auto&& op_0, ph::Unsigned auto&& pc_index) -> void
{
    
}

auto jump_and_link_register (Register auto&& op_0, ph::Unsigned auto&& pc_index) -> void
{
    
}






    //static_assert (Computer <computer>, "");


struct memory
{
    
};

auto start () -> int
{
    
    
    return 0;
}
#undef EAT_NOT
#undef EAT

