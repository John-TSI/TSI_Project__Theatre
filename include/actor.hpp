#ifndef ACTOR_HPP
#define ACTOR_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Actor : public Performer
{
    private:
        string genre; // not currently being used 
        vector<string> genres = {};

    public:
        // --- constructors ---
        Actor(int); // initialise Employee.idNum
        Actor(int, float); // initialise Employee.idNum, Employee.salary

        // --- getters/setters ---
        string GetGenre();
        void SetGenre(string);
};

#endif