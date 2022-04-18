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
bool PerformanceHall::GetIsBooked() { return isBooked; }
void PerformanceHall::SetIsBooked(bool input) { isBooked = input; }
Performance PerformanceHall::GetScheduledPerf() { return scheduledPerformance; }
void PerformanceHall::SetScheduledPerf(Performance input) { scheduledPerformance = input; }
// test
Play& PerformanceHall::GetScheduledPlay() { return scheduledPlay; }
void PerformanceHall::SetScheduledPlay(Play& input) { scheduledPlay = input; }
Musical& PerformanceHall::GetScheduledMusical() { return scheduledMusical; }
void PerformanceHall::SetScheduledMusical(Musical& input) { scheduledMusical = input; }
// end test
bool PerformanceHall::GetStageIsPrepared() {return stageIsPrepared; }
void PerformanceHall::SetStageIsPrepared(bool input) { stageIsPrepared = input; }

// --- utility ---
void PerformanceHall::PrintPerformance(Performance p)
{
    cout << p.GetPerfID();
}