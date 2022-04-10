#ifndef SINGER_HPP
#define SINGER_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Singer : public Performer
{
    private:
        vector<string> styles = {};

    public:
        // --- constructors ---
        Singer();
        Singer(int);

        // --- getters/setters ---
        vector<string> GetStyles();
};

#endif