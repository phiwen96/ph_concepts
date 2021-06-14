/// While parsers read text formats, generators write them

#pragma once
//#include <boost/spirit/include/qi.hpp> /// classes and functions to develop parsers
//#include <boost/spirit/home/x3.hpp>
#include <experimental/coroutine>
#include "typeinfo.hpp"
#include "concepts.hpp"

using namespace std::experimental;

//#include <boost/spirit/include/karma.hpp> /// classes and functions to develop generators can be found in boost::spirit::karma
//#include <boost/spirit/include/lex.hpp> /// can be used to develop lexers

//using namespace boost::spirit;

auto start () -> int;
