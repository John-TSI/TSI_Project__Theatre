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
        vector<Singer> singerRoster;
        vector<string> requiredInstruments;
        int numMusicians = 0;
        vector<Musician> musicianRoster;

    protected:
        Musical(int);

    public:
        Musical();
        string GetStyle();
        void SetStyle(string);
        int GetNumSingers();
        void SetNumSingers(int);
        vector<Singer> GetSingerRoster();
        void SetSingerRoster(vector<Singer>);
        vector<string> GetRequiredInstruments();
        void SetRequiredInstruments(vector<string>);
        int GetNumMusicians();
        void SetNumMusicians(int);
        vector<Musician> GetMusicianRoster();
        void SetMusicianRoster(vector<Musician>);
};

#endif