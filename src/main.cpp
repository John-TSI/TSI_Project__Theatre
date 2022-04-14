#include<iostream>
#include<limits>
#include<string>
#include<vector>
#include<algorithm>
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
// - implement unassign/unschedule in menu2
// - modify assignment functions: show only unassigned objects
// - modify unassignment functions: show only assigned objects
// - do not allow an assigned object to be assigned
// - move Unassign Actor in menu2 to be option below Assign Actor


// ------ PROTOTYPES (get user requests) ------
void Welcome();
int GetMainMenuRequest();

int GetMenu1Request();
// --- menu1 ---
int GetPerformerToAdd();
int GetPerformerToRm();
int GetPerformanceToAdd();
int GetPerformanceToRm();

int GetMenu2Request();
// ---menu2 ---

int GetMenu3Request();
int GetMenu4Request();

// --- misc ---
int GetIDRequest();



int main()
{	system("cls");


	SystemManager SM; // instantiate the SystemManager


	// create references of SystemManager's object lists
 	vector<Actor> actorList = SM.GetActorList();
	vector<Singer> singerList = SM.GetSingerList();
	vector<Musician> musicianList = SM.GetMusicianList();
	vector<Play> playList = SM.GetPlayList();
	vector<Musical> musicalList = SM.GetMusicalList();
	vector<PerformanceHall> perfHallList = SM.GetPerfHallList();


	// ------ BEGIN USER INTERACTIVITY ------
	Welcome();
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
										cout << "\nCurrently listed Actor IDs: { ";
										SM.PrintActors(actorList); 
										cout << "}" << endl;
										cout << "Enter the ID number of the Actor to be removed:" << endl;
										int id = GetIDRequest();
										if(!SM.VerifiedActorID(id, actorList))
										{
											cout << "\nThe specified Actor is not currently listed." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										SM.RmActor(id, actorList);
										cout << "\nThe Actor has been removed." << endl;
										cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
										break;
									}
									case 2: // selected Remove Singer
									{
										cout << "\nCurrently listed Singer IDs: { ";
										SM.PrintSingers(singerList); 
										cout << "}" << endl;
										cout << "Enter the ID number of the Singer to be removed:" << endl;
										int id = GetIDRequest();
										if(!SM.VerifiedSingerID(id, singerList))
										{
											cout << "\nThe specified Singer is not currently listed." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}										
										SM.RmSinger(id, singerList);
										cout << "\nThe Singer has been removed." << endl;
										cout << "System currently has " << SM.GetSingerCount() << " listed Singers.\n";
										break;
									}
									case 3: // selected Remove Musician
									{
										cout << "\nCurrently listed Musician IDs: { ";
										SM.PrintMusicians(musicianList); 
										cout << "}" << endl;
										cout << "Enter the ID number of the Musician to be removed:" << endl;
										int id = GetIDRequest();
										if(!SM.VerifiedMusicianID(id, musicianList))
										{
											cout << "\nThe specified Musician is not currently listed." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										SM.RmMusician(id, musicianList);
										cout << "\nThe Musician has been removed." << endl;
										cout << "System currently has " << SM.GetMusicianCount() << " listed Musicians.\n";
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
								reqAP = GetPerformanceToAdd(); // open Menu to add Performance (2+1 cases)
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
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;
										cout << "Enter the performance ID of the Play to be removed:" << endl;
										int id = GetIDRequest();
										if(!SM.VerifiedPlayID(id, playList))
										{
											cout << "\nThe specified Play is not currently listed." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										SM.RmPlay(id, playList);
										cout << "\nThe Play has been removed." << endl;
										cout << "System currently has " << SM.GetPlayCount() << " listed Plays.\n";
										break;
									}
									case 2: // selected Remove Musical
									{
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;
										cout << "Enter the performance ID of the Musical to be removed:" << endl;
										int id = GetIDRequest();
										if(!SM.VerifiedMusicalID(id, musicalList))
										{
											cout << "\nThe specified Musical is not currently listed." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										SM.RmMusical(id, musicalList);
										cout << "\nThe Musical has been removed." << endl;
										cout << "System currently has " << SM.GetMusicalCount() << " listed Musicals.\n";
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
							cout << "\nCurrently listed Performance Hall numbers: { ";
							SM.PrintHalls(perfHallList); 
							cout << "}" << endl;
							cout << "Enter the number of the Performance Hall to be removed:" << endl;
							int num = GetIDRequest();
							if(!SM.VerifiedHallNum(num, perfHallList))
							{
								cout << "\nThe specified Performance Hall is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}
							SM.RmPerfHall(num, perfHallList);
							cout << "\nThe Performance Hall has been removed." << endl;
							cout << "System currently has " << SM.GetHallCount() << " listed Performance Halls.\n";
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
					switch(req2)
					{
						case 1: // selected Assign an Actor to a Play
						{
							cout << "\nCurrently listed Actor IDs: { ";
							SM.PrintActors(actorList); 
							cout << "}" << endl;
							cout << "Enter the ID number of the Actor to be assigned:" << endl;
							int idA = GetIDRequest();
							if(!SM.VerifiedActorID(idA, actorList))
							{
								cout << "\nThe specified Actor is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}														
							cout << "\nCurrently listed Play performance IDs: { ";
							SM.PrintPlays(playList); 
							cout << "}" << endl;
							cout << "Enter the performance ID of the Play to be assigned to:" << endl;
							int idP = GetIDRequest();
							if(!SM.VerifiedPlayID(idP, playList))
							{
								cout << "\nThe specified Play is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}													
							Actor* a = SM.FindActor(idA, actorList);
							Play* p = SM.FindPlay(idP, playList);
							vector<Actor> aList = p->GetActorRoster();
							SM.AssignActor(*a, aList, *p);
							cout << "\nThe Actor has been assigned to the Play." << endl;
							//cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
							break;
						}
						case 2: // selected Assign a Singer to a Musical
						{
							cout << "\nCurrently listed Singer IDs: { ";
							SM.PrintSingers(singerList); 
							cout << "}" << endl;
							cout << "Enter the ID number of the Singer to be assigned:" << endl;
							int idS = GetIDRequest();
							if(!SM.VerifiedSingerID(idS, singerList))
							{
								cout << "\nThe specified Singer is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}							
							cout << "\nCurrently listed Musical performance IDs: { ";
							SM.PrintMusicals(musicalList); 
							cout << "}" << endl;
							cout << "Enter the performance ID of the Musical to be assigned to:" << endl;
							int idMu = GetIDRequest();
							if(!SM.VerifiedMusicalID(idMu, musicalList))
							{
								cout << "\nThe specified Musical is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}													
							Singer* s = SM.FindSinger(idS, singerList);
							Musical* mu = SM.FindMusical(idMu, musicalList);
							vector<Singer> sList = mu->GetSingerRoster();
							SM.AssignSinger(*s, sList, *mu);
							cout << "\nThe Singer has been assigned to the Musical." << endl;
							//cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
							break;
						}
						case 3: // selected Assign a Musician to a Musical
						{
							cout << "\nCurrently listed Musician IDs: { ";
							SM.PrintMusicians(musicianList); 
							cout << "}" << endl;
							cout << "Enter the ID number of the Musician to be assigned:" << endl;
							int idM = GetIDRequest();
							if(!SM.VerifiedMusicianID(idM, musicianList))
							{
								cout << "\nThe specified Musician is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}														
							cout << "\nCurrently listed Musical performance IDs: { ";
							SM.PrintMusicals(musicalList); 
							cout << "}" << endl;
							cout << "Enter the performance ID of the Musical to be assigned to:" << endl;
							int idMu = GetIDRequest();
							if(!SM.VerifiedMusicalID(idMu, musicalList))
							{
								cout << "\nThe specified Musical is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}														
							Musician* m = SM.FindMusician(idM, musicianList);
							Musical* mu = SM.FindMusical(idMu, musicalList);
							vector<Musician> mList = mu->GetMusicianRoster();
							SM.AssignMusician(*m, mList, *mu);
							cout << "\nThe Musician has been assigned to the Musical." << endl;
							//cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
							break;
						}
						case 4: // selected Schedule a Play in a Performance Hall
						{
							cout << "\nCurrently listed Play performance IDs: { ";
							SM.PrintPlays(playList); 
							cout << "}" << endl;
							cout << "Enter the performance ID of the Play to be scheduled:" << endl;
							int idP = GetIDRequest();
							if(!SM.VerifiedPlayID(idP, playList))
							{
								cout << "\nThe specified Play is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}														
							cout << "\nCurrently listed Performance Hall numbers: { ";
							SM.PrintHalls(perfHallList); 
							cout << "}" << endl;
							cout << "Enter the number of the Performance Hall to be booked:" << endl;
							int num = GetIDRequest();
							if(!SM.VerifiedHallNum(num, perfHallList))
							{
								cout << "\nThe specified Performance Hall is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}												
							Play* p = SM.FindPlay(idP, playList);
							PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
							SM.SchedulePerformance(*p, *h); // changed from SchedulePlay()
							cout << "\nThe Play has been scheduled in the Performance Hall." << endl;
							//cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
							break;
						}
						case 5: // selected Schedule a Musical in a Performance Hall
						{
							cout << "\nCurrently listed Musical performance IDs: { ";
							SM.PrintMusicals(musicalList); 
							cout << "}" << endl;
							cout << "Enter the performance ID of the Musical to be scheduled:" << endl;
							int idMu = GetIDRequest();
							if(!SM.VerifiedMusicalID(idMu, musicalList))
							{
								cout << "\nThe specified Musical is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}													
							cout << "\nCurrently listed Performance Hall numbers: { ";
							SM.PrintHalls(perfHallList); 
							cout << "}" << endl;
							cout << "Enter the number of the Performance Hall to be booked:" << endl;
							int num = GetIDRequest();
							if(!SM.VerifiedHallNum(num, perfHallList))
							{
								cout << "\nThe specified Performance Hall is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}														
							Musical* mu = SM.FindMusical(idMu, musicalList);
							PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
							SM.SchedulePerformance(*mu, *h);
							cout << "\nThe Musical has been scheduled in the Performance Hall." << endl;
							//cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";
							break;
						}
						case 6: // selected Unassign an Actor
						{
							cout << "\nCurrently listed Actor IDs: { ";
							SM.PrintActors(actorList); 
							cout << "}" << endl;
							cout << "Enter the ID of the Actor to be unassigned:" << endl;
							int idA = GetIDRequest();
							if(!SM.VerifiedActorID(idA, actorList))
							{
								cout << "\nThe specified Actor is not currently listed." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}
							Actor* a = SM.FindActor(idA, actorList);
							int idP = a->GetInPerfID();
							if(idP == -1)
							{
								cout << "\nThe specified Actor is not currently assigned to a Play." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}
							Play* p = SM.FindPlay(idP, playList);
							vector<Actor>& aList = p->GetActorRoster();
							SM.UnassignActor(*a, aList, *p); // this call will incorrectly decrement the SM actorCount attribute...
							SM.SetActorCount(SM.GetActorCount() + 1); // ...so increment it here to correct
							cout << "\nThe Actor has been removed from the Play roster." << endl;
							//cout << "System currently has " << SM.GetActorCount() << " listed Actors.\n";						
							break;
						}
						
					}
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
/* 	Actor* a1 = SM.FindActor(1, actorList);
	Actor* a2 = SM.FindActor(2, actorList); */
	cout << "Listed Actors: ";
	SM.PrintActors(actorList);

 	cout << endl;
	Play* p0 = SM.FindPlay(0, playList);
	//Musical* mu0 = SM.FindMusical(0, musicalList);
	cout << "Listed Plays: ";
	SM.PrintPlays(playList);

	cout << endl;
	SM.PrintActors(p0->GetActorRoster());
 	cout << endl;
/* 	cout << SM.GetActorCount() << endl;
	cout << SM.FindActor(1, actorList)->GetIsAssigned() << endl;
	cout << SM.FindActor(1, actorList)->GetInPerfID() << endl;
	cout << SM.FindActor(2, actorList)->GetIsAssigned() << endl;
	cout << SM.FindActor(2, actorList)->GetInPerfID() << endl; */
	cout << SM.FindPlay(0, playList)->GetIsScheduled() << endl;
	cout << SM.FindPlay(1, playList)->GetIsScheduled() << endl;
	cout << SM.FindPerfHall(0, perfHallList)->GetScheduledPerf().GetIsFullyCast() << endl;
	cout << SM.FindPerfHall(1, perfHallList)->GetIsBooked() << endl;


	// --- END TESTING ---


	return 0;
}



// ------ DEFINITIONS ------
void Welcome()
{
	cout << "()()()()()()()()()()()()()()()()" << endl;
	cout << "() Welcome to THEATRE MANAGER ()" << endl;
	cout << "()()()()()()()()()()()()()()()()" << endl;
}

int GetMainMenuRequest()
{
	int req = -1;
	cout << "\nSelect a menu option:" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "1 ....... Add/Remove" << endl;
	cout << "2 ....... Assign/Unassign/Schedule/Unschedule" << endl;
	cout << "3 ....... Check/Verify" << endl;
	cout << "4 ....... Utility" << endl;
	cout << "0 ....... Exit the program" << endl;
	cout << "---------------------------------------------" << endl;
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
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		req = -1;
		return req;
	}
	return req;
}

int GetPerformerToRm()
{
	int req = -1;
	cout << "\nSelect a Performer to remove:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1 ....... Remove an Actor from the System" << endl;
	cout << "2 ....... Remove a Singer from the System" << endl;
	cout << "3 ....... Remove a Musician from the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		req = -1;
		return req;
	}
	return req;
}

int GetPerformanceToAdd()
{
	int req = -1;
	cout << "\nSelect a Performance to add:" << endl;
	cout << "-------------------------------------" << endl;
	cout << "1 ....... Add a Play to the System" << endl;
	cout << "2 ....... Add a Musical to the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "-------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		req = -1;
		return req;
	}
	return req;
}

int GetPerformanceToRm()
{
	int req = -1;
	cout << "\nSelect a Performance to remove:" << endl;
	cout << "------------------------------------------" << endl;
	cout << "1 ....... Remove a Play from the System" << endl;
	cout << "2 ....... Remove a Musical from the System" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	cout << "--------------------------------------------------" << endl;
	cout << "1 ....... Assign an Actor to a Play" << endl;
	cout << "2 ....... Assign a Singer to a Musical" << endl;
	cout << "3 ....... Assign a Musician to a Musical" << endl;
	cout << "4 ....... Schedule a Play in a Performance Hall" << endl;
	cout << "5 ....... Schedule a Musical in a Performance Hall" << endl;
	cout << "6 ....... Unassign an Actor" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		req = -1;
		return req;
	}
	return req;
} 

// --- MENU2 ---


// ------------


int GetMenu3Request()
{
	int req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "1 ....... Verify a Play is fully cast" << endl;
	cout << "2 ....... Verify a Musical is fully cast" << endl;
	cout << "3 ....... Check whether a Performance Hall is booked" << endl;
	cout << "4 ....... Check status of all Performance Halls" << endl;
	cout << "5 ....... Verify all scheduled Performances are prepared" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		req = -1;
		return req;
	}
	return req;
}

// --- MISC ---
int GetIDRequest()
{
	int req = -1;
	cout << "> ";
	cin >> req;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		req = -1;
		return req;
	}
	return req;
}