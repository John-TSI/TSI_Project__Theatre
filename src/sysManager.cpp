
#include<iostream>
#include<algorithm>
#include"../include/sysManager.hpp"

using std::cout; using std::endl;


// --- constructors ---
SystemManager::SystemManager() {}


// --- getters/setters ---
int SystemManager::GetActorCount() { return actorCount; }
void SystemManager::SetActorCount(int input) { actorCount = input; }
int SystemManager::GetSingerCount() { return singerCount; }
void SystemManager::SetSingerCount(int input) { singerCount = input; }
int SystemManager::GetMusicianCount() { return musicianCount; }
void SystemManager::SetMusicianCount(int input) { musicianCount = input; }
int SystemManager::GetPlayCount() { return playCount; }
void SystemManager::SetPlayCount(int input) { playCount = input; }
int SystemManager::GetMusicalCount() { return musicalCount; }
void SystemManager::SetMusicalCount(int input) { musicalCount = input; }
int SystemManager::GetHallCount() { return hallCount; }
void SystemManager::SetHallCount(int input) {hallCount = input; }

vector<Actor>& SystemManager::GetActorList() { return actorList; }
vector<Singer>& SystemManager::GetSingerList() { return singerList; }
vector<Musician>& SystemManager::GetMusicianList() { return musicianList; }
vector<PerformanceHall>& SystemManager::GetPerfHallList() { return perfHallList; }
vector<Play>& SystemManager::GetPlayList() { return playList; }
vector<Musical>& SystemManager::GetMusicalList() { return musicalList; }


// --- add/remove --- 
void SystemManager::AddActor(vector<Actor>& aList)
{
    aList.push_back(Actor(actorIDcount) );
    actorIDcount++;
    actorCount++;
}

void SystemManager::RmActor(int idNum, vector<Actor>& aList)
{
    aList.erase(std::remove_if(begin(aList), end(aList), 
        [idNum](Actor& a) { return a.GetIDNum() == idNum; }
    ), end(aList));
    actorCount--;
}

void SystemManager::AddSinger(vector<Singer>& sList)
{
    sList.push_back(Singer(singerIDcount) );
    singerIDcount++;
    singerCount++;
}

void SystemManager::RmSinger(int idNum, vector<Singer>& sList)
{
    sList.erase(std::remove_if(begin(sList), end(sList), 
        [idNum](Singer& s) { return s.GetIDNum() == idNum; }
    ), end(sList));
    singerCount--;
}

void SystemManager::AddMusician(vector<Musician>& mList)
{
    mList.push_back(Musician(musicianIDcount) );
    musicianIDcount++;
    musicianCount++;
}

void SystemManager::RmMusician(int idNum, vector<Musician>& mList)
{
    mList.erase(std::remove_if(begin(mList), end(mList), 
        [idNum](Musician& m) { return m.GetIDNum() == idNum; }
    ), end(mList));
    musicianCount--;
}

void SystemManager::AddPlay(vector<Play>& pList)
{
    pList.push_back((playIDcount) );
    playIDcount++;
    playCount++;
}

void SystemManager::RmPlay(int perfID, vector<Play>& pList)
{
    pList.erase(std::remove_if(begin(pList), end(pList), 
        [perfID](Play& p) { return p.GetPerfID() == perfID; }
    ), end(pList));
    playCount--;
}

void SystemManager::AddMusical(vector<Musical>& mList)
{
    mList.push_back(Musical(musicalIDcount) );
    musicalIDcount++;
    musicalCount++;
}

void SystemManager::RmMusical(int perfID, vector<Musical>& mList)
{
    mList.erase(std::remove_if(begin(mList), end(mList), 
        [perfID](Musical& m) { return m.GetPerfID() == perfID; }
    ), end(mList));
    musicalCount--;
}

void SystemManager::AddPerfHall(vector<PerformanceHall>& pHList)
{
    pHList.push_back(PerformanceHall(hallNumCount) );
    hallNumCount++;
    hallCount++;
}

void SystemManager::RmPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    pHList.erase(std::remove_if(begin(pHList), end(pHList), 
        [hallNum](PerformanceHall& pH) { return pH.GetHallNum() == hallNum; }
    ), end(pHList));
    hallCount--;
}


