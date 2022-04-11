#ifndef SYSMANAGER_HPP
#define SYSMANAGER_HPP

#include<string>
#include<vector>
#include"actor.hpp"
#include"singer.hpp"
#include"musician.hpp"
#include"hall.hpp"
#include"play.hpp"
#include"musical.hpp"

using std::string; using std::vector;


class SystemManager
{
    private:
        int actorCount = 0;
        int singerCount = 0;
        int musicianCount = 0;
        int hallCount = 0;
        int playCount = 0;
        int musicalCount = 0;

        vector<Actor> actorList;
        vector<Singer> singerList;
        vector<Musician> musicianList;
        // technician stuff
        vector<PerformanceHall> perfHallList;
        vector<Play> playList;
        vector<Musical> musicalList;

    public:
        SystemManager();

        // --- getters/setters ---
        int GetActorCount();
        int GetSingerCount();
        int GetMusicianCount();
        int GetHallCount();
        int GetPlayCount();
        int GetMusicalCount();
        vector<Actor> GetActorList();
        vector<Singer> GetSingerList();
        vector<Musician> GetMusicianList();
        vector<PerformanceHall> GetPerfHallList();
        vector<Play> GetPlayList();
        vector<Musical> GetMusicalList();

        // --- add/remove ---
        void AddActor(vector<Actor>&);
        void RmActor(int, vector<Actor>&);
        Actor FindActor(int, vector<Actor>&);
        void AddSinger(vector<Singer>&);
        void RmSinger(int, vector<Singer>&);
        Singer FindSinger(int, vector<Singer>&);
        void AddMusician(vector<Musician>&);
        void RmMusician(int, vector<Musician>&);
        Musician FindMusician(int, vector<Musician>&);
        void AddPerfHall(vector<PerformanceHall>&);
        void RmPerfHall(int, vector<PerformanceHall>&);
        PerformanceHall FindPerfHall(int, vector<PerformanceHall>&);
        void AddPlay(vector<Play>&);
        void RmPlay(int, vector<Play>&);
        Play FindPlay(int, vector<Play>&);
        void AddMusical(vector<Musical>&);
        void RmMusical(int, vector<Musical>&);
        Musical FindMusical(int, vector<Musical>&);

        // --- assign/schedule ---
        //void AssignActor(Actor, Play&);
        void AssignActor(Actor, vector<Actor>&);

        // --- utility ---
        void PrintActors(vector<Actor>);
        void PrintSingers(vector<Singer>);
        void PrintMusicians(vector<Musician>);
        void PrintHalls(vector<PerformanceHall>);
        void PrintPlays(vector<Play>);
        void PrintMusicals(vector<Musical>);

};

#endif