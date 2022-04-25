#include"../include/employee.hpp"


// --- constructors ---
Employee::Employee(int idNum) : idNum(idNum) {}
Employee::Employee(int idNum, float salary) : idNum(idNum), salary(salary) {}


// --- getters/setters ---
int Employee::GetIDNum() { return idNum; }
void Employee::SetIDNum(int input) { idNum = input; }
float Employee::GetSalary() { return salary; }
void Employee::SetSalary(float input) { salary = input; }