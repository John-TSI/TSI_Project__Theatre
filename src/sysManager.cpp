
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
    cout << "\nAn Actor has been added." << endl;
    cout << "System currently has " << GetActorCount() << " listed Actors.\n";
}

void SystemManager::RmActor(int idNum, vector<Actor>& aList, bool unassigning)
{
    if((FindActor(idNum, aList)->GetIsAssigned()) && !(unassigning))
    {
        cout << "\nThe specified Actor is currently assigned to a Play." << endl;
        cout << "Unassign the Actor before removing them from the System." << endl;
    }
    else
    {
        aList.erase(std::remove_if(begin(aList), end(aList), [idNum](Actor& a) { return a.GetIDNum() == idNum; }), end(aList));
        if(!unassigning)
        {
            actorCount--;
            cout << "\nThe Actor has been removed." << endl;
            cout << "System currently has " << GetActorCount() << " listed Actors.\n";
        }
    }
}

void SystemManager::AddSinger(vector<Singer>& sList)
{
    sList.push_back(Singer(singerIDcount) );
    singerIDcount++;
    singerCount++;
    cout << "\nA Singer has been added." << endl;
    cout << "System currently has " << GetSingerCount() << " listed Singers.\n";
}

void SystemManager::RmSinger(int idNum, vector<Singer>& sList, bool unassigning)
{
    if((FindSinger(idNum, sList)->GetIsAssigned()) && !(unassigning))
    {
        cout << "\nThe specified Singer is currently assigned to a Musical." << endl;
        cout << "Unassign the Singer before removing them from the System." << endl;
    }
    else
    {
        sList.erase(std::remove_if(begin(sList), end(sList), 
            [idNum](Singer& s) { return s.GetIDNum() == idNum; }
        ), end(sList));
        if(!unassigning)
        {
            singerCount--;
            cout << "\nThe Singer has been removed." << endl;
            cout << "System currently has " << GetSingerCount() << " listed Singers.\n";
        }
    }
}

void SystemManager::AddMusician(vector<Musician>& mList)
{
    mList.push_back(Musician(musicianIDcount) );
    musicianIDcount++;
    musicianCount++;
    cout << "\nA Musician has been added." << endl;
    cout << "System currently has " << GetMusicianCount() << " listed Musicians.\n";
}

void SystemManager::RmMusician(int idNum, vector<Musician>& mList, bool unassigning)
{
    if((FindMusician(idNum, mList)->GetIsAssigned()) && !(unassigning))
    {
        cout << "\nThe specified Musician is currently assigned to a Musical." << endl;
        cout << "Unassign the Musician before removing them from the System." << endl;
    }
    else
    {
        mList.erase(std::remove_if(begin(mList), end(mList), 
            [idNum](Musician& m) { return m.GetIDNum() == idNum; }
        ), end(mList));
        if(!unassigning)
        {
            musicianCount--;
            cout << "\nThe Musician has been removed." << endl;
            cout << "System currently has " << GetMusicianCount() << " listed Musicians.\n";
        }
    }
}

void SystemManager::AddPlay(vector<Play>& pList)
{
    pList.push_back((playIDcount) );
    playIDcount++;
    playCount++;
    cout << "\nA Play has been added." << endl;
    cout << "System currently has " << GetPlayCount() << " listed Plays.\n";
}

void SystemManager::RmPlay(int perfID, vector<Play>& pList)
{   
    Play* p = FindPlay(perfID, pList); 
    if(p->GetNumActors() > 0)
    {
        // unassign actors
/*         vector<Actor>& aList = p->GetActorRoster();
        for(Actor& a : aList) 
        { 
            //UnassignActor(a, aList, *p);
            int idNum = a.GetIDNum();
            vector<Actor>& aList = GetActorList();
            Actor* a_sys = FindActor(idNum, aList);
            a_sys->SetIsAssigned(false);
            a_sys->SetInPerfID(-1); 
        } */
        cout << "\nThe specified Play currently has " << p->GetNumActors() << " Actor(s) assigned to it." << endl;
        cout << "Unassign all Performers from the Play before removing it from the System." << endl;
    }
    else if(p->GetIsScheduled())
    {
        cout << "\nThe specified Play is currently scheduled in a Performance Hall." << endl;
        cout << "Unschedule the Play before removing it from the System." << endl;
    }
    else
    {
        pList.erase(std::remove_if(begin(pList), end(pList), [perfID](Play& p) { return p.GetPerfID() == perfID; }), end(pList));
        playCount--;
        cout << "\nThe Play has been removed." << endl;
        cout << "System currently has " << GetPlayCount() << " listed Plays.\n";
    }
}

