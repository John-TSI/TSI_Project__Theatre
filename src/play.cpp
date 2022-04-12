#include<iostream>
#include"../include/play.hpp"

using std::cout; using std::endl;


// --- constructors ---
Play::Play() {}
Play::Play(int perfID) : Performance(perfID) {}


// --- getters/setters ---
string Play::GetGenre() { return genre; }
void Play::SetGenre(string input) { genre = input; }
int Play::GetNumActors() { return numActors; }
void Play::SetNumActors(int input) { numActors = input; }
int Play::GetReqNumActors() { return reqNumActors; }
void Play::SetReqNumActors(int input) { reqNumActors = input; }
vector<Actor> Play::GetActorRoster() { return actorRoster; }
void Play::SetActorRoster(vector<Actor> input) { actorRoster = input; }


// --- utility ---
void Play::PrintActors(vector<Actor> aList)
{
    for(Actor a : aList) { cout << a.GetIDNum() << " "; }
}
void Play::CastActor(Actor a, vector<Actor>& actorRoster)
{
    actorRoster.push_back(a);
    numActors++;
} 