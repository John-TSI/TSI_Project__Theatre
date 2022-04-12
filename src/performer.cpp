#include"../include/employee.hpp"
#include"../include/performer.hpp"

// --- constructors ---
Performer::Performer(){}
Performer::Performer(int idNum) : Employee(idNum) {}

// --- getters/setters ---
bool Performer::GetAssigned() { return assigned; }
void Performer::SetAssigned(bool input) { assigned = input; }
bool Performer::GetCostumed() { return costumed; }
void Performer::SetCostumed(bool input) { costumed = input; }