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

	SM.AddPlay(playList);
	SM.AddPlay(playList);   


	Actor a = SM.FindActor(2, actorList);
	Play p = SM.FindPlay(1, playList);
	vector<Actor> actors = p.GetActorRoster();
	//p.PrintActors(actors);
	//actors.push_back(Actor(17));
	//SM.AssignActor(pA,p);
	p.CastActor(a, actors);
	p.PrintActors(actors);

	cout << "\n------" << endl;
	SM.AssignActor(a,p);
	Play p1 = SM.FindPlay(1, playList);
	vector<Actor> actors1 = p1.GetActorRoster();
	p1.PrintActors(actors1);


	return 0;
}

// --- definitions ---