// --- (un)assign/(un)schedule ---
void SystemManager::AssignActor(Actor& a, vector<Actor>& va, Play& p)
{
    // -- modify Actor attributes inherited from Performer --
    a.SetIsAssigned(true);
    a.SetInPerfID(p.GetPerfID());

    // -- modify Play attributes --
    va.push_back(a);
    p.SetActorRoster(va);
    p.SetNumActors(p.GetNumActors() + 1);

    // -- modify Play attributes inherited from Performance --
    p.SetNumPerformers(p.GetNumPerformers() + 1);
    p.SetPerfCost(p.GetPerfCost() + a.GetSalary());
    //p.SetPerformerRoster(p.GetPerformerRoster().push_back(a));
    if(p.GetNumActors() >= p.GetReqNumActors())
    {
        p.SetIsFullyCast(true);
    }
}

void SystemManager::UnassignActor(Actor& a, vector<Actor>& va, Play& p)
{
    // -- modify Actor attributes inherited from Performer --
    a.SetIsAssigned(false);
    a.SetInPerfID(-1);

    // -- modify Play attributes --
    RmActor(a.GetIDNum(), va); // this call will incorrectly decrement the SM actorCount attribute (compensate after calling this method)
    p.SetNumActors(p.GetNumActors() - 1);

    // -- modify Play attributes inherited from Performance --
    p.SetNumPerformers(p.GetNumPerformers() - 1);
    p.SetPerfCost(p.GetPerfCost() - a.GetSalary());
    (p.GetNumActors() >= p.GetReqNumActors()) ? p.SetIsFullyCast(true) : p.SetIsFullyCast(false);
}

void SystemManager::AssignSinger(Singer& s, vector<Singer>& vs, Musical& mu)
{
    // -- modify Singer attributes inherited from Performer --
    s.SetIsAssigned(true);
    s.SetInPerfID(mu.GetPerfID());

    // -- modify Musical attributes --
    vs.push_back(s);
    mu.SetSingerRoster(vs);
    mu.SetNumSingers(mu.GetNumSingers() + 1);

    // -- modify Musical attributes inherited from Performance --
    mu.SetNumPerformers(mu.GetNumPerformers() + 1);
    mu.SetPerfCost(mu.GetPerfCost() + s.GetSalary());
    if((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians()))
    {
        mu.SetIsFullyCast(true);
    }
}

void SystemManager::UnassignSinger(Singer& s, vector<Singer>& vs, Musical& mu)
{
    // -- modify Singer attributes inherited from Performer --
    s.SetIsAssigned(false);
    s.SetInPerfID(-1);

    // -- modify Musical attributes --
    RmSinger(s.GetIDNum(), vs); // this call will incorrectly decrement the SM singerCount attribute (compensate after calling this method)
    mu.SetNumSingers(mu.GetNumSingers() - 1);

    // -- modify Musical attributes inherited from Performance --
    mu.SetNumPerformers(mu.GetNumPerformers() - 1);
    mu.SetPerfCost(mu.GetPerfCost() - s.GetSalary());
    ((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians())) ? mu.SetIsFullyCast(true) : mu.SetIsFullyCast(false);
}

void SystemManager::AssignMusician(Musician& m, vector<Musician>& vm, Musical& mu)
{
     // -- modify Singer attributes inherited from Performer --
    m.SetIsAssigned(true);
    m.SetInPerfID(mu.GetPerfID());

     // -- modify Musical attributes --
    vm.push_back(m);
    mu.SetMusicianRoster(vm);
    mu.SetNumMusicians(mu.GetNumMusicians() + 1);

    // modify Musical attributes inherited from Performance
    mu.SetNumPerformers(mu.GetNumPerformers() + 1);
    mu.SetPerfCost(mu.GetPerfCost() + m.GetSalary());
    if((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians()))
    {
        mu.SetIsFullyCast(true);
    }
}

