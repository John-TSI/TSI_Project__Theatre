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

        vector<Actor> actorList;
        vector<Singer> singerList;
        vector<Musician> musicianList;
        // technician stuff
        vector<PerformanceHall> perfHallList;
        vector<Play> playList;
        vector<Musical> musicalList;

    public:
        SystemManager();

        int GetActorCount();
        void SetActorCount(int);
        vector<Actor> GetActorList();

        //void AddActor(Actor);
        void AddActor(vector<Actor>&);
        void RmActor(int, vector<Actor>&);
        void AddSinger(Singer);
        void RmSinger(int, vector<Singer>&);
        void AddMusician(Musician);
        void RmMusician(int, vector<Musician>&);
        void AddPerfHall(PerformanceHall);
        void RmPerfHall(int, vector<PerformanceHall>&);
        void AddPlay(Play);
        void RmPlay(int, vector<Play>&);
        void AddMusical(Musical);
        void RmMusical(int, vector<Musical>&);


};

#endif