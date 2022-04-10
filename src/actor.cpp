#include"../include/actor.hpp"


// --- constructors ---
Actor::Actor() {}
Actor::Actor(int idNum) : Performer(idNum) {}


// ---getters/setters ---
vector<string> Actor::GetGenres() { return genres; }