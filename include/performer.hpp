#ifndef PERFORMER_HPP
#define PERFORMER_HPP

#include<string>
#include"employee.hpp"


class Performer : public Employee
{ 
    private:
        bool isAssigned = false;
        int inPerfID = -1;
    
    protected:
        Performer(int); // allow derived classes to initialise Employee.idNum
        Performer(int, float); // allow derived classes to initialise Employee.idNum and Employee.salary  

    public:
        bool GetIsAssigned();
        void SetIsAssigned(bool);
        int GetInPerfID();
        void SetInPerfID(int);
};

#endif