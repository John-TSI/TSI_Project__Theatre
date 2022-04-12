#ifndef MUSICAL_HPP
#define MUSICAL_HPP

#include"performance.hpp"
#include"singer.hpp"
#include"musician.hpp"


class Musical : public Performance
{
    private:
        string style;
        int numSingers = 0;
        int reqNumSingers = 1;
        vector<Singer> singerRoster;
        vector<string> requiredInstruments;
        int numMusicians = 0;
        int reqNumMusicians = 1;
        vector<Musician> musicianRoster;

    public:
        Musical();
        Musical(int);
        string GetStyle();
        void SetStyle(string);
        int GetNumSingers();
        void SetNumSingers(int);
        int GetReqNumSingers();
        void SetReqNumSingers(int);
        vector<Singer> GetSingerRoster();
        void SetSingerRoster(vector<Singer>);
        vector<string> GetRequiredInstruments();
        void SetRequiredInstruments(vector<string>);
        int GetNumMusicians();
        void SetNumMusicians(int);
        int GetReqNumMusicians();
        void SetReqNumMusicians(int);
        vector<Musician> GetMusicianRoster();
        void SetMusicianRoster(vector<Musician>);

        void PrintSingers(vector<Singer>);
        void CastSinger(Singer, vector<Singer>&);
        void PrintMusicians(vector<Musician>);
        void CastMusician(Musician, vector<Musician>&);
};

#endif