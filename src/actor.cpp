#include"../include/actor.hpp"


// --- constructors ---
Actor::Actor(int idNum) : Performer(idNum) {}
Actor::Actor(int idNum, float salary) : Performer(idNum, salary) {}
//Actor::Actor(int idNum, string genre) : Performer(idNum), genre(genre) {}


// ---getters/setters ---
string Actor::GetGenre() { return genre; }
void Actor::SetGenre(string input) { genre = input; }