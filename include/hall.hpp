#ifndef HALL_HPP
#define HALL_HPP

#include<string>
#include"../include/performance.hpp"
#include"../include/play.hpp"
#include"../include/musical.hpp"

using std::string;


class PerformanceHall
{
    private:
        string name = "Performance Hall";
        int hallNum = 0;
        int capacity = 150;
        bool isBooked = false;
        bool hasPlay = false, hasMusical = false;
        Performance scheduledPerformance;
        Play scheduledPlay;
        Musical scheduledMusical;
        bool stageIsPrepared = false;  // not currently being used

    public:
        PerformanceHall();
        PerformanceHall(int); // initialise hallNum
        PerformanceHall(int, int); // initialise hallNum and capacity

        int GetHallNum();
        void SetHallNum(int);
        int GetCapacity();
        void SetCapacity(int);
        bool GetIsBooked();
        void SetIsBooked(bool);
        bool GetHasPlay(); bool GetHasMusical();
        void SetHasPlay(bool); void SetHasMusical(bool);
        Performance& GetScheduledPerf();
        void SetScheduledPerf(Performance&);
        Play& GetScheduledPlay();
        void SetScheduledPlay(Play&);
        Musical& GetScheduledMusical();
        void SetScheduledMusical(Musical&);
        bool GetStageIsPrepared();
        void SetStageIsPrepared(bool);
};

#endif