#include"../include/employee.hpp"
#include"../include/performer.hpp"

// --- constructors ---
Performer::Performer(){}
Performer::Performer(int idNum) : Employee(idNum) {}
Performer::Performer(int idNum, float salary) : Employee(idNum, salary) {}

// --- getters/setters ---
bool Performer::GetIsAssigned() { return isAssigned; }
void Performer::SetIsAssigned(bool input) { isAssigned = input; }
int Performer::GetInPerfID() { return inPerfID; }
void Performer::SetInPerfID(int input) { inPerfID = input; }
//bool Performer::GetCostumed() { return costumed; }
//void Performer::SetCostumed(bool input) { costumed = input; }