#include"../include/performer.hpp"
#include"../include/singer.hpp"


// --- constructors ---
Singer::Singer() {}
Singer::Singer(int idNum) : Performer(idNum) {}

// --- other methods ---
vector<string> Singer::GetStyles() { return styles; }