#include"../include/performer.hpp"
#include"../include/singer.hpp"


// --- constructors ---
Singer::Singer(int idNum) : Performer(idNum) {}
Singer::Singer(int idNum, float salary) : Performer(idNum, salary) {}