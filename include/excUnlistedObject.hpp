#ifndef EXCEPTION_UNLISTED_OBJECT_HPP
#define EXCEPTION_UNLISTED_OBJECT_HPP

#include<exception>

namespace UnlistedObject
{
    class UnlistedActor : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnlistedSinger : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnlistedMusician : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnlistedPlay : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnlistedMusical : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnlistedHall : public std::exception
    {
        virtual const char* what() const noexcept;
    };
}

#endif