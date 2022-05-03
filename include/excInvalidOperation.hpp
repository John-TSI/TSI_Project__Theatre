#ifndef EXCEPTION_INVALID_OPERATION_HPP
#define EXCEPTION_INVALID_OPERATION_HPP

#include<exception>
#include<string>

namespace InvalidOperation
{
    // object already assigned/scheduled
    class AssignedActor : public std::exception
    {
        std::string msg;
        public:
            explicit AssignedActor(int);
            virtual const char* what() const noexcept;
    };
    class AssignedSinger : public std::exception
    {
        std::string msg;
        public:
            explicit AssignedSinger(int);
            virtual const char* what() const noexcept;
    };
    class AssignedMusician : public std::exception
    {
        std::string msg;
        public:
            explicit AssignedMusician(int);
            virtual const char* what() const noexcept;
    };
    class ScheduledPlay : public std::exception
    {
        std::string msg;
        public:
            explicit ScheduledPlay(int);
            virtual const char* what() const noexcept;
    };
    class ScheduledMusical : public std::exception
    {
        std::string msg;
        public:
            explicit ScheduledMusical(int);
            virtual const char* what() const noexcept;
    };

    // object is not assigned/scheduled
    class UnassignedActor : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnassignedSinger : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnassignedMusician : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnscheduledPlay : public std::exception
    {
        virtual const char* what() const noexcept;
    };
    class UnscheduledMusical : public std::exception
    {
        virtual const char* what() const noexcept;
    };
}

#endif