void SystemManager::AddMusical(vector<Musical>& mList)
{
    mList.push_back(Musical(musicalIDcount) );
    musicalIDcount++;
    musicalCount++;
    cout << "\nA Musical has been added." << endl;
    cout << "System currently has " << GetMusicalCount() << " listed Musicals.\n";
}

void SystemManager::RmMusical(int perfID, vector<Musical>& mList)
{
    Musical* mu = FindMusical(perfID, mList);
    if((mu->GetNumSingers() > 0) || (mu->GetNumMusicians() > 0))
    {
        cout << "\nThe specified Musical currently has " << mu->GetNumSingers() << " Singer(s) and " << mu->GetNumMusicians() << " Musician(s) assigned to it." << endl;
        cout << "Unassign all Performers from the Musical before removing it from the System." << endl;
    }
    else if(mu->GetIsScheduled())
    {
        cout << "\nThe specified Musical is currently scheduled in a Performance Hall." << endl;
        cout << "Unschedule the Musical before removing it from the System." << endl;
    }
    else
    {
        mList.erase(std::remove_if(begin(mList), end(mList), [perfID](Musical& m) { return m.GetPerfID() == perfID; }), end(mList));
        musicalCount--;
        cout << "\nThe Musical has been removed." << endl;
        cout << "System currently has " << GetMusicalCount() << " listed Musicals.\n";
    }
}

void SystemManager::AddPerfHall(vector<PerformanceHall>& pHList)
{
    pHList.push_back(PerformanceHall(hallNumCount) );
    hallNumCount++;
    hallCount++;
    cout << "\nA Performance Hall has been added." << endl;
    cout << "System currently has " << GetHallCount() << " listed Performance Halls.\n";
}

void SystemManager::RmPerfHall(int hallNum, vector<PerformanceHall>& pHList)
{
    PerformanceHall* h = FindPerfHall(hallNum, pHList);
    if(h->GetIsBooked())
    {
        cout << "\nThe specified Performance Hall is currently booked with a Performance." << endl;
        cout << "Unschedule the Performance before removing the Performance Hall from the System." << endl;
    }
    else
    {
        pHList.erase(std::remove_if(begin(pHList), end(pHList), [hallNum](PerformanceHall& pH) { return pH.GetHallNum() == hallNum; }), end(pHList));
        hallCount--;
        cout << "\nThe Performance Hall has been removed." << endl;
        cout << "System currently has " << GetHallCount() << " listed Performance Halls.\n";
    }
}


// --- (un)assign/(un)schedule ---
void SystemManager::AssignActor(Actor& a, Play& p)
{
    // -- modify Actor attributes inherited from Performer --
    a.SetIsAssigned(true);
    a.SetInPerfID(p.GetPerfID());

    // -- modify Play attributes --
    vector<Actor> va = p.GetActorRoster();
    va.push_back(a);
    p.SetActorRoster(va);
    p.SetNumActors(p.GetNumActors() + 1);

    // -- modify Play attributes inherited from Performance --
    p.SetNumPerformers(p.GetNumPerformers() + 1);
    p.SetPerfCost(p.GetPerfCost() + a.GetSalary());
    if(p.GetNumActors() >= p.GetReqNumActors()) { p.SetIsFullyCast(true); }
    cout << "\nThe Actor has been assigned to the Play." << endl;
}
void SystemManager::AssignActor(Actor& a, Play& p, PerformanceHall& h)
{
    // -- modify Actor attributes inherited from Performer --
    a.SetIsAssigned(true);
    a.SetInPerfID(p.GetPerfID());

    // -- modify Play attributes --
    vector<Actor> va = p.GetActorRoster();
    va.push_back(a);
    p.SetActorRoster(va);
    p.SetNumActors(p.GetNumActors() + 1);

    // -- modify Play attributes inherited from Performance --
    p.SetNumPerformers(p.GetNumPerformers() + 1);
    p.SetPerfCost(p.GetPerfCost() + a.GetSalary());
    if(p.GetNumActors() >= p.GetReqNumActors()) { p.SetIsFullyCast(true); }

    // modify attributes of Play within Performance Hall
    Play* ph = &(h.GetScheduledPlay());
    vector<Actor> vaph = ph->GetActorRoster();
    vaph.push_back(a);
    ph->SetActorRoster(va);
    ph->SetNumActors(ph->GetNumActors() + 1);

    ph->SetNumPerformers(ph->GetNumPerformers() + 1);
    ph->SetPerfCost(ph->GetPerfCost() + a.GetSalary());
    if(ph->GetNumActors() >= ph->GetReqNumActors()) { ph->SetIsFullyCast(true); }

    cout << "\nThe Actor has been assigned to the Play." << endl;
}

