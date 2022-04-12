#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include<string>

using std::string;

class Employee
{
    private:
        string name = "Employee";
        int idNum = 0;
        float salary = 120.0f;

    protected: // allow derived classes to initialise Employee.idNum
        Employee(int);

    public:
        Employee();

        string GetName();
        void SetName(string);
        int GetIDNum();
        void SetIDNum(int);
        float GetSalary();
        void SetSalary(float);

};

#endif