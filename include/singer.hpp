#ifndef SINGER_HPP
#define SINGER_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Singer : public Performer
{
    private:
        vector<string> styles = {}; // not currently being used

    public:
        // --- constructors ---
        Singer(int);  // initialise Employee.idNum
        Singer(int, float); // initialise Employee.idNum, Employee.salary

        // --- getters/setters ---
        vector<string> GetStyles();
};

#endif