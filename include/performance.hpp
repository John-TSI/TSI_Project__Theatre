#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

#include<string>

using std::string;


class Performance
{
    private:
        string name = "Performance";
        int perfID = 0;
        int hallNum = 0;
        float ticketPrice = 0.0f;
        int ticketsSold = 0;
        bool fullyCast = false;

    protected:
        Performance(int); // allow derived classes to initialise Performance.perfID
    
    public:
        Performance();
        string GetName();
        void SetName(string);
        int GetPerfID();
        void SetPerfID(int);
        int GetHallNum();
        void SetHallNum(int);
        float GetTicketPrice();
        void SetTicketPrice(float);
        int GetTicketsSold();
        void SetTicketsSold(int);
        bool GetFullyCast();
        void SetFullyCast(bool);

};

#endif