void SystemManager::UnassignActor(Actor& a, Play& p)
{
    // -- modify Actor attributes inherited from Performer --
    a.SetIsAssigned(false);
    a.SetInPerfID(-1);

    // -- modify Play attributes --
    vector<Actor> va = p.GetActorRoster();
    RmActor(a.GetIDNum(), va, true);
    p.SetNumActors(p.GetNumActors() - 1);

    // -- modify Play attributes inherited from Performance --
    p.SetNumPerformers(p.GetNumPerformers() - 1);
    p.SetPerfCost(p.GetPerfCost() - a.GetSalary());
    (p.GetNumActors() >= p.GetReqNumActors()) ? p.SetIsFullyCast(true) : p.SetIsFullyCast(false);
    cout << "\nThe Actor has been removed from the Play roster." << endl;
}
void SystemManager::UnassignActor(Actor& a, Play& p, PerformanceHall& h)
{
    // -- modify Actor attributes inherited from Performer --
    a.SetIsAssigned(false);
    a.SetInPerfID(-1);

    // -- modify Play attributes --
    vector<Actor> va = p.GetActorRoster();
    RmActor(a.GetIDNum(), va, true);
    p.SetNumActors(p.GetNumActors() - 1);

    // -- modify Play attributes inherited from Performance --
    p.SetNumPerformers(p.GetNumPerformers() - 1);
    p.SetPerfCost(p.GetPerfCost() - a.GetSalary());
    (p.GetNumActors() >= p.GetReqNumActors()) ? p.SetIsFullyCast(true) : p.SetIsFullyCast(false);

    // modify attributes of Play within Performance Hall
    Play* ph = &(h.GetScheduledPlay());
    vector<Actor> vah = ph->GetActorRoster();
    RmActor(a.GetIDNum(), vah, true);
    ph->SetNumActors(ph->GetNumActors() - 1);

    ph->SetNumPerformers(ph->GetNumPerformers() - 1);
    ph->SetPerfCost(ph->GetPerfCost() - a.GetSalary());
    (ph->GetNumActors() >= ph->GetReqNumActors()) ? ph->SetIsFullyCast(true) : ph->SetIsFullyCast(false);

    cout << "\nThe Actor has been removed from the Play roster." << endl;
}

void SystemManager::AssignSinger(Singer& s, Musical& mu)
{
    // -- modify Singer attributes inherited from Performer --
    s.SetIsAssigned(true);
    s.SetInPerfID(mu.GetPerfID());

    // -- modify Musical attributes --
    vector<Singer> vs = mu.GetSingerRoster();
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
    cout << "\nThe Singer has been assigned to the Musical." << endl;
}
void SystemManager::AssignSinger(Singer& s, Musical& mu, PerformanceHall& h)
{
    // -- modify Singer attributes inherited from Performer --
    s.SetIsAssigned(true);
    s.SetInPerfID(mu.GetPerfID());

    // -- modify Musical attributes --
    vector<Singer> vs = mu.GetSingerRoster();
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

    // modify attributes of Musical within Performance Hall
    Musical* muh = &(h.GetScheduledMusical());
    vector<Singer> vsmuh = muh->GetSingerRoster();
    vsmuh.push_back(s);
    muh->SetSingerRoster(vsmuh);
    muh->SetNumSingers(muh->GetNumSingers() + 1);

    muh->SetNumPerformers(muh->GetNumPerformers() + 1);
    muh->SetPerfCost(muh->GetPerfCost() + s.GetSalary());
    if((muh->GetNumSingers() >= muh->GetReqNumSingers()) && (muh->GetNumMusicians() >= muh->GetReqNumMusicians()))
    {
        muh->SetIsFullyCast(true);
    }
    cout << "\nThe Singer has been assigned to the Musical." << endl;
}

