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


// --- prototypes ---


int main()
{	system("cls");

	SystemManager SM;

 	vector<Actor> actorList = SM.GetActorList();
	vector<Play> playList = SM.GetPlayList();

	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.AddActor(actorList);

	SM.AddPlay(playList);
	SM.AddPlay(playList);   


	Actor a2 = SM.FindActor(2, actorList);
	Actor a3 = SM.FindActor(3, actorList);
	Actor a4 = SM.FindActor(4, actorList);
	Play p0 = SM.FindPlay(0, playList);
	Play p1 = SM.FindPlay(1, playList);
	vector<Actor> actors0 = p0.GetActorRoster();
	vector<Actor> actors1 = p1.GetActorRoster();
	//p.PrintActors(actors);
	//actors.push_back(Actor(17));
	//SM.AssignActor(pA,p);
	//p1.CastActor(a2, actors);
	//p1.PrintActors(actors);

/* 	cout << "\n------" << endl;
	SM.AssignActor(a4, actors0);
	p0.PrintActors(actors0);
	cout << "\n------" << endl;
	SM.AssignActor(a2,actors1);
	SM.AssignActor(a3,actors1);
	p1.PrintActors(actors1); */

/* 	cout << p0.GetNumActors();
	cout << endl;
	SM.AssignActor(a4, actors0);
	p0.PrintActors(actors0);
	p0.SetNumActors(p0.GetNumActors() + 1);
	cout << endl;
	cout << p0.GetNumActors(); */

/* 	cout << p0.GetNumActors();
	cout << endl;
	p0.CastActor(a4, actors0);
	p0.PrintActors(actors0);
	cout << endl;
	cout << p0.GetNumActors(); */

	cout << p0.GetNumActors();
	cout << endl;
	SM.AssignActor(a4, actors0, p0);
	SM.AssignActor(a3, actors0, p0);
	p0.PrintActors(p0.GetActorRoster());
	cout << endl;
	cout << p0.GetNumActors();


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