void SystemManager::UnassignMusician(Musician& m, vector<Musician>& vm, Musical& mu)
{
    // -- modify Musician attributes inherited from Performer --
    m.SetIsAssigned(false);
    m.SetInPerfID(-1);

    // -- modify Musical attributes --
    RmMusician(m.GetIDNum(), vm); // this call will incorrectly decrement the SM musicianCount attribute (compensate after calling this method)
    mu.SetNumMusicians(mu.GetNumMusicians() - 1);

    // -- modify Musical attributes inherited from Performance --
    mu.SetNumPerformers(mu.GetNumPerformers() - 1);
    mu.SetPerfCost(mu.GetPerfCost() - m.GetSalary());
    ((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians())) ? mu.SetIsFullyCast(true) : mu.SetIsFullyCast(false);
}

void SystemManager::SchedulePerformance(Performance& p, PerformanceHall& h) // remove?
{
    // -- modify Performance attribtes --
    p.SetIsScheduled(true);
    p.SetInHallNum(h.GetHallNum());

    // -- modify Performance Hall attributes --
    h.SetIsBooked(true);
    h.SetScheduledPerf(p);
}

void SystemManager::UnschedulePerformance(Performance& p, PerformanceHall& h)
{
    // -- modify Performance --
    p.SetIsScheduled(false);
    p.SetInHallNum(-1);

    // -- modify Performance Hall attributes --
    h.SetIsBooked(false);
}


// --- verifications ---
bool SystemManager::IsFullyCast(Play& p) { return p.GetIsFullyCast(); }
bool SystemManager::IsFullyCast(Musical& m) { return m.GetIsFullyCast(); }
bool SystemManager::IsBooked(PerformanceHall& h) { return h.GetIsBooked(); }
//bool SystemManager::StageIsPrepared(PerformanceHall& h) { return h.GetStagePrepared(); }

void SystemManager::CheckHallsStatus(vector<PerformanceHall>& hList)
{
    for(PerformanceHall h : hList)
	{	
        int hallNum = h.GetHallNum();
		int perfNum =  h.GetScheduledPerf().GetPerfID();
		(h.GetIsBooked()) ? cout << "Hall number " << hallNum << " is booked with performance number " << perfNum << "." << endl : cout << "Hall number " << hallNum << " is not booked." << endl;
		if(h.GetIsBooked())
        {
            (h.GetScheduledPerf().GetIsFullyCast()) ? cout << "Scheduled performance is fully cast!\n" << endl : cout << "Scheduled performance has insufficient performers!\n" << endl;
        }
	}
}

bool SystemManager::AllPerfsReady(vector<PerformanceHall>& hList)
{
    bool allPerfsReady = true;
    for(PerformanceHall h : hList)
	{	
		if(h.GetIsBooked())
        {
            if(!h.GetScheduledPerf().GetIsFullyCast()) { allPerfsReady = false; }
        }
	}
    return allPerfsReady;
}

// ID verifiers
bool SystemManager::VerifiedActorID(int idNum, vector<Actor> aList)
{
    bool verified = false;
    for(Actor a : aList)
    {
        if(a.GetIDNum() == idNum) { verified = true; }
    }
    return verified;
}

bool SystemManager::VerifiedSingerID(int idNum, vector<Singer> sList)
{
    bool verified = false;
    for(Singer s : sList)
    {
        if(s.GetIDNum() == idNum) { verified = true; }
    }
    return verified;
}

bool SystemManager::VerifiedMusicianID(int idNum, vector<Musician> mList)
{
    bool verified = false;
    for(Musician m : mList)
    {
        if(m.GetIDNum() == idNum) { verified = true; }
    }
    return verified;
}

bool SystemManager::VerifiedPlayID(int perfID, vector<Play> pList)
{
    bool verified = false;
    for(Play p : pList)
    {
        if(p.GetPerfID() == perfID) { verified = true; }
    }
    return verified;
}

bool SystemManager::VerifiedMusicalID(int perfID, vector<Musical> muList)
{
    bool verified = false;
    for(Musical mu : muList)
    {
        if(mu.GetPerfID() == perfID) { verified = true; }
    }
    return verified;
}

bool SystemManager::VerifiedHallNum(int hallNum, vector<PerformanceHall> hList)
{
    bool verified = false;
    for(PerformanceHall h: hList)
    {
        if(h.GetHallNum() == hallNum) { verified = true; }
    }
    return verified;
}


// --- utility ---
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

PerformanceHall* SystemManager::FindPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    auto pH_it = std::find_if(pHList.begin(), pHList.end(), [hallNum](PerformanceHall& pH) {return pH.GetHallNum() == hallNum;});
    return &*pH_it;
}


