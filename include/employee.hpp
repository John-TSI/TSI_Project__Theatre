#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include<string>

using std::string;

class Employee
{
    private:
        int idNum = 0;
        float salary = 120.0f;

    protected:
        Employee(int); // allow derived classes to initialise idNum
        Employee(int, float); // derived classes can initialise idNum and salary

    public:
        int GetIDNum();
        void SetIDNum(int);
        float GetSalary();
        void SetSalary(float);

};

#endif