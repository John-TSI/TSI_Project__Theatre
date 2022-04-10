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
        vector<Actor> actorRoster = {}; 

    public:
        Play();
        Play(int);
        string GetGenre();
        void SetGenre(string);
        int GetNumActors();
        void SetNumActors(int);
        vector<Actor> GetActorRoster();
        void SetActorRoster(vector<Actor>);
};

#endif