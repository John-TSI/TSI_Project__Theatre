#ifndef MUSICIAN_HPP
#define MUSICIAN_HPP

#include<string>
#include<vector>
#include"performer.hpp"

using std::string; using std::vector;


class Musician : public Performer
{
    private:
        vector<string> instruments = {};
    
    public:
        // --- constructors ---
        Musician();
        Musician(int);

        // --- getters/setters ---
        vector<string> GetInstruments();
};

#endif