void SystemManager::UnassignSinger(Singer& s, Musical& mu)
{
    // -- modify Singer attributes inherited from Performer --
    s.SetIsAssigned(false);
    s.SetInPerfID(-1);

    // -- modify Musical attributes --
    vector<Singer> vs = mu.GetSingerRoster();
    RmSinger(s.GetIDNum(), vs, true);
    mu.SetNumSingers(mu.GetNumSingers() - 1);

    // -- modify Musical attributes inherited from Performance --
    mu.SetNumPerformers(mu.GetNumPerformers() - 1);
    mu.SetPerfCost(mu.GetPerfCost() - s.GetSalary());
    ((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians())) ? mu.SetIsFullyCast(true) : mu.SetIsFullyCast(false);
    cout << "\nThe Singer has been removed from the Musical roster." << endl;	
}

void SystemManager::AssignMusician(Musician& m, Musical& mu)
{
     // -- modify Singer attributes inherited from Performer --
    m.SetIsAssigned(true);
    m.SetInPerfID(mu.GetPerfID());

     // -- modify Musical attributes --
    vector<Musician> vm = mu.GetMusicianRoster();
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
    cout << "\nThe Musician has been assigned to the Musical." << endl;
}
void SystemManager::AssignMusician(Musician& m, Musical& mu, PerformanceHall& h)
{
    // -- modify Musician attributes inherited from Performer --
    m.SetIsAssigned(true);
    m.SetInPerfID(mu.GetPerfID());

    // -- modify Musical attributes --
    vector<Musician> vm = mu.GetMusicianRoster();
    vm.push_back(m);
    mu.SetMusicianRoster(vm);
    mu.SetNumMusicians(mu.GetNumMusicians() + 1);

    // -- modify Musical attributes inherited from Performance --
    mu.SetNumPerformers(mu.GetNumPerformers() + 1);
    mu.SetPerfCost(mu.GetPerfCost() + m.GetSalary());
    if((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians()))
    {
        mu.SetIsFullyCast(true);
    }

    // modify attributes of Musical within Performance Hall
    Musical* muh = &(h.GetScheduledMusical());
    vector<Musician> vmmuh = muh->GetMusicianRoster();
    vmmuh.push_back(m);
    muh->SetMusicianRoster(vmmuh);
    muh->SetNumMusicians(muh->GetNumMusicians() + 1);

    muh->SetNumPerformers(muh->GetNumPerformers() + 1);
    muh->SetPerfCost(muh->GetPerfCost() + m.GetSalary());
    if((muh->GetNumSingers() >= muh->GetReqNumSingers()) && (muh->GetNumMusicians() >= muh->GetReqNumMusicians()))
    {
        muh->SetIsFullyCast(true);
    }
    cout << "\nThe Musician has been assigned to the Musical." << endl;
}

void SystemManager::UnassignMusician(Musician& m, Musical& mu)
{
    // -- modify Musician attributes inherited from Performer --
    m.SetIsAssigned(false);
    m.SetInPerfID(-1);

    // -- modify Musical attributes --
    vector<Musician> vm = mu.GetMusicianRoster();
    RmMusician(m.GetIDNum(), vm, true);
    mu.SetNumMusicians(mu.GetNumMusicians() - 1);

    // -- modify Musical attributes inherited from Performance --
    mu.SetNumPerformers(mu.GetNumPerformers() - 1);
    mu.SetPerfCost(mu.GetPerfCost() - m.GetSalary());
    ((mu.GetNumSingers() >= mu.GetReqNumSingers()) && (mu.GetNumMusicians() >= mu.GetReqNumMusicians())) ? mu.SetIsFullyCast(true) : mu.SetIsFullyCast(false);
    cout << "\nThe Musician has been removed from the Musical roster." << endl;	
}

void SystemManager::SchedulePlay(Play& p, PerformanceHall& h)
{
    // -- modify Play attributes inherited from Performance --
    p.SetIsScheduled(true);
    p.SetInHallNum(h.GetHallNum());

    // -- modify Performance Hall attributes --
    h.SetIsBooked(true);
    h.SetHasPlay(true); h.SetHasMusical(false);
    h.SetScheduledPlay(p);

    cout << "\nThe Play has been scheduled in the Performance Hall." << endl;
}

