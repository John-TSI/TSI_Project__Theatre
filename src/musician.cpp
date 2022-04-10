#include"../include/performer.hpp"
#include"../include/musician.hpp"


// --- constructors ---
Musician::Musician() {}
Musician::Musician(int idNum) : Performer(idNum) {}

// ---other methods ---
vector<string> Musician::GetInstruments() { return instruments; }