#include<iostream>
#include<limits>
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
// - verify schedPerf.ticketSold <= hall.capacity
// - performance.hpp remove vector<Performer> attribute / methods ?
// - implement a user guide option in one of the menus


// ------ PROTOTYPES (get user requests) ------
void Introduction();
int GetMainMenuRequest();

int GetMenu1Request();
// --- menu1 ---
int GetPerformerToAdd();
int GetPerformerToRm();
int GetPerformanceToAdd();
int GetPerformanceToRm();

int GetMenu2Request();
int GetMenu3Request();
int GetMenu4Request();

// --- misc ---
int GetActorID();
int GetSingerID();
int GetMusicianID();
int GetPlayID();
int GetMusicalID();
int GetHallNum();



int main()
{	system("cls");

	SystemManager SM; // instantiate the SystemManager

	// create references of SystemManager's lists
 	vector<Actor> actorList = SM.GetActorList();
	vector<Singer> singerList = SM.GetSingerList();
	vector<Musician> musicianList = SM.GetMusicianList();
	vector<Play> playList = SM.GetPlayList();
	vector<Musical> musicalList = SM.GetMusicalList();
	vector<PerformanceHall> perfHallList = SM.GetPerfHallList();


	// --- TESTING ---
	// add some objects to the SystemManager's lists
/* 	SM.AddActor(actorList);
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
	PerformanceHall* h1 = SM.FindPerfHall(1, perfHallList); */




	// checking result of AssignActor()
/*  	cout << p0->GetNumActors() << endl;
	cout << SM.IsFullyCast(*p0) << endl;
	SM.AssignActor(*a4, actors0, *p0);
	SM.AssignActor(*a3, actors0, *p0);
	p0->PrintActors(p0->GetActorRoster());
	cout << endl;
	cout << p0->GetNumActors() << endl;
	cout << SM.IsFullyCast(*p0);
	cout << "\n------" << endl; */ 

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

// checking assigning performers to performance and perf to a hall
/* 	cout << h1->GetHallNum() << endl;
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
	cout << SM.CalcTotalProfit(perfHallList)  << endl; */

	//cout << GetMenuRequest();


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


	// --- END TESTING ---


	// ------ BEGIN USER INTERACTIVITY ------
	Introduction();
	int mainReq = -1;
	while(mainReq != 0)
	{
		mainReq = GetMainMenuRequest(); // open MainMenu (4+1 cases)
		switch(mainReq)
		{
			case 1: // selected Menu1 : Add/Remove
			{
				int req1 = -1;
				while(req1 != 0)
				{
					req1 = GetMenu1Request(); // open Menu1 (6+1 cases)
					switch(req1)
					{
						case 1: // selected Add Performer
						{
							int reqAP = -1;
							while(reqAP != 0)
							{
								reqAP = GetPerformerToAdd(); // open Menu to Add Performer (3+1 cases)
								switch(reqAP)
								{
									case 1: // selected Add Actor
									{
										SM.AddActor(actorList);
										cout << "\nAn Actor has been added." << endl;
										cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
										break;
									}
									case 2: // selected Add Singer
									{
										SM.AddSinger(singerList);
										cout << "\nA Singer has been added." << endl;
										cout << "System currently has " << SM.GetSingerCount() << " listed Singers.\n";
										break;
									}
									case 3: // selected Add Musician
									{
										SM.AddMusician(musicianList);
										cout << "\nA Musician has been added." << endl;
										cout << "System currently has " << SM.GetMusicianCount() << " listed Musicians.\n";
										break;
									}
									case 0:
									{
										reqAP = 0;
										break;
									}
									default:
										cout << "\nInvalid input, please review the input options and try again." << endl;					
								}
							}
							break;
						}
						case 2: // selected Remove Performer
						{
							int reqRP = -1;
							while(reqRP != 0)
							{
								reqRP = GetPerformerToRm(); // open Menu to Remove Performer (3+1 cases)
								switch(reqRP)
								{
									case 1: // selected Remove Actor
									{
										int id = GetActorID();
										if(!SM.VerifiedActorID(id, actorList))
										{
											cout << "\nThe specified Actor is not currently listed." << endl;
											cout << "Currently listed Actor IDs: { ";
											SM.PrintActors(actorList); 
											cout << "}\nCheck your input and try again.\n" << endl;
											break;
										}
										else
										{
											SM.RmActor(id, actorList);
											cout << "\nThe Actor has been removed." << endl;
											cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
										}
										break;
									}
									case 2: // selected Remove Singer
									{
										int id = GetSingerID();
										if(!SM.VerifiedSingerID(id, singerList))
										{
											cout << "\nThe specified Singer is not currently listed." << endl;
											cout << "Currently listed Singer IDs: { ";
											SM.PrintSingers(singerList); 
											cout << "}\nCheck your input and try again.\n" << endl;
											break;
										}
										else
										{
											SM.RmSinger(id, singerList);
											cout << "\nThe Singer has been removed." << endl;
											cout << "System currently has " << SM.GetSingerCount() << " listed Singers.\n";
										}
										break;
									}
									case 3: // selected Remove Musician
									{
										int id = GetMusicianID();
										if(!SM.VerifiedMusicianID(id, musicianList))
										{
											cout << "\nThe specified Musician is not currently listed." << endl;
											cout << "Currently listed Musician IDs: { ";
											SM.PrintMusicians(musicianList); 
											cout << "}\nCheck your input and try again.\n" << endl;
											break;
										}
										else
										{
											SM.RmMusician(id, musicianList);
											cout << "\nThe Musician has been removed." << endl;
											cout << "System currently has " << SM.GetMusicianCount() << " listed Muscians.\n";
										}
										break;
									}
									case 0:
									{
										reqRP = 0;
										break;
									}
									default:
										cout << "\nInvalid input, please review the input options and try again." << endl;					
								}
							}
							break;
						}
						case 3: // selected Add Performance
						{
							int reqAP = -1;
							while(reqAP != 0)
							{
								reqAP = GetPerformanceToAdd(); // open menu to add Performance (2+1 cases)
								switch(reqAP)
								{
									case 1:
									{
										SM.AddPlay(playList);
										cout << "\nA Play has been added." << endl;
										cout << "System currently has " << SM.GetPlayCount() << " listed Plays.\n";
										break;
									}
									case 2:
									{
										SM.AddMusical(musicalList);
										cout << "\nA Musical has been added." << endl;
										cout << "System currently has " << SM.GetMusicalCount() << " listed Musicals.\n";
										break;
									}
									case 0:
									{
										reqAP = 0;
										break;
									}
									default:
										cout << "\nInvalid input, please review the input options and try again." << endl;					
								}
							}
							break;
						}
						case 4: // selected Remove Performance
						{
							int reqRP = -1;
							while(reqRP != 0)
							{
								reqRP = GetPerformanceToRm(); // open Menu to Remove Performance (2+1 cases)
								switch(reqRP)
								{
									case 1: // selected Remove Play
									{
										int id = GetPlayID();
										if(!SM.VerifiedPlayID(id, playList))
										{
											cout << "\nThe specified Play is not currently listed." << endl;
											cout << "Currently listed Play IDs: { ";
											SM.PrintPlays(playList); 
											cout << "}\nCheck your input and try again.\n" << endl;
											break;
										}
										else
										{
											SM.RmPlay(id, playList);
											cout << "\nThe Play has been removed." << endl;
											cout << "System currently has " << SM.GetPlayCount() << " listed Plays.\n";
										}
										break;
									}
									case 2: // selected Remove Musical
									{
										int id = GetMusicalID();
										if(!SM.VerifiedMusicalID(id, musicalList))
										{
											cout << "\nThe specified Musical is not currently listed." << endl;
											cout << "Currently listed Musical IDs: { ";
											SM.PrintMusicals(musicalList); 
											cout << "}\nCheck your input and try again.\n" << endl;
											break;
										}
										else
										{
											SM.RmMusical(id, musicalList);
											cout << "\nThe Musical has been removed." << endl;
											cout << "System currently has " << SM.GetMusicalCount() << " listed Musicals.\n";
										}
										break;
									}
									case 0:
									{
										reqRP = 0;
										break;
									}
									default:
										cout << "\nInvalid input, please review the input options and try again." << endl;					
								}
							}
							break;
						}
						case 5: // selected Add a Performance Hall
						{
							SM.AddPerfHall(perfHallList);
							cout << "\nA Performance Hall has been added." << endl;
							cout << "System currently has " << SM.GetHallCount() << " listed Performance Halls.\n";
							break;
						}
						case 6: // selected Remove a Performance Hall
						{
							int num = GetHallNum();
							if(!SM.VerifiedHallNum(num, perfHallList))
							{
								cout << "\nThe specified Performance Hall is not currently listed." << endl;
								cout << "Currently listed Performance Hall numbers: { ";
								SM.PrintHalls(perfHallList); 
								cout << "}\nCheck your input and try again.\n" << endl;
								break;
							}
							else
							{
								SM.RmPerfHall(num, perfHallList);
								cout << "\nThe Performance Hall has been removed." << endl;
								cout << "System currently has " << SM.GetHallCount() << " listed Performance Halls.\n";
							}
							break;
						}
						case 0:
						{
							req1 = 0;
							break;
						}
						default:
							cout << "\nInvalid input, please review the input options and try again." << endl;					
					}
				}
				break;
			}

			case 2: // selected Menu2 : Assign/Schedule
			{
				int req2 = -1;
				while(req2 != 0)
				{
					req2 = GetMenu2Request();
					// insert switch here
					cout << req2 << endl;
				}
				break;
			}

			case 3: //  selected Menu3 : Check/Verify
			{
				int req3 = -1;
				while(req3 != 0)
				{
					req3 = GetMenu3Request();
					// insert switch here
					cout << req3 << endl;
				}
				break;
			}

			case 4: // selected Menu4 : Utility
			{
				int req4 = -1;
				while(req4 != 0)
				{
					req4 = GetMenu4Request();
					// insert switch here
					cout << req4 << endl;
				}
				break;
			}

			case 0:
			{
/* 				cout << "\nExiting program." << endl;
				return 0; */
				mainReq = 0; // break out of main loop only while TESTING
				break;
			}

			default:
				cout << "\nInvalid input, please review the input options and try again." << endl;
		}
	}


	// --- TESTING ---
	
	cout << endl;
	Actor* a0 = SM.FindActor(0, actorList);
	Actor* a1 = SM.FindActor(1, actorList);
	Actor* a2 = SM.FindActor(2, actorList);
	cout << "Listed Actors: ";
	SM.PrintActors(actorList);

/* 	cout << endl;
	Play* p0 = SM.FindPlay(0, playList);
	Musical* mu0 = SM.FindMusical(0, musicalList);
	cout << "Listed Plays: ";
	SM.PrintPlays(playList);
	cout << endl;
	cout << "Listed Musicals: ";
	SM.PrintMusicals(musicalList);

	cout << endl;
	PerformanceHall* h0 = SM.FindPerfHall(0, perfHallList);
	cout << "Listed Halls: ";
	SM.PrintHalls(perfHallList); */

	cout << endl;
	cout << SM.VerifiedActorID(1, actorList) << endl;
	cout << SM.VerifiedActorID(21, actorList) << endl;



	// --- END TESTING ---


	return 0;
}



