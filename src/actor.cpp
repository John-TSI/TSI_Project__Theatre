#include"../include/actor.hpp"


// --- constructors ---
Actor::Actor(int idNum) : Performer(idNum) {}
Actor::Actor(int idNum, float salary) : Performer(idNum, salary) {}