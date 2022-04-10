#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include<string>
#include"employee.hpp"


class Performer : public Employee
{
     protected: // allow derived classes to instantiate Employee.idNum
        Performer(int); 
    private:
        bool booked = false;
        bool costumed = false;

    public:
        Performer();

        bool GetBooked();
        void SetBooked(bool);
        bool GetCostumed();
        void SetCostumed(bool);
};

#endif