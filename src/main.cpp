#include<iostream>
#include<string>
#include<vector>
#include"../include/actor.hpp"
#include"../include/singer.hpp"
#include"../include/musician.hpp"
#include"../include/hall.hpp"
#include"../include/play.hpp"
#include"../include/musical.hpp"
#include"../include/sysManager.hpp"

using std::cout; using std::cin; using std::endl;


// ------ TO DO ------
// - remove default constructors? (require instantiate with ID number)
// - change Find methods to return pointers?
// - verify schedPerf.ticketSold <= hall.capacity
// - performance.hpp remove vector<Performer> attribute / methods ?

// --- prototypes ---
int GetMenuRequest();
int GetMenu1Request();
int GetMenu2Request();


int main()
{	system("cls");

	SystemManager SM;

	// create references of SystemManager's lists
 	vector<Actor> actorList = SM.GetActorList();
	vector<Singer> singerList = SM.GetSingerList();
	vector<Musician> musicianList = SM.GetMusicianList();
	vector<Play> playList = SM.GetPlayList();
	vector<Musical> musicalList = SM.GetMusicalList();
	vector<PerformanceHall> perfHallList = SM.GetPerfHallList();


	// add some objects to the SystemManager's lists
	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.AddActor(actorList);

	SM.AddSinger(singerList);

	SM.AddMusician(musicianList);

	SM.AddPlay(playList);
	SM.AddPlay(playList);
	SM.AddPlay(playList);   

	SM.AddMusical(musicalList);

	SM.AddPerfHall(perfHallList);
	SM.AddPerfHall(perfHallList);


	// find and assign using SM methods
	Actor* a2 = SM.FindActor(2, actorList);
	Actor* a3 = SM.FindActor(3, actorList);
	Actor* a4 = SM.FindActor(4, actorList); 
	Singer* s0 = SM.FindSinger(0, singerList);
	Musician* m0 = SM.FindMusician(0, musicianList);

	Play* p0 = SM.FindPlay(0, playList);
	Play* p1 = SM.FindPlay(1, playList);
	Play* p2 = SM.FindPlay(2, playList);
	Musical* mu0 = SM.FindMusical(0, musicalList);

	vector<Actor> actors0 = p0->GetActorRoster();
	vector<Actor> actors1 = p1->GetActorRoster();
	vector<Actor> actors2 = p2->GetActorRoster();
	vector<Singer> singers0 = mu0->GetSingerRoster();
	vector<Musician> musicians0 = mu0->GetMusicianRoster();

	PerformanceHall* h0 = SM.FindPerfHall(0, perfHallList);
	PerformanceHall* h1 = SM.FindPerfHall(1, perfHallList);



	// checking result of AssignActor()
 /* 	cout << p0->GetNumActors() << endl;
	cout << SM.FullyCast(*p0) << endl;
	SM.AssignActor(*a4, actors0, *p0);
	SM.AssignActor(*a3, actors0, *p0);
	p0->PrintActors(p0->GetActorRoster());
	cout << endl;
	cout << p0->GetNumActors() << endl;
	cout << SM.FullyCast(*p0);
	cout << "\n------" << endl;  */

	// checking result of AssignSinger()
/* 	cout << m0.GetNumSingers() << endl;
	SM.AssignSinger(s0, singers0, m0);
	m0.PrintSingers(m0.GetSingerRoster());
	cout << endl;
	cout << m0.GetNumSingers() << endl;
	cout << s0.GetAssigned() << endl; */

	// checking result of SchedulePlay()
/* 	h0.PrintPerformance(h1.GetScheduledPerf() );
	cout << endl;
	cout << p2.GetScheduled() << endl;
	cout << p2.GetHallNum() << endl;
	cout << h1.GetBooked();
	cout << "\n------" << endl;
	SM.SchedulePlay(p2, h1);
	h1.PrintPerformance(h1.GetScheduledPerf() );
	cout << endl;
	cout << p2.GetScheduled() << endl;
	cout << p2.GetHallNum() << endl;
	cout << h1.GetBooked(); */

	cout << h1->GetHallNum() << endl;
	h1->SetHallNum(33);
	//cout << SM.FindPerfHall(33,perfHallList)->GetHallNum();
	cout << h1->GetHallNum();
	cout << endl;
	SM.PrintHalls(perfHallList);
	//SM.RmPerfHall(0, perfHallList);
	cout << endl;
	SM.PrintHalls(perfHallList);
	cout << endl;
	PerformanceHall* h33 = SM.FindPerfHall(33, perfHallList);

	SM.AssignActor(*a4, actors2, *p2);
	SM.AssignActor(*a3, actors2, *p2); // optional extra actor
	SM.AssignSinger(*s0, singers0, *mu0);
	SM.AssignMusician(*m0, musicians0, *mu0);

	SM.SchedulePlay(*p2, *h33);
	SM.ScheduleMusical(*mu0, *h0);
	cout << endl;
	SM.CheckHallsStatus(perfHallList);
	cout << endl;
	cout << SM.AllPerfsReady(perfHallList) << endl;
	cout << SM.CalcPerfProfit(*h33) << endl;
	cout << SM.CalcTotalProfit(perfHallList)  << endl;

	cout << GetMenuRequest();


/* 	auto RetActors = [&](int idNum, int perfID)
	{
		Actor a = SM.FindActor(idNum, actorList);
		Play p = SM.FindPlay(perfID, playList);
		vector<Actor> actors = p.GetActorRoster();
		return actors;
	}; 
	cout << "\n------" << endl;
	vector<Actor> actors = RetActors(4,0);
	SM.AssignActor(4, actors);
	p0.PrintActors(actors0); */


	return 0;
}

// --- definitions ---
int GetMenuRequest()
{
	int req = -1;
	cout << "\nSelect a menu option:" << endl;
	cout << "-------------------------" << endl;
	cout << "1 ....... Add/Remove" << endl;
	cout << "2 ....... Assign/Schedule" << endl;
	cout << "3 ....... Check/Verify" << endl;
	cout << "4 ....... Utility" << endl;
	cout << "0 ....... Exit the program" << endl;
	cout << "--------------------------" << endl;
	cout << "> ";
	cin >> req;
	return req;
}

int GetMenu1Request()
{
	int req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "1 ....... Add a Performer to the System" << endl;
	cout << "2 ....... Remove a Performer from the System" << endl;
	cout << "3 ....... Add a Performance to the System" << endl;
	cout << "4 ....... Remove a Performance from the System" << endl;
	cout << "5 ....... Add a Performance Hall to the System" << endl;
	cout << "6 ....... Remove a Performance Hall from the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	return req;
}

int GetMenu2Request()
{
	
}