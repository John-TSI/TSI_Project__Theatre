#ifndef HALL_HPP
#define HALL_HPP

#include<string>
#include"../include/performance.hpp"
// test includes
#include"../include/play.hpp"
#include"../include/musical.hpp"

using std::string;


class PerformanceHall
{
    private:
        string name = "Performance Hall";
        int hallNum = 0;
        int capacity = 100;
        bool isBooked = false;
        Performance scheduledPerformance;
        //test attributes
        Play scheduledPlay;
        Musical scheduledMusical;
        // end test
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
        // test methods
        Play& GetScheduledPlay();
        void SetScheduledPlay(Play&);
        Musical& GetScheduledMusical();
        void SetScheduledMusical(Musical&);
        // end test
        bool GetStageIsPrepared();
        void SetStageIsPrepared(bool);

        void PrintPerformance(Performance);
};

#endif