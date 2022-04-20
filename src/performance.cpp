#include"../include/performance.hpp"

// --- constructors ---
Performance::Performance() {}
Performance::Performance(int perfID) : perfID(perfID) {}
Performance::Performance(int perfID, float ticketPrice) : perfID(perfID), ticketPrice(ticketPrice) {}


// --- getters/setters ---
string Performance::GetName() { return name; }
void Performance::SetName(string input) { name = input; }
int Performance::GetPerfID() { return perfID; }
void Performance::SetPerfID(int input) { perfID = input; }
bool Performance::GetIsScheduled() { return isScheduled; }
void Performance::SetIsScheduled(bool input) { isScheduled = input; }
int Performance::GetInHallNum() { return inHallNum; }
void Performance::SetInHallNum(int input) { inHallNum = input; }
float Performance::GetTicketPrice() { return ticketPrice; }
void Performance::SetTicketPrice(float input) { ticketPrice = input; }
int Performance::GetTicketsSold() { return ticketsSold; }
void Performance::SetTicketsSold(int input) { ticketsSold = input; }
int Performance::GetNumPerformers() { return numPerformers; }
void Performance::SetNumPerformers(int input) { numPerformers = input; }
float Performance::GetPerfCost() { return perfCost; }
void Performance::SetPerfCost(float input) { perfCost = input; }
bool Performance::GetIsFullyCast() { return isFullyCast; }
void Performance::SetIsFullyCast(bool input) { isFullyCast = input; }
