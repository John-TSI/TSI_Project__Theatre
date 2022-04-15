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
        int actorCount = 0, actorIDcount = 0;
        int singerCount = 0, singerIDcount = 0;
        int musicianCount = 0, musicianIDcount = 0;
        int hallCount = 0, hallNumCount = 0;
        int playCount = 0, playIDcount = 0;
        int musicalCount = 0, musicalIDcount = 0;
        //bool allPerfsReady = true;

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
        void SetActorCount(int);
        int GetSingerCount();
        void SetSingerCount(int);
        int GetMusicianCount();
        void SetMusicianCount(int);
        int GetHallCount();
        void SetHallCount(int);
        int GetPlayCount();
        void SetPlayCount(int);
        int GetMusicalCount();
        void SetMusicalCount(int);
        // setters not required for vector attributes below
        vector<Actor>& GetActorList();
        vector<Singer>& GetSingerList();
        vector<Musician>& GetMusicianList();
        vector<PerformanceHall>& GetPerfHallList();
        vector<Play>& GetPlayList();
        vector<Musical>& GetMusicalList();


        // --- add/remove ---
        void AddActor(vector<Actor>&);
        void RmActor(int, vector<Actor>&);
        void AddSinger(vector<Singer>&);
        void RmSinger(int, vector<Singer>&);
        void AddMusician(vector<Musician>&);
        void RmMusician(int, vector<Musician>&);
        void AddPerfHall(vector<PerformanceHall>&);
        void RmPerfHall(int, vector<PerformanceHall>&);
        void AddPlay(vector<Play>&);
        void RmPlay(int, vector<Play>&);
        void AddMusical(vector<Musical>&);
        void RmMusical(int, vector<Musical>&);


        // --- (un)assign/(un)schedule ---
        void AssignActor(Actor&, vector<Actor>&, Play&);
        void UnassignActor(Actor&, vector<Actor>&, Play&);
        void AssignSinger(Singer&, vector<Singer>&, Musical&);
        void UnassignSinger(Singer&, vector<Singer>&, Musical&);
        void AssignMusician(Musician&, vector<Musician>&, Musical&);
        void UnassignMusician(Musician&, vector<Musician>&, Musical&);
        void SchedulePerformance(Performance&, PerformanceHall&);
        void UnschedulePerformance(Performance&, PerformanceHall&);


        // --- verifications ---
        bool IsFullyCast(Play&);
        bool IsFullyCast(Musical&);
        bool IsBooked(PerformanceHall&);
        //bool StageIsPrepared(PerformanceHall&);

        void CheckHallsStatus(vector<PerformanceHall>&);
        bool AllPerfsReady(vector<PerformanceHall>&);

        // ID verifiers
        bool VerifiedActorID(int, vector<Actor>);
        bool VerifiedSingerID(int, vector<Singer>);
        bool VerifiedMusicianID(int, vector<Musician>);
        bool VerifiedPlayID(int, vector<Play>);
        bool VerifiedMusicalID(int, vector<Musical>);
        bool VerifiedHallNum(int, vector<PerformanceHall>);


        // --- utility ---
        // finders
        Actor* FindActor(int, vector<Actor>&);
        Singer* FindSinger(int, vector<Singer>&);
        Musician* FindMusician(int, vector<Musician>&);
        PerformanceHall* FindPerfHall(int, vector<PerformanceHall>&);
        Play* FindPlay(int, vector<Play>&);
        Musical* FindMusical(int, vector<Musical>&);

        // ID printers
        // void PrintPerformers(auto);
        void PrintActors(vector<Actor>);
        void PrintAssignedActors(vector<Actor>);
        void PrintUnassignedActors(vector<Actor>);
        void PrintSingers(vector<Singer>);
        void PrintAssignedSingers(vector<Singer>);
        void PrintUnassignedSingers(vector<Singer>);
        void PrintMusicians(vector<Musician>);
        void PrintAssignedMusicians(vector<Musician>);
        void PrintUnassignedMusicians(vector<Musician>);
        void PrintHalls(vector<PerformanceHall>);
        void PrintPlays(vector<Play>);
        void PrintMusicals(vector<Musical>);

        // calculators
        float CalcPerfProfit(PerformanceHall);
        float CalcTotalProfit(vector<PerformanceHall>);
};

#endif