#include<iostream>
#include"../include/hall.hpp"

using std::cout; using std::endl;

// --- constructors ---
PerformanceHall::PerformanceHall(int hallNum) : hallNum(hallNum) {}
PerformanceHall::PerformanceHall(int hallNum, int capacity) : hallNum(hallNum), capacity(capacity) {}


// --- getters/setters ---
int PerformanceHall::GetHallNum() { return hallNum; }
void PerformanceHall::SetHallNum(int input) { hallNum = input; }
int PerformanceHall::GetCapacity() { return capacity; }
void PerformanceHall::SetCapacity(int input) { capacity = input; }
bool PerformanceHall::GetIsBooked() { return isBooked; }
void PerformanceHall::SetIsBooked(bool input) { isBooked = input; }
bool PerformanceHall::GetHasPlay() { return hasPlay; }
void PerformanceHall::SetHasPlay(bool input) { hasPlay = input;}
bool PerformanceHall::GetHasMusical() { return hasMusical; }
void PerformanceHall::SetHasMusical(bool input) { hasMusical = input;}
Performance& PerformanceHall::GetScheduledPerf() { return scheduledPerformance; }
void PerformanceHall::SetScheduledPerf(Performance& input) { scheduledPerformance = input; }
Play& PerformanceHall::GetScheduledPlay() { return scheduledPlay; }
void PerformanceHall::SetScheduledPlay(Play& input) { scheduledPlay = input; }
Musical& PerformanceHall::GetScheduledMusical() { return scheduledMusical; }
void PerformanceHall::SetScheduledMusical(Musical& input) { scheduledMusical = input; }
bool PerformanceHall::GetStageIsPrepared() {return stageIsPrepared; }
void PerformanceHall::SetStageIsPrepared(bool input) { stageIsPrepared = input; }