void SystemManager::UnschedulePlay(Play& p, PerformanceHall& h)
{
    // -- modify Play attributes inherited from Performance --
    p.SetIsScheduled(false);
    p.SetInHallNum(-1);

    // -- modify Performance Hall attributes --
    h.SetIsBooked(false);
    h.SetHasPlay(false); h.SetHasMusical(false);

    cout << "\nThe Play has been unscheduled." << endl;
}

void SystemManager::ScheduleMusical(Musical& mu, PerformanceHall& h)
{
    // -- modify Musical attributes inherited from Performance --
    mu.SetIsScheduled(true);
    mu.SetInHallNum(h.GetHallNum());

    // -- modify Performance Hall attributes --
    h.SetIsBooked(true);
    h.SetHasMusical(true); h.SetHasPlay(false);
    h.SetScheduledMusical(mu);

    cout << "\nThe Musical has been scheduled in the Performance Hall." << endl;
}

void SystemManager::UnscheduleMusical(Musical& mu, PerformanceHall& h)
{
    // -- modify Musical attributes inherited from Performance --
    mu.SetIsScheduled(false);
    mu.SetInHallNum(-1);

    // -- modify Performance Hall attributes --
    h.SetIsBooked(false);
    h.SetHasMusical(false); h.SetHasPlay(false);

    cout << "\nThe Musical has been unscheduled." << endl;
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


//modifiers
void SystemManager::ModifyActorSalary(Actor& a, float newSalary)
{
    float currentSalary = a.GetSalary();
    float diff = newSalary - currentSalary;
    a.SetSalary(newSalary);
    cout << "\nThe Actor's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}
void SystemManager::ModifyActorSalary(Actor& a, int idNum, Play& p, float newSalary)
{
    // modify Actor in SystemManager list
    float currentSalary = a.GetSalary();
    float diff = newSalary - currentSalary;
    a.SetSalary(newSalary);
    p.SetPerfCost(p.GetPerfCost() + diff);

    // modify Actor assigned to a Play
    Actor* ap = FindActor(idNum, p.GetActorRoster());
    ap->SetSalary(newSalary);

    cout << "\nThe Actor's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}
void SystemManager::ModifyActorSalary(Actor& a, int idNum, Play& p, PerformanceHall& h, float newSalary)
{
    // modify Actor in SystemManager list
    float currentSalary = a.GetSalary();
    float diff = newSalary - currentSalary;
    a.SetSalary(newSalary);
    p.SetPerfCost(p.GetPerfCost() + diff);

    // modify Actor assigned to a Play
    Actor* ap = FindActor(idNum, p.GetActorRoster());
    ap->SetSalary(newSalary);

    // modify Actor in PLay assigned to a Performance Hall
    Play* ph = &(h.GetScheduledPlay());
    ph->SetPerfCost(ph->GetPerfCost() + diff);
    Actor* aph = FindActor(idNum, ph->GetActorRoster());
    aph->SetSalary(newSalary);

    cout << "\nThe Actor's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}

void SystemManager::ModifySingerSalary(Singer& s, float newSalary)
{
    float currentSalary = s.GetSalary();
    float diff = newSalary - currentSalary;
    s.SetSalary(newSalary);
    cout << "\nThe Singer's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ")." : cout << "(decreased by " << -diff << ").";
}
void SystemManager::ModifySingerSalary(Singer& s, int idNum, Musical& mu, float newSalary)
{
    // modify Singer in SystemManager list
    float currentSalary = s.GetSalary();
    float diff = newSalary - currentSalary;
    s.SetSalary(newSalary);
    mu.SetPerfCost(mu.GetPerfCost() + diff);

    // modify Singer assigned to a Musical
    Singer* smu = FindSinger(idNum, mu.GetSingerRoster());
    smu->SetSalary(newSalary);

    cout << "\nThe Singer's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}
void SystemManager::ModifySingerSalary(Singer& s, int idNum, Musical& mu, PerformanceHall& h, float newSalary)
{
    // modify Singer in SystemManager list
    float currentSalary = s.GetSalary();
    float diff = newSalary - currentSalary;
    s.SetSalary(newSalary);
    mu.SetPerfCost(mu.GetPerfCost() + diff);

    // modify Singer assigned to a Musical
    Singer* smu = FindSinger(idNum, mu.GetSingerRoster());
    smu->SetSalary(newSalary);

    // modify Singer in Musical assigned to a Performance Hall
    Musical* muh = &(h.GetScheduledMusical());
    muh->SetPerfCost(muh->GetPerfCost() + diff);
    Singer* smuh = FindSinger(idNum, muh->GetSingerRoster());
    smuh->SetSalary(newSalary);

    cout << "\nThe Singer's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}

void SystemManager::ModifyMusicianSalary(Musician& m, float newSalary)
{
    float currentSalary = m.GetSalary();
    float diff = newSalary - currentSalary;
    m.SetSalary(newSalary);
    cout << "\nThe Musician's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ")." : cout << "(decreased by " << -diff << ").";
}
void SystemManager::ModifyMusicianSalary(Musician& m, int idNum, Musical& mu, float newSalary)
{
    // modify Musician in SystemManager list
    float currentSalary = m.GetSalary();
    float diff = newSalary - currentSalary;
    m.SetSalary(newSalary);
    mu.SetPerfCost(mu.GetPerfCost() + diff);

    // modify Musician assigned to a Musical
    Musician* mmu = FindMusician(idNum, mu.GetMusicianRoster());
    mmu->SetSalary(newSalary);

    cout << "\nThe Musician's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}
void SystemManager::ModifyMusicianSalary(Musician& m, int idNum, Musical& mu, PerformanceHall& h, float newSalary)
{
    // modify Musician in SystemManager list
    float currentSalary = m.GetSalary();
    float diff = newSalary - currentSalary;
    m.SetSalary(newSalary);
     mu.SetPerfCost(mu.GetPerfCost() + diff);

    // modify Musician assigned to a Musical
    Musician* mmu = FindMusician(idNum, mu.GetMusicianRoster());
    mmu->SetSalary(newSalary);

    // modify Musician in Musical assigned to a Performance Hall
    Musical* muh = &(h.GetScheduledMusical());
    muh->SetPerfCost(muh->GetPerfCost() + diff);
    Musician* mmuh = FindMusician(idNum, muh->GetMusicianRoster());
    mmuh->SetSalary(newSalary);

    cout << "\nThe Musician's salary has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ").\n" : cout << "(decreased by " << -diff << ").\n";
}

void SystemManager::ModifyPlayTicketPrice(int perfID, vector<Play>& pList, float newPrice)
{
    Play* p = FindPlay(perfID, pList);
    float currentPrice = p->GetTicketPrice();
    float diff = newPrice - currentPrice;
    p->SetTicketPrice(newPrice);
    cout << "\nThe Play's ticket price has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ")." : cout << "(decreased by " << -diff << ").";
}

void SystemManager::ModifyMusicalTicketPrice(int perfID, vector<Musical>& mList, float newPrice)
{
    Musical* mu = FindMusical(perfID, mList);
    float currentPrice = mu->GetTicketPrice();
    float diff = newPrice - currentPrice;
    mu->SetTicketPrice(newPrice);
    cout << "\nThe Musical's ticket price has been modified ";
    (diff >= 0) ? cout << "(increased by " << diff << ")." : cout << "(decreased by " << -diff << ").";
}


// calculators
float SystemManager::CalcPerfProfit(PerformanceHall h, bool printOutput = false)
{
    Performance p = (h.GetHasPlay()) ? (Performance) h.GetScheduledPlay() : (Performance) h.GetScheduledMusical(); 
    float perfSales = (p.GetTicketPrice())*(p.GetTicketsSold()); 
    float perfCost = p.GetPerfCost(); 
    float perfProfit = perfSales - perfCost;
    if(printOutput)
    {
        cout << "\nPerformance Hall number " << h.GetHallNum() << ":" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Total amount generated by ticket sales: " << perfSales << endl;
        cout << "Total cost of Performer salaries: " << perfCost << endl;
        cout << "Profit generated by this Performance: " << perfProfit << endl;
    } 
    return perfProfit;
}

float SystemManager::CalcTotalProfit(vector<PerformanceHall> hList, bool printOutput)
{
    float totalProfit = 0.0f;
    for(PerformanceHall h : hList)
    {
        if(h.GetIsBooked()) { totalProfit += CalcPerfProfit(h, printOutput); }
    }
    return totalProfit;
}