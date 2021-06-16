#pragma once

#include "common.hpp"
#include "concepts.hpp"
#include <list>
#include <queue>


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
        ERROR,
        PUSH_INDENT,
        PRINT_VALUE,
        POP_INDENT,
        PUSH_VALUE,
        INC_VALUE,
        DEC_VALUE,
        DONE,
        PUSH_STRING,
        NEGATE_VALUE,
        ADD_VALUES
    };
    
    
    auto const next = [i = 0]{};
    
    class VM
    {
    public:
        VM (int a [10]) : stackSize_(0) {
            
            run (a);
          
        }
        
            // Other stuff...
        
    private:
        static const int MAX_STACK = 128;
        int stackSize_ {0};
        int stack_[MAX_STACK];
        
        int indent {0};
        
        void push(int value)
        {
                // Check for stack overflow.
            assert(stackSize_ < MAX_STACK);
            stack_[stackSize_++] = value;
        }
        
        int& pop()
        {
                // Make sure the stack isn't empty.
//            assert(stackSize_ > 0);
            return stack_[--stackSize_];
        }
        
        int& top()
        {
                // Make sure the stack isn't empty.
            assert(stackSize_ > 0);
            return stack_[stackSize_ - 1];
        }

        
        void run (int a [128])
        {
            
            for (int i = 0; i < 128; ++i)
            {
                switch (a [i])
                {
                    case DONE:
                    {
                        std::cout << "DONE" << std::endl;
                        i = 128;
                        break;
                    }
                        
                    case ERROR:
                    {
                        std::cout << "PUSH_INDENT" << std::endl;

//                        throw std::runtime_error ("!");
                        break;
                    }
                        
                    case PUSH_INDENT:
                    {
//                        std::cout << "PUSH_INDENT" << std::endl;
                        
//                        indent += 4;
                        break;
                    }
                        
                    case POP_INDENT:
                    {
//                        std::cout << "POP_INDENT" << std::endl;
                        
//                        indent -= 4;
                        break;
                    }
                        
                    case NEGATE_VALUE:
                    {
                        std::cout << "NEGATE_VALUE" << std::endl;
                        top() *= -1;
//                        indent -= 4;
                        break;
                    }
                        
                    case PUSH_STRING:
                    {
                        break;
                    }
                        
                    case PUSH_VALUE:
                    {
                        push (a [i + 1]);
                        ++i;
//                        value = *(++begin);
                        
                        std::cout << "PUSH_VALUE " << top() << std::endl;
                        
//                        push (value);
//                        push ();
//                        ++begin;
                        break;
                    }
                        
                    case PRINT_VALUE:
                    {
                        
                        std::cout << "PRINT_VALUE " << top () << std::endl;
                        
                        break;
                    }
                        
                    case ADD_VALUES:
                    {
                        
//                        std::cout << "ADD_VALUES " << push(pop()) << std::endl;
                        
                        
                        break;
                    }
                        
                    case INC_VALUE:
                    {
                        ++top();
//                        int& value = * (begin - 1);
                        
//                        ++value;
                        
                        std::cout << "INC_VALUE " << std::endl;
//                        *(begin+1) += 1;
                        
                        
                        break;
                    }
                        
                    default:
                    {
                        break;
                    }
                }
            
            }
        Exit:{
            
        }
        }
    };
}

namespace ph::experimenting
{
    struct Token
    {
        enum
        {
            PLUS,
            MINUS,
            NUMBER,
            LPAREN,
            RPAREN,
            END
        } type;
        char const* begin;
        char const* end;
    };
    struct scanner
    {
        char const* s;
        scanner (char const* s) : s {s}
        {

        }
        
        operator std::vector <Token> ()
        {
            auto res = std::vector <Token> {};
            for (auto i = s; i < s + strlen (s); ++i)
            {
                if (*i == '+')
                {
                    res.push_back(Token{Token::PLUS, i, i + 1});

                } else if (*i == '-')
                {
                    res.push_back(Token{Token::MINUS, i, i + 1});

                } else if (*i == '(')
                {
                        res.push_back(Token{Token::LPAREN, i, i + 1});

                } else if (*i == ')')
                {
                            res.push_back(Token{Token::RPAREN, i, i + 1});

                } else if (isdigit(*i))
                {
                            res.push_back(Token{Token::NUMBER, i, i + 1});

                } else
                {
                    
                }
            }
            return res;
        }
        
    private:
        
    };
}


namespace ph::experimenting
{
    struct parser
    {
        struct
        {
            int stackSize {0};
            int stack [128];
            
            void push(int value)
            {
                    // Check for stack overflow.
                assert(stackSize < 128);
                stack[stackSize++] = value;
            }
            
            int& pop()
            {
                    // Make sure the stack isn't empty.
    //            assert(stackSize > 0);
                return stack[--stackSize];
            }
            
            int& top()
            {
                    // Make sure the stack isn't empty.
                assert(stackSize > 0);
                return stack[stackSize - 1];
            }
        } code;
        
        struct
        {
            int stackSize {0};
            int stack [128];
            
            void push(int value)
            {
                    // Check for stack overflow.
                assert(stackSize < 128);
                stack[stackSize++] = value;
            }
            
            int& pop()
            {
                    // Make sure the stack isn't empty.
    //            assert(stackSize > 0);
                return stack[--stackSize];
            }
            
            int& top()
            {
                    // Make sure the stack isn't empty.
                assert(stackSize > 0);
                return stack[stackSize - 1];
            }
        } stack;
        
        
        
        std::queue <std::function<void()>> queue;
        
        
        
        parser (std::vector <ph::experimenting::Token>& tokens)
        {
            for (auto i = tokens.begin(); i < tokens.end(); ++i)
            {
                if (not queue.empty())
                {
                    queue.front()();
                    if (i >= tokens.end())
                    {
                        break;
                    }
                }
                
                switch (i->type)
                {
                    case Token::NUMBER:
                    {
                        stack.push (std::stod (std::string {i->begin, i->begin + 1}));
                        std::cout << "Token::NUMBER\n";
                        break;
                    }
                        
                    case Token::PLUS:
                    {
                        code.push (stack.pop());
                        queue.push ([&]()
                        {
                            if (i->type == Token::NUMBER)
                            {
                                code.push (std::stod (std::string {i->begin, i->begin + 1}));
                                
                                ++i;

                            } else
                            {
                                queue.pop();
                                if (not queue.empty())
                                {
                                    queue.front()();
                                }
                            }
                        });
                        std::cout << "Token::PLUS\n";
                        break;
                    }
                        
                    case Token::MINUS:
                    {
                        std::cout << "Token::MINUS\n";
                        break;
                    }
                        
                    case Token::LPAREN:
                    {
                        queue.push ([&]()
                        {
                            if (i->type == Token::RPAREN)
                            {
                                queue.pop();
                                
                                if (not queue.empty())
                                {
                                    queue.front()();
                                }
                            }
                        });
                        std::cout << "Token::LPAREN\n";
                        break;
                    }
                        
    
                    default:
                        break;
                }
            }
            
            
        }
        
    private:
        
        
        
        auto group () -> void
        {
            
        }
    };
}