// ID printers
void SystemManager::PrintActors(vector<Actor> vec)
{
    for(Actor a : vec) { cout << a.GetIDNum() << " "; }
} 
void SystemManager::PrintAssignedActors(vector<Actor> vec)
{
    for(Actor a : vec) { if(a.GetIsAssigned() ) { cout << a.GetIDNum() << " "; } }
}
void SystemManager::PrintUnassignedActors(vector<Actor> vec)
{
    for(Actor a : vec) { if(!a.GetIsAssigned() ) { cout << a.GetIDNum() << " "; } }
}

void SystemManager::PrintSingers(vector<Singer> vec)
{
    for(Singer s : vec) { cout << s.GetIDNum() << " "; }
}
void SystemManager::PrintAssignedSingers(vector<Singer> vec)
{
    for(Singer s : vec) { if(s.GetIsAssigned() ) { cout << s.GetIDNum() << " "; } }
}
void SystemManager::PrintUnassignedSingers(vector<Singer> vec)
{
    for(Singer s : vec) { if(!s.GetIsAssigned() ) { cout << s.GetIDNum() << " "; } }
}

void SystemManager::PrintMusicians(vector<Musician> vec)
{
    for(Musician m : vec) { cout << m.GetIDNum() << " "; }
}
void SystemManager::PrintAssignedMusicians(vector<Musician> vec)
{
    for(Musician m : vec) { if(m.GetIsAssigned() ) { cout << m.GetIDNum() << " "; } }
}
void SystemManager::PrintUnassignedMusicians(vector<Musician> vec)
{
    for(Musician m : vec) { if(!m.GetIsAssigned() ) { cout << m.GetIDNum() << " "; } }
}

void SystemManager::PrintPlays(vector<Play> vec)
{
    for(Play p : vec) { cout << p.GetPerfID() << " "; }
}
void SystemManager::PrintScheduledPlays(vector<Play> vec)
{
    for(Play p : vec) { if(p.GetIsScheduled() ) { cout << p.GetPerfID() << " "; } }
}
void SystemManager::PrintUnscheduledPlays(vector<Play> vec)
{
    for(Play p : vec) { if(!p.GetIsScheduled() ) { cout << p.GetPerfID() << " "; } }
}

void SystemManager::PrintMusicals(vector<Musical> vec)
{
    for(Musical m : vec) { cout << m.GetPerfID() << " "; }
}
void SystemManager::PrintScheduledMusicals(vector<Musical> vec)
{
    for(Musical mu : vec) { if(mu.GetIsScheduled() ) { cout << mu.GetPerfID() << " "; } }
}
void SystemManager::PrintUnscheduledMusicals(vector<Musical> vec)
{
    for(Musical mu : vec) { if(!mu.GetIsScheduled() ) { cout << mu.GetPerfID() << " "; } }
}

void SystemManager::PrintHalls(vector<PerformanceHall> vec)
{
    for(PerformanceHall hall : vec) { cout << hall.GetHallNum() << " "; }
}
void SystemManager::PrintBookedHalls(vector<PerformanceHall> vec)
{
    for(PerformanceHall h : vec) { if(h.GetIsBooked() ) { cout << h.GetHallNum() << " "; } }
}
void SystemManager::PrintAvailableHalls(vector<PerformanceHall> vec)
{
    for(PerformanceHall h : vec) { if(!h.GetIsBooked() ) { cout << h.GetHallNum() << " "; } }
}


// calculators
float SystemManager::CalcPerfProfit(PerformanceHall h)
{
    if(!h.GetIsBooked()) { cout << "No scheduled performance in this hall!" << endl; return 0.0f; }
    Performance p = h.GetScheduledPerf();
    float totalSales = (p.GetTicketPrice())*(p.GetTicketsSold()); 
    float perfCost = p.GetPerfCost(); 
    return totalSales - perfCost;
}

float SystemManager::CalcTotalProfit(vector<PerformanceHall> hList)
{
    float totalProfit = 0.0f;
    for(PerformanceHall h : hList)
    {
        totalProfit += CalcPerfProfit(h);
    }
    return totalProfit;
}