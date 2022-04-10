#include"../include/hall.hpp"


// --- constructors ---
PerformanceHall::PerformanceHall() {}
PerformanceHall::PerformanceHall(int hallNum) : hallNum(hallNum) {}


// --- getters/setters ---
int PerformanceHall::GetHallNum() { return hallNum; }
void PerformanceHall::SetHallNum(int input) { hallNum = input; }
int PerformanceHall::GetCapacity() { return capacity; }
void PerformanceHall::SetCapacity(int input) { capacity = input; }
bool PerformanceHall::GetScheduled() { return scheduled; }
void PerformanceHall::SetScheduled(bool input) { scheduled = input; }
Performance PerformanceHall::GetScheduledPerf() { return scheduledPerformance; }
void PerformanceHall::SetScheduledPerf(Performance input) { scheduledPerformance = input; }
bool PerformanceHall::GetStagePrepared() {return stagePrepared; }
void PerformanceHall::SetStagePrepared(bool input) { stagePrepared = input; }