// ------ DEFINITIONS ------
void Introduction()
{
	cout << "()()()()()()()()()()()()()()()()" << endl;
	cout << "() Welcome to THEATRE MANAGER ()" << endl;
	cout << "()()()()()()()()()()()()()()()()\n" << endl;
}

int GetMainMenuRequest()
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
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
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
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

// --- MENU1 ---
int GetPerformerToAdd()
{
	int req = -1;
	cout << "\nSelect a Performer to add:" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1 ....... Add an Actor to the System" << endl;
	cout << "2 ....... Add a Singer to the System" << endl;
	cout << "3 ....... Add a Musician to the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetPerformerToRm()
{
	int req = -1;
	cout << "\nSelect a Performer to remove:" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1 ....... Remove an Actor from the System" << endl;
	cout << "2 ....... Remove a Singer from the System" << endl;
	cout << "3 ....... Remove a Musician from the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetPerformanceToAdd()
{
	int req = -1;
	cout << "\nSelect a Performance to add:" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1 ....... Add a Play to the System" << endl;
	cout << "2 ....... Add a Musical to the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetPerformanceToRm()
{
	int req = -1;
	cout << "\nSelect a Performance to remove:" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1 ....... Remove a Play from the System" << endl;
	cout << "2 ....... Remove a Musical from the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

// ------------

int GetMenu2Request()
{
	int req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "1 ....... Assign an Actor to a Play" << endl;
	cout << "2 ....... Assign a Singer to a Musical" << endl;
	cout << "3 ....... Assign a Musician to a Musical" << endl;
	cout << "4 ....... Schedule a Play in a Performance Hall" << endl;
	cout << "5 ....... Schedule a Musical Hall in a Performance Hall" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
} 

int GetMenu3Request()
{
	int req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "1 ....... Verify a Play is fully cast" << endl;
	cout << "2 ....... Verify a Musical is fully cast" << endl;
	cout << "3 ....... Check whether a Performance Hall is booked" << endl;
	cout << "4 ....... Check status of all Performance Halls" << endl;
	cout << "5 ....... Verify all scheduled Performances are prepared" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
} 

int GetMenu4Request()
{
	int req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1 ....... Calculate profit of a scheduled Performance" << endl;
	cout << "2 ....... Calculate total profit of all scheduled Performances " << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

// --- MISC ---
int GetActorID()
{
	int req = -1;
	cout << "\nEnter the ID number of the Actor to be removed:" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetSingerID()
{
	int req = -1;
	cout << "\nEnter the ID number of the Singer to be removed:" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetMusicianID()
{
	int req = -1;
	cout << "\nEnter the ID number of the Musician to be removed:" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetPlayID()
{
	int req = -1;
	cout << "\nEnter the performance ID number of the Play to be removed:" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetMusicalID()
{
	int req = -1;
	cout << "\nEnter the performance ID number of the Musical to be removed:" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}

int GetHallNum()
{
	int req = -1;
	cout << "\nEnter the hall number of the Performance Hall to be removed:" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores rest of user input
		req = -1;
		return req;
	}
	return req;
}