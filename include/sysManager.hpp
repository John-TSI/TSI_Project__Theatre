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
        void AddActor(vector<Actor>&, float = 120.00f);
        void RmActor(int, vector<Actor>&, bool);
        void AddSinger(vector<Singer>&, float = 120.00f);
        void RmSinger(int, vector<Singer>&, bool);
        void AddMusician(vector<Musician>&, float = 120.00f);
        void RmMusician(int, vector<Musician>&, bool);
        void AddPlay(vector<Play>&, float = 15.0f);
        void RmPlay(int, vector<Play>&);
        void AddMusical(vector<Musical>&, float = 15.0f);
        void RmMusical(int, vector<Musical>&);
        void AddPerfHall(vector<PerformanceHall>&, int = 150);
        void RmPerfHall(int, vector<PerformanceHall>&);


        // --- (un)assign/(un)schedule ---
        void AssignActor(Actor&, Play&);
        void AssignActor(Actor&, Play&, PerformanceHall&);  // overload, use if Play scheduled
        void UnassignActor(Actor&, Play&);
        void UnassignActor(Actor&, Play&, PerformanceHall&);
        void AssignSinger(Singer&, Musical&);
        void AssignSinger(Singer&, Musical&, PerformanceHall&);  // overload, use if Musical scheduled
        void UnassignSinger(Singer&, Musical&);
        void UnassignSinger(Singer&, Musical&, PerformanceHall&);
        void AssignMusician(Musician&, Musical&);
        void AssignMusician(Musician&, Musical&, PerformanceHall&);  // overload, use if Musical scheduled
        void UnassignMusician(Musician&, Musical&);
        void UnassignMusician(Musician&, Musical&, PerformanceHall&);
        void SchedulePlay(Play&, PerformanceHall&);
        void UnschedulePlay(Play&, PerformanceHall&);
        void ScheduleMusical(Musical&, PerformanceHall&);
        void UnscheduleMusical(Musical&, PerformanceHall&);


        // --- utility/verification ---
        // check status
        bool AllPerfsReady(vector<PerformanceHall>&); // remove?

        void CheckActorsStatus(vector<Actor>);
        void CheckSingersStatus(vector<Singer>);
        void CheckMusiciansStatus(vector<Musician>);
        void CheckPlaysStatus(vector<Play>);
        void CheckMusicalsStatus(vector<Musical>);
        void CheckHallsStatus(vector<PerformanceHall>);

        // ID verifiers
        bool VerifiedActorID(int, vector<Actor>);
        bool VerifiedSingerID(int, vector<Singer>);
        bool VerifiedMusicianID(int, vector<Musician>);
        bool VerifiedPlayID(int, vector<Play>);
        bool VerifiedMusicalID(int, vector<Musical>);
        bool VerifiedHallNum(int, vector<PerformanceHall>);

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


        // --- modify/calculate ---
        // modify
        void ToggleSpecifyMode(bool&);

        void ModifyActorSalary(Actor&, float);
        void ModifyActorSalary(Actor&, int, Play&, float); // overload, used if Actor is assigned
        void ModifyActorSalary(Actor&, int, Play&, PerformanceHall&, float); // overload, used if Play is scheduled
        void ModifySingerSalary(Singer&, float);
        void ModifySingerSalary(Singer&, int, Musical&, float);
        void ModifySingerSalary(Singer&, int, Musical&, PerformanceHall&, float);
        void ModifyMusicianSalary(Musician&, float);
        void ModifyMusicianSalary(Musician&, int, Musical&, float);
        void ModifyMusicianSalary(Musician&, int, Musical&, PerformanceHall&, float);
        // TEST methods
        void ModifyReqNumActors(Play&, int);
        void ModifyReqNumActors(Play&, PerformanceHall&, int); // overload, used if Play is scheduled
        // END TEST
        void ModifyPlayTicketPrice(Play&, float);
        void ModifyPlayTicketPrice(Play&, PerformanceHall&, float); // overload, used if Play is scheduled
        void ModifyPlayTicketsSold(Play&, int);
        void ModifyPlayTicketsSold(Play&, PerformanceHall&, int); // overload, used if Play is scheduled
        void ModifyMusicalTicketPrice(Musical&, float);
        void ModifyMusicalTicketPrice(Musical&, PerformanceHall&, float);
        void ModifyMusicalTicketsSold(Musical&, int);
        void ModifyMusicalTicketsSold(Musical&, PerformanceHall&, int);
        void ModifyHallCapacity(PerformanceHall&, int);

        // --- calculators ---
        float CalcPerfProfit(PerformanceHall, bool);
        float CalcTotalProfit(vector<PerformanceHall>, bool);
};

#endif