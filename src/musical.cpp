#include<iostream>
#include"../include/musical.hpp"

using std::cout; using std::endl;

// --- constructors ---
Musical::Musical() {}
Musical::Musical(int perfID) : Performance(perfID) {}
Musical::Musical(int perfID, float ticketPrice) : Performance(perfID, ticketPrice) {}


//--- getters/setters ---
int Musical::GetNumSingers() {return numSingers; }
void Musical::SetNumSingers(int input) { numSingers = input; }
int Musical::GetReqNumSingers() { return reqNumSingers; }
void Musical::SetReqNumSingers(int input) { reqNumSingers = input; }
vector<Singer>& Musical::GetSingerRoster() { return singerRoster; }
void Musical::SetSingerRoster(vector<Singer> input) { singerRoster = input; }
int Musical::GetNumMusicians() {return numMusicians; }
void Musical::SetNumMusicians(int input) { numMusicians = input; }
int Musical::GetReqNumMusicians() { return reqNumMusicians; }
void Musical::SetReqNumMusicians(int input) { reqNumMusicians = input; }
vector<Musician>& Musical::GetMusicianRoster() { return musicianRoster; }
void Musical::SetMusicianRoster(vector<Musician> input) { musicianRoster = input; }