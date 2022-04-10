
#include<algorithm>
#include"../include/sysManager.hpp"


// --- constructors ---
SystemManager::SystemManager() {}


// --- getters/setters ---
int SystemManager::GetActorCount() { return actorCount; }
void SystemManager::SetActorCount(int input) { actorCount = input; }
vector<Actor> SystemManager::GetActorList() { return actorList; }


// --- other methods ---
/* void SystemManager::AddActor(Actor a)
{
    actorList.push_back(a);
} */
void SystemManager::AddActor(vector<Actor>& aList)
{
    aList.push_back(Actor(GetActorCount()));
    actorCount++;
}

void SystemManager::RmActor(int idNum, vector<Actor>& aList)
{
    aList.erase(std::remove_if(begin(aList), end(aList), 
        [idNum](Actor& a) { return a.GetIDNum() == idNum; }
    ), end(aList));
}

void SystemManager::AddSinger(Singer s)
{
    singerList.push_back(s);
}

void SystemManager::RmSinger(int idNum, vector<Singer>& sList)
{
    sList.erase(std::remove_if(begin(sList), end(sList), 
        [idNum](Singer& s) { return s.GetIDNum() == idNum; }
    ), end(sList));
}

void SystemManager::AddMusician(Musician m)
{
    musicianList.push_back(m);
}

void SystemManager::RmMusician(int idNum, vector<Musician>& mList)
{
    mList.erase(std::remove_if(begin(mList), end(mList), 
        [idNum](Musician& m) { return m.GetIDNum() == idNum; }
    ), end(mList));
}

void SystemManager::AddPerfHall(PerformanceHall pH)
{
    perfHallList.push_back(pH);
}

void SystemManager::RmPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    pHList.erase(std::remove_if(begin(pHList), end(pHList), 
        [hallNum](PerformanceHall& pH) { return pH.GetHallNum() == hallNum; }
    ), end(pHList));
}

void SystemManager::AddPlay(Play p)
{
    playList.push_back(p);
}

void SystemManager::RmPlay(int perfID, vector<Play>& pList)
{
    pList.erase(std::remove_if(begin(pList), end(pList), 
        [perfID](Play& p) { return p.GetPerfID() == perfID; }
    ), end(pList));
}

void SystemManager::AddMusical(Musical m)
{
    musicalList.push_back(m);
}

void SystemManager::RmMusical(int perfID, vector<Musical>& mList)
{
    mList.erase(std::remove_if(begin(mList), end(mList), 
        [perfID](Musical& m) { return m.GetPerfID() == perfID; }
    ), end(mList));
}