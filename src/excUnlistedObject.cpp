#include"../include/excUnlistedObject.hpp"

const char* UnlistedObject::UnlistedActor::what() const noexcept
{
    return "The specified Actor is not currently listed. Check your input and try again.";
}

const char* UnlistedObject::UnlistedSinger::what() const noexcept
{
    return "The specified Singer is not currently listed. Check your input and try again.";
}

const char* UnlistedObject::UnlistedMusician::what() const noexcept
{
    return "The specified Musician is not currently listed. Check your input and try again.";
}

const char* UnlistedObject::UnlistedPlay::what() const noexcept
{
    return "The specified Play is not currently listed. Check your input and try again.";
}

const char* UnlistedObject::UnlistedMusical::what() const noexcept
{
    return "The specified Musical is not currently listed. Check your input and try again.";
}

const char* UnlistedObject::UnlistedHall::what() const noexcept
{
    return "The specified Performance Hall is not currently listed. Check your input and try again.";
}