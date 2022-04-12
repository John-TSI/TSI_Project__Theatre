#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include<string>
#include"employee.hpp"


class Performer : public Employee
{
     protected: // allow derived classes to instantiate Employee.idNum
        Performer(int); 
    private:
        bool assigned = false;
        bool costumed = false;

    public:
        Performer();

        bool GetAssigned();
        void SetAssigned(bool);
        bool GetCostumed();
        void SetCostumed(bool);
};

#endif