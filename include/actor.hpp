#ifndef ACTOR_HPP
#define ACTOR_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Actor : public Performer
{
    private:
        string genre; // remove? 
        vector<string> genres = {};

    public:
        // --- constructors ---
        Actor(int); // initialise Employee.idNum
        Actor(int, float); // initialise Employee.idNum, Employee.salary
        //Actor(int, string);

        // --- getters/setters ---
        vector<string> GetGenres();
};

#endif