#ifndef HALL_HPP
#define HALL_HPP

#include<string>
#include"../include/performance.hpp"

using std::string;


class PerformanceHall
{
    private:
        string name = "Performance Hall";
        int hallNum = 0;
        int capacity = 100;
        bool isBooked = false;
        Performance scheduledPerformance;
        bool stageIsPrepared = false;

    public:
        PerformanceHall();
        PerformanceHall(int);
        int GetHallNum();
        void SetHallNum(int);
        int GetCapacity();
        void SetCapacity(int);
        bool GetIsBooked();
        void SetIsBooked(bool);
        Performance GetScheduledPerf();
        void SetScheduledPerf(Performance);
        bool GetStageIsPrepared();
        void SetStageIsPrepared(bool);

        void PrintPerformance(Performance);
};

#endif