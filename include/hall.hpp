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
        int capacity = 0;
        bool scheduled = false;
        Performance scheduledPerformance;
        bool stagePrepared = false;
    
    protected:
        PerformanceHall(int);

    public:
        PerformanceHall();
        int GetHallNum();
        void SetHallNum(int);
        int GetCapacity();
        void SetCapacity(int);
        bool GetScheduled();
        void SetScheduled(bool);
        Performance GetScheduledPerf();
        void SetScheduledPerf(Performance);
        bool GetStagePrepared();
        void SetStagePrepared(bool);
};

#endif