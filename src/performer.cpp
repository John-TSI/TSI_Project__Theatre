#include"../include/employee.hpp"
#include"../include/performer.hpp"

// --- constructors ---
Performer::Performer(){}
Performer::Performer(int idNum) : Employee(idNum) {}

// --- getters/setters ---
bool Performer::GetBooked() { return booked; }
void Performer::SetBooked(bool input) { booked = input; }
bool Performer::GetCostumed() { return costumed; }
void Performer::SetCostumed(bool input) { costumed = input; }