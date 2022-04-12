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
        bool scheduled = false;
        int hallNum = 0;
        float ticketPrice = 12.0f;
        int ticketsSold = 80;
        int numPerformers = 0;
        float perfCost = 0.0f;
        //vector<Performer> performerRoster = {};
        bool fullyCast = false;

    protected:
        Performance(int); // allow derived classes to initialise Performance.perfID
    
    public:
        Performance();
        string GetName();
        void SetName(string);
        int GetPerfID();
        void SetPerfID(int);
        bool GetScheduled();
        void SetScheduled(bool);
        int GetHallNum();
        void SetHallNum(int);
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
        bool GetFullyCast();
        void SetFullyCast(bool);

};

#endif