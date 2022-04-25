#ifndef MUSICAL_HPP
#define MUSICAL_HPP

#include"performance.hpp"
#include"singer.hpp"
#include"musician.hpp"


class Musical : public Performance
{
    private:
        int numSingers = 0;
        int reqNumSingers = 1;
        vector<Singer> singerRoster;
        int numMusicians = 0;
        int reqNumMusicians = 1;
        vector<Musician> musicianRoster;

    public:
        Musical();
        Musical(int); // initialise Performance.perfID
        Musical(int, float); // initialise Performance.perfID, Performance.ticketPrice

        int GetNumSingers();
        void SetNumSingers(int);
        int GetReqNumSingers();
        void SetReqNumSingers(int);
        vector<Singer>& GetSingerRoster();
        void SetSingerRoster(vector<Singer>);
        int GetNumMusicians();
        void SetNumMusicians(int);
        int GetReqNumMusicians();
        void SetReqNumMusicians(int);
        vector<Musician>& GetMusicianRoster();
        void SetMusicianRoster(vector<Musician>);
};

#endif