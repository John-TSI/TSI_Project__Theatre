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

	cout << "\n------" << endl;
	SM.AssignActor(a4, actors0);
	p1.PrintActors(actors0);
	cout << "\n------" << endl;
	SM.AssignActor(a2,actors1);
	SM.AssignActor(a3,actors1);
	p1.PrintActors(actors1);


	return 0;
}

// --- definitions ---