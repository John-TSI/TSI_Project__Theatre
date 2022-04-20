#ifndef MUSICAL_HPP
#define MUSICAL_HPP

#include"performance.hpp"
#include"singer.hpp"
#include"musician.hpp"


class Musical : public Performance
{
    private:
        string style; // not currently being used
        int numSingers = 0;
        int reqNumSingers = 1;
        vector<Singer> singerRoster;
        vector<string> requiredInstruments;  // not currently being used
        int numMusicians = 0;
        int reqNumMusicians = 1;
        vector<Musician> musicianRoster;

    public:
        Musical(int); // initialise Performance.perfID
        Musical(int, float); // initialise Performance.perfID, Performance.ticketPrice

        string GetStyle();
        void SetStyle(string);
        int GetNumSingers();
        void SetNumSingers(int);
        int GetReqNumSingers();
        void SetReqNumSingers(int);
        vector<Singer>& GetSingerRoster();
        void SetSingerRoster(vector<Singer>);
        vector<string> GetRequiredInstruments();
        void SetRequiredInstruments(vector<string>);
        int GetNumMusicians();
        void SetNumMusicians(int);
        int GetReqNumMusicians();
        void SetReqNumMusicians(int);
        vector<Musician>& GetMusicianRoster();
        void SetMusicianRoster(vector<Musician>);
};

#endif