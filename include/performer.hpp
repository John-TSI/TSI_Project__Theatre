#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include<string>
#include"employee.hpp"


class Performer : public Employee
{
     protected: // allow derived classes to instantiate Employee.idNum
        Performer(int); 
    private:
        bool isAssigned = false;
        int inPerfID = -1;
        //bool costumed = false;

    public:
        Performer();

        bool GetIsAssigned();
        void SetIsAssigned(bool);
        int GetInPerfID();
        void SetInPerfID(int);
        //bool GetCostumed();
        //void SetCostumed(bool);
};

#endif