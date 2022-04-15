#include<iostream>
#include"../include/musical.hpp"

using std::cout; using std::endl;

// --- constructors ---
Musical::Musical() {}
Musical::Musical(int perfID) : Performance(perfID) {}


//--- getters/setters ---
string Musical::GetStyle() { return style; }
void Musical::SetStyle(string input) { style = input; }
int Musical::GetNumSingers() {return numSingers; }
void Musical::SetNumSingers(int input) { numSingers = input; }
int Musical::GetReqNumSingers() { return reqNumSingers; }
void Musical::SetReqNumSingers(int input) { reqNumSingers = input; }
vector<Singer>& Musical::GetSingerRoster() { return singerRoster; }
void Musical::SetSingerRoster(vector<Singer> input) { singerRoster = input; }
vector<string> Musical::GetRequiredInstruments() { return requiredInstruments; }
void Musical::SetRequiredInstruments(vector<string> input) { requiredInstruments = input; }
int Musical::GetNumMusicians() {return numMusicians; }
void Musical::SetNumMusicians(int input) { numMusicians = input; }
int Musical::GetReqNumMusicians() { return reqNumMusicians; }
void Musical::SetReqNumMusicians(int input) { reqNumMusicians = input; }
vector<Musician>& Musical::GetMusicianRoster() { return musicianRoster; }
void Musical::SetMusicianRoster(vector<Musician> input) { musicianRoster = input; }


// --- utility ---
void Musical::PrintSingers(vector<Singer> sList)
{
    for(Singer s : sList) { cout << s.GetIDNum() << " "; }
}
void Musical::CastSinger(Singer s, vector<Singer>& singerRoster)
{
    singerRoster.push_back(s);
    numSingers++;
} 

void Musical::PrintMusicians(vector<Musician> mList)
{
    for(Musician m : mList) { cout << m.GetIDNum() << " "; }
}
void Musical::CastMusician(Musician m, vector<Musician>& musicianRoster)
{
    musicianRoster.push_back(m);
    numMusicians++;
} 