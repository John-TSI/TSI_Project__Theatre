#include"../include/performance.hpp"

// --- constructors ---
Performance::Performance() {}
Performance::Performance(int perfID) : perfID(perfID) {}


// --- getters/setters ---
string Performance::GetName() { return name; }
void Performance::SetName(string input) { name = input; }
int Performance::GetPerfID() { return perfID; }
void Performance::SetPerfID(int input) { perfID = input; }
bool Performance::GetScheduled() { return scheduled; }
void Performance::SetScheduled(bool input) { scheduled = input; }
int Performance::GetHallNum() { return hallNum; }
void Performance::SetHallNum(int input) { hallNum = input; }
float Performance::GetTicketPrice() { return ticketPrice; }
void Performance::SetTicketPrice(float input) { ticketPrice = input; }
int Performance::GetTicketsSold() { return ticketsSold; }
void Performance::SetTicketsSold(int input) { ticketsSold = input; }
int Performance::GetNumPerformers() { return numPerformers; }
void Performance::SetNumPerformers(int input) { numPerformers = input; }
float Performance::GetPerfCost() { return perfCost; }
void Performance::SetPerfCost(float input) { perfCost = input; }
//vector<Performer> Performance::GetPerformerRoster() { return performerRoster; }
//void Performance::SetPerformerRoster(vector<Performer> input) { performerRoster = input; }
bool Performance::GetFullyCast() { return fullyCast; }
void Performance::SetFullyCast(bool input) { fullyCast = input; }
