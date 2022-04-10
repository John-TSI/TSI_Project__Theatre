#include"../include/play.hpp"


// --- constructors ---
Play::Play() {}
Play::Play(int perfID) : Performance(perfID) {}


// --- getters/setters ---
string Play::GetGenre() { return genre; }
void Play::SetGenre(string input) { genre = input; }
int Play::GetNumActors() { return numActors; }
void Play::SetNumActors(int input) { numActors = input; }
vector<Actor> Play::GetActorRoster() { return actorRoster; }
void Play::SetActorRoster(vector<Actor> input) { actorRoster = input; }