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
        bool booked = false;
        Performance scheduledPerformance;
        bool stagePrepared = false;

    public:
        PerformanceHall();
        PerformanceHall(int);
        int GetHallNum();
        void SetHallNum(int);
        int GetCapacity();
        void SetCapacity(int);
        bool GetBooked();
        void SetBooked(bool);
        Performance GetScheduledPerf();
        void SetScheduledPerf(Performance);
        bool GetStagePrepared();
        void SetStagePrepared(bool);

        void PrintPerformance(Performance);
};

#endif