#include"../include/musical.hpp"


// --- constructors ---
Musical::Musical() {}
Musical::Musical(int perfID) : Performance(perfID) {}


//--- getters/setters ---
string Musical::GetStyle() { return style; }
void Musical::SetStyle(string input) { style = input; }
int Musical::GetNumSingers() {return numSingers; }
void Musical::SetNumSingers(int input) { numSingers = input; }
vector<Singer> Musical::GetSingerRoster() { return singerRoster; }
void Musical::SetSingerRoster(vector<Singer> input) { singerRoster = input; }
vector<string> Musical::GetRequiredInstruments() { return requiredInstruments; }
void Musical::SetRequiredInstruments(vector<string> input) { requiredInstruments = input; }
int Musical::GetNumMusicians() {return numMusicians; }
void Musical::SetNumMusicians(int input) { numMusicians = input; }
vector<Musician> Musical::GetMusicianRoster() { return musicianRoster; }
void Musical::SetMusicianRoster(vector<Musician> input) { musicianRoster = input; }