#include"../include/performance.hpp"

// --- constructors ---
Performance::Performance() {}
Performance::Performance(int perfID) : perfID(perfID) {}


// --- getters/setters ---
string Performance::GetName() { return name; }
void Performance::SetName(string input) { name = input; }
int Performance::GetPerfID() { return perfID; }
void Performance::SetPerfID(int input) { perfID = input; }
int Performance::GetHallNum() { return hallNum; }
void Performance::SetHallNum(int input) { hallNum = input; }
float Performance::GetTicketPrice() { return ticketPrice; }
void Performance::SetTicketPrice(float input) { ticketPrice = input; }
int Performance::GetTicketsSold() { return ticketsSold; }
void Performance::SetTicketsSold(int input) { ticketsSold = input; }
bool Performance::GetFullyCast() { return fullyCast; }
void Performance::SetFullyCast(bool input) { fullyCast = input; }
