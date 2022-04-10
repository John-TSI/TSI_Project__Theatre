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
// - add remaining getters/setters to sysManager


int main()
{	system("cls");

	SystemManager SM;
/* 	Actor A1(13);
	Actor A2(14);

	SM.AddActor(A1);
	SM.AddActor(A2);

	vector<Actor> actorList = SM.GetActorList();
 	for(Actor a : actorList)
	{
		cout << a.GetIDNum() << " " << endl;
	}

	SM.RmActor(13, actorList);
	for(Actor a : actorList)
	{
		cout << a.GetIDNum() << " " << endl;
	} */


	vector<Actor> actorList = SM.GetActorList();
	SM.AddActor(actorList);
	SM.AddActor(actorList);

 	for(Actor a : actorList)
	{
		cout << a.GetIDNum() << " " << endl;
	}

	SM.RmActor(0, actorList);
	for(Actor a : actorList)
	{
		cout << a.GetIDNum() << " " << endl;
	}
 
	return 0;
}
