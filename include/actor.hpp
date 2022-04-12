#ifndef ACTOR_HPP
#define ACTOR_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Actor : public Performer
{
    private:
        string genre; // test attribute, remove 
        vector<string> genres = {};

    public:
        // --- constructors ---
        Actor();
        Actor(int);
        Actor(int,string);

        // --- getters/setters ---
        vector<string> GetGenres();
};

#endif