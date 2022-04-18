#ifndef SYSMANAGER_HPP
#define SYSMANAGER_HPP

#include<string>
#include<vector>
#include"actor.hpp"
#include"singer.hpp"
#include"musician.hpp"
#include"play.hpp"
#include"musical.hpp"
#include"hall.hpp"

using std::string; using std::vector;


class SystemManager
{
    private:
        int actorCount = 0, actorIDcount = 0;
        int singerCount = 0, singerIDcount = 0;
        int musicianCount = 0, musicianIDcount = 0;
        int playCount = 0, playIDcount = 0;
        int musicalCount = 0, musicalIDcount = 0;
        int hallCount = 0, hallNumCount = 0;
        //bool allPerfsReady = true;

        vector<Actor> actorList;
        vector<Singer> singerList;
        vector<Musician> musicianList;
        // technician stuff
        vector<Play> playList;
        vector<Musical> musicalList;
        vector<PerformanceHall> perfHallList;


    public:
        SystemManager();

        // --- getters/setters ---
        int GetActorCount();
        void SetActorCount(int);
        int GetSingerCount();
        void SetSingerCount(int);
        int GetMusicianCount();
        void SetMusicianCount(int);
        int GetPlayCount();
        void SetPlayCount(int);
        int GetMusicalCount();
        void SetMusicalCount(int);
        int GetHallCount();
        void SetHallCount(int);
        // setters not required for vector attributes below
        vector<Actor>& GetActorList();
        vector<Singer>& GetSingerList();
        vector<Musician>& GetMusicianList();
        vector<Play>& GetPlayList();
        vector<Musical>& GetMusicalList();
        vector<PerformanceHall>& GetPerfHallList();


        // --- add/remove ---
        void AddActor(vector<Actor>&);
        void RmActor(int, vector<Actor>&, bool);
        void RemoveActor(int, Actor&, vector<Actor>&, bool, vector<Actor>&, Play&, bool);
        void AddSinger(vector<Singer>&);
        void RmSinger(int, vector<Singer>&, bool);
        void AddMusician(vector<Musician>&);
        void RmMusician(int, vector<Musician>&, bool);
        void AddPlay(vector<Play>&);
        void RmPlay(int, vector<Play>&); // START HERE in cpp
        void AddMusical(vector<Musical>&);
        void RmMusical(int, vector<Musical>&);
        void AddPerfHall(vector<PerformanceHall>&);
        void RmPerfHall(int, vector<PerformanceHall>&);


        // --- (un)assign/(un)schedule ---
        void AssignActor(Actor&, vector<Actor>&, Play&);
        void UnassignActor(Actor&, vector<Actor>&, Play&);
        void AssignSinger(Singer&, vector<Singer>&, Musical&);
        void UnassignSinger(Singer&, vector<Singer>&, Musical&);
        void AssignMusician(Musician&, vector<Musician>&, Musical&);
        void UnassignMusician(Musician&, vector<Musician>&, Musical&);
        //void SchedulePerformance(Performance&, PerformanceHall&);
        //void UnschedulePerformance(Performance&, PerformanceHall&);
        // test methods
        void SchedulePlay(Play&, PerformanceHall&);
        void UnschedulePlay(Play&, PerformanceHall&);
        void ScheduleMusical(Musical&, PerformanceHall&);
        void UnscheduleMusical(Musical&, PerformanceHall&);
        // end test


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
        Play* FindPlay(int, vector<Play>&);
        Musical* FindMusical(int, vector<Musical>&);
        PerformanceHall* FindPerfHall(int, vector<PerformanceHall>&);

        // ID printers
        void PrintActors(vector<Actor>);
        void PrintAssignedActors(vector<Actor>);
        void PrintUnassignedActors(vector<Actor>);
        void PrintSingers(vector<Singer>);
        void PrintAssignedSingers(vector<Singer>);
        void PrintUnassignedSingers(vector<Singer>);
        void PrintMusicians(vector<Musician>);
        void PrintAssignedMusicians(vector<Musician>);
        void PrintUnassignedMusicians(vector<Musician>);

        void PrintPlays(vector<Play>);
        void PrintScheduledPlays(vector<Play>);
        void PrintUnscheduledPlays(vector<Play>);
        void PrintMusicals(vector<Musical>);
        void PrintScheduledMusicals(vector<Musical>);
        void PrintUnscheduledMusicals(vector<Musical>);

        void PrintHalls(vector<PerformanceHall>);
        void PrintBookedHalls(vector<PerformanceHall>);
        void PrintAvailableHalls(vector<PerformanceHall>);

        // modifiers
        //void ModifyActorSalary(int, vector<Actor>&, float);
        void ModifyActorSalary(Actor&, float);
        void ModifySingerSalary(int, vector<Singer>&, float);
        void ModifyMusicianSalary(int, vector<Musician>&, float);
        void ModifyPlayTicketPrice(int, vector<Play>&, float);
        void ModifyMusicalTicketPrice(int, vector<Musical>&, float);

        // calculators
        float CalcPerfProfit(PerformanceHall, bool);
        float CalcTotalProfit(vector<PerformanceHall>, bool);
};

#endif