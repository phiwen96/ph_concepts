#pragma once

#include "common.hpp"
#include "concepts.hpp"


namespace ph::experimenting
{
    class Expression
    {
    public:
        virtual ~Expression() {}
        virtual double evaluate() = 0;
    };
    
    
    class NumberExpression : public Expression
    {
    public:
        NumberExpression(double value)
        : value_(value)
        {}
        
        virtual double evaluate()
        {
            return value_;
        }
        
    private:
        double value_;
    };
    
    
    class AdditionExpression : public Expression
    {
    public:
        AdditionExpression(Expression* left, Expression* right)
        : left_(left),
        right_(right)
        {}
        
        virtual double evaluate()
        {
                // Evaluate the operands.
            double left = left_->evaluate();
            double right = right_->evaluate();
            
                // Add them.
            return left + right;
        }
        
    private:
        Expression* left_;
        Expression* right_;
    };
}


namespace ph::experimenting
{
    
    enum Instruction
    {
        ERROR = 0x00,
//        INST_SET_HEALTH      = 0x00,
        INST_SET_WISDOM      = 0x01,
        INST_SET_AGILITY     = 0x02,
        INST_PLAY_SOUND      = 0x03,
        INST_SPAWN_PARTICLES = 0x04,
        PUSH_INDENT = 0x05,
        PRINT_VALUE = 0x06,
        POP_INDENT = 0x08,
        PUSH_VALUE = 0x09,
        DONE = 0x10
    };
    
    
    class VM
    {
    public:
        VM (int a[10]) : stackSize_(0) {
            for (int i = 0; i < 10 and a [i] != DONE; ++i)
            {
                switch (a[i])
                {
                    case DONE:
                    {
                        std::cout << "DONE" << std::endl;
                        break;
                    }
                        
                    case ERROR:
                    {
                        throw std::runtime_error ("!");
                        break;
                    }
                        
                    case PUSH_INDENT:
                    {
                        std::cout << "PUSH_INDENT" << std::endl;

                        indent += 4;
                        break;
                    }
            
                    case POP_INDENT:
                    {
                        std::cout << "POP_INDENT" << std::endl;

                        indent -= 4;
                        break;
                    }
                        
                    case PUSH_VALUE:
                    {
                        std::cout << "PUSH_VALUE" << std::endl;

                        push (a [i+1]);
                        break;
                    }
                        
                    case PRINT_VALUE:
                    {
                        std::cout << "PRINT_VALUE " << pop () << std::endl;
                        
                        break;
                    }
                        
                    default:
                    {
                        break;
                    }
                }
            }
        }
        
            // Other stuff...
        
    private:
        static const int MAX_STACK = 128;
        int stackSize_;
        int stack_[MAX_STACK];
        
        int indent {0};
        
        void push(int value)
        {
                // Check for stack overflow.
            assert(stackSize_ < MAX_STACK);
            stack_[stackSize_++] = value;
        }
        
        int pop()
        {
                // Make sure the stack isn't empty.
            assert(stackSize_ > 0);
            return stack_[--stackSize_];
        }
    };
}

