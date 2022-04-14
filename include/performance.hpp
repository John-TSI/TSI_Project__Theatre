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
        string name = "Performance";
        int perfID = 0;
        bool isScheduled = false;
        int inHallNum = -1;
        float ticketPrice = 12.0f;
        int ticketsSold = 80;
        int numPerformers = 0;
        float perfCost = 0.0f;
        //vector<Performer> performerRoster = {};
        bool isFullyCast = false;

    protected:
        Performance(int); // allow derived classes to initialise Performance.perfID
    
    public:
        Performance();
        string GetName();
        void SetName(string);
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
        //vector<Performer> GetPerformerRoster();
        //void SetPerformerRoster(vector<Performer>);
        bool GetIsFullyCast();
        void SetIsFullyCast(bool);

};

#endif