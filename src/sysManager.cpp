
#include<iostream>
#include<algorithm>
#include"../include/sysManager.hpp"

using std::cout; using std::endl;


// --- constructors ---
SystemManager::SystemManager() {}


// --- getters/setters ---
int SystemManager::GetActorCount() { return actorCount; }
int SystemManager::GetSingerCount() { return singerCount; }
int SystemManager::GetMusicianCount() { return musicianCount; }
int SystemManager::GetHallCount() { return hallCount; }
int SystemManager::GetPlayCount() { return playCount; }
int SystemManager::GetMusicalCount() { return musicalCount; }
vector<Actor> SystemManager::GetActorList() { return actorList; }
vector<Singer> SystemManager::GetSingerList() { return singerList; }
vector<Musician> SystemManager::GetMusicianList() { return musicianList; }
vector<PerformanceHall> SystemManager::GetPerfHallList() { return perfHallList; }
vector<Play> SystemManager::GetPlayList() { return playList; }
vector<Musical> SystemManager::GetMusicalList() { return musicalList; }


// --- add/remove ---
void SystemManager::AddActor(vector<Actor>& aList)
{
    aList.push_back(Actor(GetActorCount() ) );
    actorCount++;
}

void SystemManager::RmActor(int idNum, vector<Actor>& aList)
{
    aList.erase(std::remove_if(begin(aList), end(aList), 
        [idNum](Actor& a) { return a.GetIDNum() == idNum; }
    ), end(aList));
}

void SystemManager::AddSinger(vector<Singer>& sList)
{
    sList.push_back(Singer(GetSingerCount() ) );
    singerCount++;
}

void SystemManager::RmSinger(int idNum, vector<Singer>& sList)
{
    sList.erase(std::remove_if(begin(sList), end(sList), 
        [idNum](Singer& s) { return s.GetIDNum() == idNum; }
    ), end(sList));
}

void SystemManager::AddMusician(vector<Musician>& mList)
{
    mList.push_back(Musician(GetMusicianCount() ) );
    musicianCount++;
}

void SystemManager::RmMusician(int idNum, vector<Musician>& mList)
{
    mList.erase(std::remove_if(begin(mList), end(mList), 
        [idNum](Musician& m) { return m.GetIDNum() == idNum; }
    ), end(mList));
}

void SystemManager::AddPerfHall(vector<PerformanceHall>& pHList)
{
    pHList.push_back(PerformanceHall(GetHallCount() ) );
    hallCount++;
}

void SystemManager::RmPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    pHList.erase(std::remove_if(begin(pHList), end(pHList), 
        [hallNum](PerformanceHall& pH) { return pH.GetHallNum() == hallNum; }
    ), end(pHList));
}

void SystemManager::AddPlay(vector<Play>& pList)
{
    pList.push_back((GetPlayCount() ) );
    playCount++;
}

void SystemManager::RmPlay(int perfID, vector<Play>& pList)
{
    pList.erase(std::remove_if(begin(pList), end(pList), 
        [perfID](Play& p) { return p.GetPerfID() == perfID; }
    ), end(pList));
}

void SystemManager::AddMusical(vector<Musical>& mList)
{
    mList.push_back(Musical(GetMusicalCount() ) );
    musicalCount++;
}

void SystemManager::RmMusical(int perfID, vector<Musical>& mList)
{
    mList.erase(std::remove_if(begin(mList), end(mList), 
        [perfID](Musical& m) { return m.GetPerfID() == perfID; }
    ), end(mList));
}


// --- assign/schedule ---


/* void SystemManager::AssignActor(int idNum, int perfID)
{
    Actor a = FindActor(idNum, actorList);
    Play p = FindPlay(perfID, playList);
    vector<Actor> roster = p.GetActorRoster();
	//roster.push_back(a);
    p.CastActor(a, roster);
} */


void SystemManager::AssignActor(Actor a, vector<Actor>& va, Play& p)
{
    //vector<Actor> roster = p.GetActorRoster();
    //roster.push_back(a);
    va.push_back(a);
    p.SetActorRoster(va);
    p.SetNumActors(p.GetNumActors() + 1);
}
// this one works
/* void SystemManager::AssignActor(Actor a, vector<Actor>& aList)
{
    aList.push_back(a);
} */ 


// --- utility ---
Actor SystemManager::FindActor(int idNum, vector<Actor>& aList)
{
    auto a_it = std::find_if(aList.begin(), aList.end(), [idNum](Actor& a) {return a.GetIDNum() == idNum;});
    Actor actor = *a_it;
    return actor;
}

Singer SystemManager::FindSinger(int idNum, vector<Singer>& sList)
{
    auto s_it = std::find_if(sList.begin(), sList.end(), [idNum](Singer& s) {return s.GetIDNum() == idNum;});
    Singer singer = *s_it;
    return singer;
}

Musician SystemManager::FindMusician(int idNum, vector<Musician>& mList)
{
    auto m_it = std::find_if(mList.begin(), mList.end(), [idNum](Musician& m) {return m.GetIDNum() == idNum;});
    Musician musician = *m_it;
    return musician;
}

PerformanceHall SystemManager::FindPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    auto pH_it = std::find_if(pHList.begin(), pHList.end(), [hallNum](PerformanceHall& pH) {return pH.GetHallNum() == hallNum;});
    PerformanceHall hall = *pH_it;
    return hall;
}

Play SystemManager::FindPlay(int perfID, vector<Play>& pList)
{
    auto p_it = std::find_if(pList.begin(), pList.end(), [perfID](Play& p) {return p.GetPerfID() == perfID;});
    Play play = *p_it;
    return play;
}

Musical SystemManager::FindMusical(int perfID, vector<Musical>& mList)
{
    auto m_it = std::find_if(mList.begin(), mList.end(), [perfID](Musical& m) {return m.GetPerfID() == perfID;});
    Musical musical = *m_it;
    return musical;
}

void SystemManager::PrintActors(vector<Actor> vec)
{
    for(Actor a : vec) { cout << a.GetIDNum() << " "; }
}

void SystemManager::PrintSingers(vector<Singer> vec)
{
    for(Singer s : vec) { cout << s.GetIDNum() << " "; }
}

void SystemManager::PrintMusicians(vector<Musician> vec)
{
    for(Musician m : vec) { cout << m.GetIDNum() << " "; }
}

void SystemManager::PrintHalls(vector<PerformanceHall> vec)
{
    for(PerformanceHall hall : vec) { cout << hall.GetHallNum() << " "; }
}

void SystemManager::PrintPlays(vector<Play> vec)
{
    for(Play p : vec) { cout << p.GetPerfID() << " "; }
}

void SystemManager::PrintMusicals(vector<Musical> vec)
{
    for(Musical m : vec) { cout << m.GetPerfID() << " "; }
}