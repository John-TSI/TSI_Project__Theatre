#ifndef PLAY_HPP
#define PLAY_HPP

#include<string>
#include<vector>
#include"performance.hpp"
#include"actor.hpp"


class Play : public Performance
{
    private:
        string genre;
        int numActors = 0;
        int reqNumActors = 1;
        vector<Actor> actorRoster = {}; 

    public:
        Play();
        Play(int);
        string GetGenre();
        void SetGenre(string);
        int GetNumActors();
        void SetNumActors(int);
        int GetReqNumActors();
        void SetReqNumActors(int);
        vector<Actor>& GetActorRoster();
        void SetActorRoster(vector<Actor>);

        void PrintActors(vector<Actor>);
        void CastActor(Actor, vector<Actor>&);
};

#endif