#include<iostream>
#include"../include/play.hpp"

using std::cout; using std::endl;


// --- constructors ---
Play::Play() {}
Play::Play(int perfID) : Performance(perfID) {}
Play::Play(int perfID, float ticketPrice) : Performance(perfID, ticketPrice) {}


// --- getters/setters ---
int Play::GetNumActors() { return numActors; }
void Play::SetNumActors(int input) { numActors = input; }
int Play::GetReqNumActors() { return reqNumActors; }
void Play::SetReqNumActors(int input) { reqNumActors = input; }
vector<Actor>& Play::GetActorRoster() { return actorRoster; }
void Play::SetActorRoster(vector<Actor> input) { actorRoster = input; }