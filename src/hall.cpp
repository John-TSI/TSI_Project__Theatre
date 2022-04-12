#include<iostream>
#include"../include/hall.hpp"

using std::cout; using std::endl;

// --- constructors ---
PerformanceHall::PerformanceHall() {}
PerformanceHall::PerformanceHall(int hallNum) : hallNum(hallNum) {}


// --- getters/setters ---
int PerformanceHall::GetHallNum() { return hallNum; }
void PerformanceHall::SetHallNum(int input) { hallNum = input; }
int PerformanceHall::GetCapacity() { return capacity; }
void PerformanceHall::SetCapacity(int input) { capacity = input; }
bool PerformanceHall::GetBooked() { return booked; }
void PerformanceHall::SetBooked(bool input) { booked = input; }
Performance PerformanceHall::GetScheduledPerf() { return scheduledPerformance; }
void PerformanceHall::SetScheduledPerf(Performance input) { scheduledPerformance = input; }
bool PerformanceHall::GetStagePrepared() {return stagePrepared; }
void PerformanceHall::SetStagePrepared(bool input) { stagePrepared = input; }

// --- utility ---
void PerformanceHall::PrintPerformance(Performance p)
{
    cout << p.GetPerfID();
}