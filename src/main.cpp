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


int main()
{	system("cls");

	SystemManager SM;

 	vector<Actor> actorList = SM.GetActorList();
	 vector<Play> playList = SM.GetPlayList();

	SM.AddActor(actorList);
	SM.AddActor(actorList);
	SM.PrintActors(actorList);

/* 	SM.RmActor(0, actorList);
	cout << endl;
	SM.PrintActors(actorList); */

	SM.AddPlay(playList);
 	for(Play p : playList)
	{
		vector<Actor> newRoster = p.GetActorRoster();
		newRoster.push_back(Actor(12));
		p.SetActorRoster(newRoster);
/* 		p.SetNumActors(p.GetNumActors() + 1);
		cout << p.GetNumActors() << " "; */
		vector<Actor> actors = p.GetActorRoster();
		for(Actor a : actors)
		{
			cout << a.GetIDNum() << " ";
		}
	} 

 
	return 0;
}
