
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
vector<Actor>& SystemManager::GetActorList() { return actorList; }
vector<Singer>& SystemManager::GetSingerList() { return singerList; }
vector<Musician>& SystemManager::GetMusicianList() { return musicianList; }
vector<PerformanceHall>& SystemManager::GetPerfHallList() { return perfHallList; }
vector<Play>& SystemManager::GetPlayList() { return playList; }
vector<Musical>& SystemManager::GetMusicalList() { return musicalList; }


// --- add/remove ---
void SystemManager::AddActor(vector<Actor>& aList)
{
    aList.push_back(Actor(GetActorCount() ) );
    actorCount++;
} 
/* void SystemManager::AddActor()
{
    actorList.push_back(Actor(GetActorCount() ) );
    actorCount++;
} */

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

void SystemManager::AssignActor(Actor& a, vector<Actor>& va, Play& p)
{
    a.SetAssigned(true);
    va.push_back(a);
    p.SetActorRoster(va);
    p.SetNumActors(p.GetNumActors() + 1);
    if(p.GetNumActors() >= p.GetReqNumActors())
    {
        p.SetFullyCast(true);
    }
}

void SystemManager::AssignSinger(Singer& s, vector<Singer>& vs, Musical& mu)
{
    s.SetAssigned(true);
    vs.push_back(s);
    mu.SetSingerRoster(vs);
    mu.SetNumSingers(mu.GetNumSingers() + 1);
    if((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians()))
    {
        mu.SetFullyCast(true);
    }
}

void SystemManager::AssignMusician(Musician& m, vector<Musician>& vm, Musical& mu)
{
    m.SetAssigned(true);
    vm.push_back(m);
    mu.SetMusicianRoster(vm);
    mu.SetNumMusicians(mu.GetNumMusicians() + 1);
    if((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians()))
    {
        mu.SetFullyCast(true);
    }
}

void SystemManager::SchedulePlay(Play& p, PerformanceHall& h)
{
    p.SetScheduled(true);
    p.SetHallNum(h.GetHallNum());
    h.SetBooked(true);
    h.SetScheduledPerf(p);
}

void SystemManager::ScheduleMusical(Musical& m, PerformanceHall& h)
{
    m.SetScheduled(true);
    m.SetHallNum(h.GetHallNum());
    h.SetBooked(true);
    h.SetScheduledPerf(m);
}


// --- verifications ---
// are these four needed?
bool SystemManager::IsFullyCast(Play& p) { return p.GetFullyCast(); }
bool SystemManager::IsFullyCast(Musical& m) { return m.GetFullyCast(); }
bool SystemManager::IsBooked(PerformanceHall& h) { return h.GetBooked(); }
bool SystemManager::StageIsPrepared(PerformanceHall& h) { return h.GetStagePrepared(); }

void SystemManager::CheckHallsStatus(vector<PerformanceHall>& hList)
{
    for(PerformanceHall h : hList)
	{	
        int hallNum = h.GetHallNum();
		int perfNum =  h.GetScheduledPerf().GetPerfID();
		(h.GetBooked()) ? cout << "Hall number " << hallNum << " is booked with performance number " << perfNum << "." << endl : cout << "Hall number " << hallNum << " is not booked." << endl;
		if(h.GetBooked())
        {
            (h.GetScheduledPerf().GetFullyCast()) ? cout << "Scheduled performance is fully cast!\n" << endl : cout << "Scheduled performance has insufficient performers!\n" << endl;
        }
	}
}

bool SystemManager::AllPerfsReady(vector<PerformanceHall>& hList)
{
    bool allPerfsReady = true;
    for(PerformanceHall h : hList)
	{	
		if(h.GetBooked())
        {
            if(!h.GetScheduledPerf().GetFullyCast()) { allPerfsReady = false; }
        }
	}
    return allPerfsReady;
}


// --- utility ---
/* Actor SystemManager::FindActor(int idNum, vector<Actor>& aList)
{
    auto a_it = std::find_if(aList.begin(), aList.end(), [idNum](Actor& a) {return a.GetIDNum() == idNum;});
    Actor actor = *a_it;
    return actor;
} */
Actor* SystemManager::FindActor(int idNum, vector<Actor>& aList)
{
    auto a_it = std::find_if(aList.begin(), aList.end(), [idNum](Actor& a) {return a.GetIDNum() == idNum;});
    return &*a_it;
} 

Singer* SystemManager::FindSinger(int idNum, vector<Singer>& sList)
{
    auto s_it = std::find_if(sList.begin(), sList.end(), [idNum](Singer& s) {return s.GetIDNum() == idNum;});
    return &*s_it;
}

Musician* SystemManager::FindMusician(int idNum, vector<Musician>& mList)
{
    auto m_it = std::find_if(mList.begin(), mList.end(), [idNum](Musician& m) {return m.GetIDNum() == idNum;});
    return &*m_it;
}

PerformanceHall* SystemManager::FindPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    auto pH_it = std::find_if(pHList.begin(), pHList.end(), [hallNum](PerformanceHall& pH) {return pH.GetHallNum() == hallNum;});
    return &*pH_it;
}

Play* SystemManager::FindPlay(int perfID, vector<Play>& pList)
{
    auto p_it = std::find_if(pList.begin(), pList.end(), [perfID](Play& p) {return p.GetPerfID() == perfID;});
    return &*p_it;
}

Musical* SystemManager::FindMusical(int perfID, vector<Musical>& mList)
{
    auto m_it = std::find_if(mList.begin(), mList.end(), [perfID](Musical& m) {return m.GetPerfID() == perfID;});
    return &*m_it;
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

float SystemManager::CalculatePerfProfit(PerformanceHall h)
{
    Performance p = h.GetScheduledPerf();
    float totalSales = (p.GetTicketPrice())*(p.GetTicketsSold()); 
    float perfCost = 0.0f;
    //for(p.) 
    return totalSales - perfCost;
}