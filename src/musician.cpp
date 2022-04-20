#include"../include/performer.hpp"
#include"../include/musician.hpp"


// --- constructors ---
Musician::Musician() {}
Musician::Musician(int idNum) : Performer(idNum) {}
Musician::Musician(int idNum, float salary) : Performer(idNum, salary) {}

// ---other methods ---
vector<string> Musician::GetInstruments() { return instruments; }