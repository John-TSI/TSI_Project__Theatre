#ifndef EXCEPTION_INVALID_INPUT_HPP
#define EXCEPTION_INVALID_INPUT_HPP

#include<exception>

namespace InvalidInput
{
    class excInvalidInput : public std::exception
    {
        public:
            virtual const char* what() const noexcept;
    };

    class excInvalidChoice : public std::exception
    {
        public:
            virtual const char* what() const noexcept;
    };
}

#endif