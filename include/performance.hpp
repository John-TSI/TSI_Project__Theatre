#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; 
using std::vector;


class Performance
{
    private:
        int perfID = 0;
        bool isScheduled = false;
        int inHallNum = -1;
        float ticketPrice = 15.0f;
        int ticketsSold = 80;
        int numPerformers = 0; // is updated when (un)assigning, but not currently used
        float perfCost = 0.0f;
        bool isFullyCast = false;

    protected:
        Performance(int); // allow derived classes to initialise perfID
        Performance(int, float); // allow derived classes to initialise perfID and ticketPrice 
    
    public:
        Performance();

        int GetPerfID();
        void SetPerfID(int);
        bool GetIsScheduled();
        void SetIsScheduled(bool);
        int GetInHallNum();
        void SetInHallNum(int);
        float GetTicketPrice();
        void SetTicketPrice(float);
        int GetTicketsSold();
        void SetTicketsSold(int);
        int GetNumPerformers();
        void SetNumPerformers(int);
        float GetPerfCost();
        void SetPerfCost(float);
        bool GetIsFullyCast();
        void SetIsFullyCast(bool);
};

#endif