#ifndef MUSICIAN_HPP
#define MUSICIAN_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Musician : public Performer
{
    private:
        vector<string> instruments = {}; // not currently being used
    
    public:
        // --- constructors ---
        Musician(int);  // initialise Employee.idNum
        Musician(int, float); // initialise Employee.idNum, Employee.salary

        // --- getters/setters ---
        vector<string> GetInstruments();
};

#endif