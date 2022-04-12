#include"../include/actor.hpp"


// --- constructors ---
Actor::Actor() {}
Actor::Actor(int idNum) : Performer(idNum) {}
Actor::Actor(int idNum, string genre) : Performer(idNum), genre(genre) {}


// ---getters/setters ---
vector<string> Actor::GetGenres() { return genres; }