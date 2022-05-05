#include"../include/excInvalidOperation.hpp"


// --- object is already assigned/scheduled ---
InvalidOperation::AssignedActor::AssignedActor(int inPerfID) : msg
    (
        std::string("\nThe specified Actor is already assigned to Play with performance ID ") 
        + std::to_string(inPerfID) + std::string(". Check your input and try again.\n")
    ) {}
const char* InvalidOperation::AssignedActor::what() const noexcept
{
    return msg.c_str();
}

InvalidOperation::AssignedSinger::AssignedSinger(int inPerfID) : msg
    (
        std::string("\nThe specified Singer is already assigned to Musical with performance ID ") 
        + std::to_string(inPerfID) + std::string(". Check your input and try again.\n")
    ) {}
const char* InvalidOperation::AssignedSinger::what() const noexcept
{
    return msg.c_str();
}

InvalidOperation::AssignedMusician::AssignedMusician(int inPerfID) : msg
    (
        std::string("\nThe specified Musician is already assigned to Musical with performance ID ") 
        + std::to_string(inPerfID) + std::string(". Check your input and try again.\n")
    ) {}
const char* InvalidOperation::AssignedMusician::what() const noexcept
{
    return msg.c_str();
}

InvalidOperation::ScheduledPlay::ScheduledPlay(int inHallNum) : msg
    (
        std::string("\nThe specified Play is already scheduled in Performance Hall number ") 
        + std::to_string(inHallNum) + std::string(". Check your input and try again.\n")
    ) {}
const char* InvalidOperation::ScheduledPlay::what() const noexcept
{
    return msg.c_str();
}

InvalidOperation::ScheduledMusical::ScheduledMusical(int inHallNum) : msg
    (
        std::string("\nThe specified Musical is already scheduled in Performance Hall number ") 
        + std::to_string(inHallNum) + std::string(". Check your input and try again.\n")
    ) {}
const char* InvalidOperation::ScheduledMusical::what() const noexcept
{
    return msg.c_str();
}

InvalidOperation::BookedHall::BookedHall(int perfID) : msg
    (
        std::string("\nThe specified Performance Hall is already booked with a Performance (ID ") 
        + std::to_string(perfID) + std::string(").\nCheck your input and try again.\n")
    ) {}
const char* InvalidOperation::BookedHall::what() const noexcept
{
    return msg.c_str();
}

 // Performance Hall has insufficient capacity to book a given Performance
 InvalidOperation::InsufficientCapacity::InsufficientCapacity(int capacity) : msg
    (
        std::string("\nThe specified Performance Hall is unable to accommodate this Performance (max capacity: ") 
        + std::to_string(capacity) + std::string(").\nCheck your input and try again.\n")
    ) {}
const char* InvalidOperation::InsufficientCapacity::what() const noexcept
{
    return msg.c_str();
}

 // Performance has oversold tickets for its booked Hall capacity
 InvalidOperation::OversoldTickets::OversoldTickets(int capacity) : msg
    (
        std::string("\nThis Performance is currently scheduled in a Performance Hall with an insufficient capacity.")
        + std::string("\nUnschedule the Musical before modifying its ticket sales, or enter a number <= ") 
        + std::to_string(capacity) + std::string(".\n")
    ) {}
const char* InvalidOperation::OversoldTickets::what() const noexcept
{
    return msg.c_str();
}

 // Performance Hall capacity cannot be reduced below tickets sold
 InvalidOperation::CannotReduceCapacity::CannotReduceCapacity(int ticketsSold) : msg
    (
        std::string("\nThe Performance currently scheduled in this Hall has sold more tickets than there would be seats available.")
        + std::string("\nUnschedule the Performance before modifying the Hall capacity, or enter a number >= ") 
        + std::to_string(ticketsSold) + std::string(".\n")
    ) {}
const char* InvalidOperation::CannotReduceCapacity::what() const noexcept
{
    return msg.c_str();
}


// --- object is not assigned/scheduled ---
const char* InvalidOperation::UnassignedActor::what() const noexcept
{
    return "\nThe specified Actor is not currently assigned to a Play. Check your input and try again.\n";
}

const char* InvalidOperation::UnassignedSinger::what() const noexcept
{
    return "\nThe specified Singer is not currently assigned to a Musical. Check your input and try again.\n";
}

const char* InvalidOperation::UnassignedMusician::what() const noexcept
{
    return "\nThe specified Musician is not currently assigned to a Musical. Check your input and try again.\n";
}

const char* InvalidOperation::UnscheduledPlay::what() const noexcept
{
    return "\nThe specified Play is not currently scheduled in a Performance Hall. Check your input and try again.\n";
}

const char* InvalidOperation::UnscheduledMusical::what() const noexcept
{
    return "\nThe specified Musical is not currently scheduled in a Performance Hall. Check your input and try again.\n";
}