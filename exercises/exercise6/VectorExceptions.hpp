#ifndef VECTOR_EXCEPTIONS_HPP
#define VECTOR_EXCEPTIONS_HPP

#include <exception>

class IndexError: public std::exception
{ };

class EmptyVectorError: public std::exception
{ };

#endif
