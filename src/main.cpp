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
// - implement a ClearScreen() after receiving user menu request
// - implement an UnassignAll() method to unassign all performers from a performance
// - give User option to back out instead of forcing ID/num input
// - implement a ModifyReqActors() for a Play, similarly for Musical
//		- implement a CheckIfFullyCast() when calculating, issue warning and omit if false
// - implement a check when modifying salary: if assigned/when assigning, issue warning if newSalary costs more than ticket sales
// - remove unused attributes and methods


// ------ PROTOTYPES ------
void Welcome();
void Exiting();
float GetMainMenuRequest();
void Help();

// --- menu1 ---
float GetMenu1Request();
float GetPerformerToAdd();
float GetPerformerToRm();
float GetPerformanceToAdd();
float GetPerformanceToRm();

// --- menu2 ---
float GetMenu2Request();
float GetPerformerToAssign();
float GetPerformerToUnassign();
float GetPerformanceToSchedule();
float GetPerformanceToUnschedule();

// --- menu3 ---
float GetMenu3Request();

// --- menu4 ---
float GetMenu4Request();
float GetPerformerSalaryToModify();
float GetNewSalary();
float GetPerformanceTicketPriceToModify();
float GetNewPrice();
float GetPerformanceTicketSalesToModify();
float GetNewSales();
float GetNewCapacity();

// --- misc ---
float GetIDRequest();
void WarningInvalidInput();
void WarningUnlistedActor(); void WarningUnlistedSinger(); void WarningUnlistedMusician(); void WarningUnlistedPlay(); void WarningUnlistedMusical(); void WarningUnlistedHall();



int main()
{	system("cls");


	SystemManager SM; // instantiate the SystemManager


	// create references to SystemManager's object lists
 	vector<Actor> actorList = SM.GetActorList();
	vector<Singer> singerList = SM.GetSingerList();
	vector<Musician> musicianList = SM.GetMusicianList();
	vector<Play> playList = SM.GetPlayList();
	vector<Musical> musicalList = SM.GetMusicalList();
	vector<PerformanceHall> perfHallList = SM.GetPerfHallList();


	// ------ BEGIN USER INTERACTIVITY ------
	Welcome();
	int mainReq = -1;
	bool specifyMode = false; // if true require that User initialise Performer salary, 
	                         // Performance ticket price, and Hall capacity (toggled in Utility menu)
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
						case 1: // selected Add a Performer to the SystemManager
						{
							int reqAP = -1;
							while(reqAP != 0)
							{
								reqAP = GetPerformerToAdd(); // open Menu to Add a Performer (3+1 cases)
								switch(reqAP)
								{
									case 1: // selected Add a Actor
									{
										if(specifyMode)
										{
											float newSalary = GetNewSalary();
											if(newSalary == -1.0f) { WarningInvalidInput(); break; }
											SM.AddActor(actorList, newSalary);
										}
										else { SM.AddActor(actorList); }
										break;
									}
									case 2: // selected Add a Singer
									{
										if(specifyMode)
										{
											float newSalary = GetNewSalary();
											if(newSalary == -1.0f) { WarningInvalidInput(); break; }
											SM.AddSinger(singerList, newSalary);
										}
										else { SM.AddSinger(singerList); }
										break;
									}
									case 3: // selected Add a Musician
									{
										if(specifyMode)
										{
											float newSalary = GetNewSalary();
											if(newSalary == -1.0f) { WarningInvalidInput(); break; }
											SM.AddMusician(musicianList, newSalary);
										}
										else { SM.AddMusician(musicianList); }
										break;
									}
									case 0:
									{
										reqAP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 2: // selected Remove a Performer from the SystemManager
						{
							int reqRP = -1;
							while(reqRP != 0)
							{
								reqRP = GetPerformerToRm(); // open Menu to Remove a Performer (3+1 cases)
								switch(reqRP)
								{
									case 1: // selected Remove an Actor
									{
										// output info to User
										cout << "\nCurrently listed Actor IDs: { ";
										SM.PrintActors(actorList); 
										cout << "}" << endl;

										// get User Actor request
										cout << "Enter the ID number of the Actor to be removed:" << endl;
										int idA = GetIDRequest();
										
										// break if user input is of invalid type
										if(idA == -1) { WarningInvalidInput(); break; }

										// break if Actor not listed on SystemManager
										if(!SM.VerifiedActorID(idA, actorList)) { WarningUnlistedActor(); break; }
										SM.RmActor(idA, actorList, false);
										break;
									}
									case 2: // selected Remove a Singer
									{
										// output info to User
										cout << "\nCurrently listed Singer IDs: { ";
										SM.PrintSingers(singerList); 
										cout << "}" << endl;

										// get User Singer request
										cout << "Enter the ID number of the Singer to be removed:" << endl;
										int idS = GetIDRequest();

										// break if user input is of invalid type
										if(idS == -1) { WarningInvalidInput(); break; }

										// break if Singer not listed on SystemManager
										if(!SM.VerifiedSingerID(idS, singerList)) { WarningUnlistedSinger(); break; }										
										SM.RmSinger(idS, singerList, false);
										break;
									}
									case 3: // selected Remove a Musician
									{
										cout << "\nCurrently listed Musician IDs: { ";
										SM.PrintMusicians(musicianList); 
										cout << "}" << endl;
										cout << "Enter the ID number of the Musician to be removed:" << endl;
										int idM = GetIDRequest();

										// break if user input is of invalid type
										if(idM == -1) { WarningInvalidInput(); break; }

										 // break if Musician not listed on SystemManager
										if(!SM.VerifiedMusicianID(idM, musicianList)) { WarningUnlistedMusician(); break; }
										SM.RmMusician(idM, musicianList, false);
										break;
									}
									case 0:
									{
										reqRP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 3: // selected Add a Performance to the SystemManager
						{
							int reqAP = -1;
							while(reqAP != 0)
							{
								reqAP = GetPerformanceToAdd(); // open Menu to add a Performance (2+1 cases)
								switch(reqAP)
								{
									case 1: // selected Add a Play
									{
										if(specifyMode)
										{
											float newPrice = GetNewPrice();
											if(newPrice == -1.0f) { WarningInvalidInput(); break; }
											SM.AddPlay(playList, newPrice);
										}
										else { SM.AddPlay(playList); }
										break;
									}
									case 2: // selected Add a Musical
									{
										if(specifyMode)
										{
											float newPrice = GetNewPrice();
											if(newPrice == -1.0f) { WarningInvalidInput(); break; }
											SM.AddMusical(musicalList, newPrice);
										}
										else { SM.AddMusical(musicalList); }
										break;
									}
									case 0:
									{
										reqAP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 4: // selected Remove a Performance from the SystemManager
						{
							int reqRP = -1;
							while(reqRP != 0)
							{
								reqRP = GetPerformanceToRm(); // open Menu to Remove a Performance (2+1 cases)
								switch(reqRP)
								{
									case 1: // selected a Remove Play
									{
										// output info to User
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;

										// get User Play request
										cout << "Enter the performance ID of the Play to be removed:" << endl;
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Play not listed on SystemManager
										if(!SM.VerifiedPlayID(idP, playList)) { WarningUnlistedPlay(); break; }
										SM.RmPlay(idP, playList);
										break;
									}
									case 2: // selected a Remove Musical
									{
										// output info to User
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;
										cout << "Enter the performance ID of the Musical to be removed:" << endl;

										// get User Musical request
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										 // break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idP, musicalList)) { WarningUnlistedMusical(); break; }
										SM.RmMusical(idP, musicalList);
										break;
									}
									case 0:
									{
										reqRP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 5: // selected Add a Performance Hall to the SystemManager
						{
							if(specifyMode)
							{
								int newCapacity = GetNewCapacity();
								if(newCapacity == -1) { WarningInvalidInput(); break; }
								SM.AddPerfHall(perfHallList, newCapacity);
							}
							else { SM.AddPerfHall(perfHallList); }
							break;
						}
						case 6: // selected Remove a Performance Hall from the SystemManager
						{
							// output info to User
							cout << "\nCurrently listed Performance Hall numbers: { ";
							SM.PrintHalls(perfHallList); 
							cout << "}" << endl;

							// get User Hall request
							cout << "Enter the number of the Performance Hall to be removed:" << endl;
							int num = GetIDRequest();

							// break if user input is of invalid type
							if(num == -1) { WarningInvalidInput(); break; }

							// break if Performance Hall not listed on SystemManager
							if(!SM.VerifiedHallNum(num, perfHallList)) { WarningUnlistedHall(); break; }
							SM.RmPerfHall(num, perfHallList);
							break;
						}
						case 0:
						{
							req1 = 0;
							break;
						}
						default:
							WarningInvalidInput();					
					}
				}
				break;
			}


			case 2: // selected Menu2 : Assign/Schedule
			{
				int req2 = -1;
				while(req2 != 0)
				{
					req2 = GetMenu2Request(); // open Menu2 (4+1 cases)
					switch(req2)
					{
						case 1: // selected Assign a Performer
						{
							int reqAP = -1;
							while(reqAP != 0)
							{
								reqAP = GetPerformerToAssign(); // open Menu to Assign a Performer (3+1 cases)
								switch(reqAP)
								{
									case 1: // selected Assign an Actor to a Play
									{
										// output info to User
										cout << "\nCurrently listed Actor IDs: { ";
										SM.PrintActors(actorList); 
										cout << "}" << endl;
										cout << "Currently unassigned Actor IDs: { ";
										SM.PrintUnassignedActors(actorList); 
										cout << "}" << endl;

										// get User Actor request
										cout << "Enter the ID number of the Actor to be assigned:" << endl;
										int idA = GetIDRequest();

										// break if user input is of invalid type
										if(idA == -1) { WarningInvalidInput(); break; }

										// break if Actor not listed on SystemManager
										if(!SM.VerifiedActorID(idA, actorList)) { WarningUnlistedActor(); break; }

										Actor* a = SM.FindActor(idA, actorList);
										int inPerfID = a->GetInPerfID();	
										if(inPerfID != -1) // break if Actor is already assigned to a Play
										{
											cout << "\nThe specified Actor is already assigned to Play with performance ID " << inPerfID << "." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}

										// get User Play request
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;
										cout << "Enter the performance ID of the Play to be assigned to:" << endl;
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Play not listed on SystemManager
										if(!SM.VerifiedPlayID(idP, playList)) { WarningUnlistedPlay(); break; }

										// determine appropriate version of overloaded AssignActor() to call
										Play* p = SM.FindPlay(idP, playList);
										if(p->GetIsScheduled())
										{
											int hallNum = p->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.AssignActor(*a, *p, *h);
										}
										else { SM.AssignActor(*a, *p); } 
										break;
									}
									case 2: // selected Assign a Singer to Musical
									{
										// output info to User
										cout << "\nCurrently listed Singer IDs: { ";
										SM.PrintSingers(singerList); 
										cout << "}" << endl;
										cout << "Currently unassigned Singer IDs: { ";
										SM.PrintUnassignedSingers(singerList); 
										cout << "}" << endl;

										// get User Singer request
										cout << "Enter the ID number of the Singer to be assigned:" << endl;
										int idS = GetIDRequest();

										// break if user input is of invalid type
										if(idS == -1) { WarningInvalidInput(); break; }

										// break if Singer not listed on SystemManager
										if(!SM.VerifiedSingerID(idS, singerList)) { WarningUnlistedSinger(); break; }

										Singer* s = SM.FindSinger(idS, singerList);
										int inPerfID = s->GetInPerfID();	
										if(inPerfID != -1) // break if Singer is already assigned to a Musical
										{
											cout << "\nThe specified Singer is already assigned to Musical with performance ID " << inPerfID << "." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}

										// get User Musical request
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;
										cout << "Enter the performance ID of the Musical to be assigned to:" << endl;
										int idMu = GetIDRequest();

										// break if user input is of invalid type
										if(idMu == -1) { WarningInvalidInput(); break; }

										// break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idMu, musicalList)) { WarningUnlistedMusical(); break; }

										// determine appropriate version of overloaded AssignSinger() to call
										Musical* mu = SM.FindMusical(idMu, musicalList);
										if(mu->GetIsScheduled())
										{
											int hallNum = mu->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.AssignSinger(*s, *mu, *h);
										}
										else { SM.AssignSinger(*s, *mu); } 
										break;
									}
									case 3: // selected Assign a Musician to a Musical
									{
										// output info to User
										cout << "\nCurrently listed Musician IDs: { ";
										SM.PrintMusicians(musicianList); 
										cout << "}" << endl;
										cout << "Currently unassigned Musician IDs: { ";
										SM.PrintUnassignedMusicians(musicianList); 
										cout << "}" << endl;

										// get User Musician request
										cout << "Enter the ID number of the Musician to be assigned:" << endl;
										int idM = GetIDRequest();

										// break if user input is of invalid type
										if(idM == -1) { WarningInvalidInput(); break; }

										// break if Musician not listed on SystemManager
										if(!SM.VerifiedMusicianID(idM, musicianList)) { WarningUnlistedMusician(); break; }

										Musician* m = SM.FindMusician(idM, musicianList);
										int inPerfID = m->GetInPerfID();	
										if(inPerfID != -1) // break if Musician is already assigned to a Musical
										{
											cout << "\nThe specified Musician is already assigned to Musical with performance ID " << inPerfID << "." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}

										// get User Musical request
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;
										cout << "Enter the performance ID of the Musical to be assigned to:" << endl;
										int idMu = GetIDRequest();

										// break if user input is of invalid type
										if(idMu == -1) { WarningInvalidInput(); break; }

										// break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idMu, musicalList)) { WarningUnlistedMusical(); break; }

										// determine appropriate version of overloaded AssignMusician() to call
										Musical* mu = SM.FindMusical(idMu, musicalList);
										if(mu->GetIsScheduled())
										{
											int hallNum = mu->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.AssignMusician(*m, *mu, *h);
										}
										else { SM.AssignMusician(*m, *mu); } 
										break;
									}
									case 0:
									{
										reqAP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 2: // selected Unassign a Performer
						{
							int reqUP = -1;
							while(reqUP != 0)
							{
								reqUP = GetPerformerToUnassign(); // open Menu to Unassign a Performer (3+1 cases)
								switch(reqUP)
								{
									case 1: // selected Unassign an Actor from a Play
									{
										// output info to User
										cout << "\nCurrently listed Actor IDs: { ";
										SM.PrintActors(actorList); 
										cout << "}" << endl;
										cout << "Currently assigned Actor IDs: { ";
										SM.PrintAssignedActors(actorList); 
										cout << "}" << endl;

										// get User Actor request
										cout << "Enter the ID number of the Actor to be unassigned:" << endl;
										int idA = GetIDRequest();

										// break if user input is of invalid type
										if(idA == -1) { WarningInvalidInput(); break; }

										// break if Actor not listed on SystemManager
										if(!SM.VerifiedActorID(idA, actorList)) { WarningUnlistedActor(); break; }

										Actor* a = SM.FindActor(idA, actorList);
										int idP = a->GetInPerfID();	
										if(idP == -1) // break if Actor is not assigned to a Play
										{
											cout << "\nThe specified Actor is not currently assigned to a Play." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
													
										// determine appropriate version of overloaded UnassignActor() to call
										Play* p = SM.FindPlay(idP, playList);
										if(p->GetIsScheduled())
										{
											int hallNum = p->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.UnassignActor(*a, *p, *h);
										}
										else { SM.UnassignActor(*a, *p); } 
										break;
									}
									case 2: // selected Unassign a Singer from a Musical
									{
										// output info to User
										cout << "\nCurrently listed Singer IDs: { ";
										SM.PrintSingers(singerList); 
										cout << "}" << endl;
										cout << "Currently assigned Singer IDs: { ";
										SM.PrintAssignedSingers(singerList); 
										cout << "}" << endl;

										// get User Singer request
										cout << "Enter the ID number of the Singer to be unassigned:" << endl;
										int idS = GetIDRequest();

										// break if user input is of invalid type
										if(idS == -1) { WarningInvalidInput(); break; }

										// break if Singer not listed on SystemManager
										if(!SM.VerifiedSingerID(idS, singerList)) { WarningUnlistedSinger(); break; }

										Singer* s = SM.FindSinger(idS, singerList);
										int idMu = s->GetInPerfID();	
										if(idMu == -1) // break if Singer is not assigned to a Musical
										{
											cout << "\nThe specified Singer is not currently assigned to a Musical." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										
										// determine appropriate version of overloaded UnassignSinger() to call
										Musical* mu = SM.FindMusical(idMu, musicalList);
										if(mu->GetIsScheduled())
										{
											int hallNum = mu->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.UnassignSinger(*s, *mu, *h);
										}
										else { SM.UnassignSinger(*s, *mu); } 
										break;
									}
									case 3: // selected Unassign a Musician from a Musical
									{
										// output info to User
										cout << "\nCurrently listed Musician IDs: { ";
										SM.PrintMusicians(musicianList); 
										cout << "}" << endl;
										cout << "Currently assigned Musician IDs: { ";
										SM.PrintAssignedMusicians(musicianList); 
										cout << "}" << endl;

										// get User Musician request
										cout << "Enter the ID number of the Musician to be unassigned:" << endl;
										int idM = GetIDRequest();

										// break if user input is of invalid type
										if(idM == -1) { WarningInvalidInput(); break; }

										// break if Musician not listed on SystemManager
										if(!SM.VerifiedMusicianID(idM, musicianList)) { WarningUnlistedMusician(); break; }

										Musician* m = SM.FindMusician(idM, musicianList);
										int idMu = m->GetInPerfID();	
										if(idMu == -1) // break if Musician is not assigned to a Musical
										{
											cout << "\nThe specified Musician is not currently assigned to a Musical." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										
										// determine appropriate version of overloaded UnassignMusician() to call
										Musical* mu = SM.FindMusical(idMu, musicalList);
										if(mu->GetIsScheduled())
										{
											int hallNum = mu->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.UnassignMusician(*m, *mu, *h);
										}
										else { SM.UnassignMusician(*m, *mu); } 
										break;
									}
									case 0:
									{
										reqUP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;

						}
						case 3: // selected Schedule a Performance
						{
							int reqSP = -1;
							while(reqSP != 0)
							{
								reqSP = GetPerformanceToSchedule(); // open Menu to Schedule Performance (2+1 cases)
								switch(reqSP)
								{
									case 1: // selected Schedule a Play in a Performance Hall
									{
										// output info to User
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;
										cout << "Currently unscheduled Play performance IDs: { ";
										SM.PrintUnscheduledPlays(playList); 
										cout << "}" << endl;

										// get User Play request
										cout << "Enter the performance ID of the Play to be scheduled:" << endl;
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Play not listed on SystemManager
										if(!SM.VerifiedPlayID(idP, playList)) { WarningUnlistedPlay(); break; }

										Play* p = SM.FindPlay(idP, playList);
										int inHallNum = p->GetInHallNum();	
										if(inHallNum != -1) // break if Play is already scheduled
										{
											cout << "\nThe specified Play is already scheduled in Performance Hall number " << inHallNum << "." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}

										// output info to User
										cout << "\nCurrently listed Performance Hall numbers: { ";
										SM.PrintHalls(perfHallList); 
										cout << "}" << endl;
										cout << "Currently available Performance Hall numbers: { ";
										SM.PrintAvailableHalls(perfHallList); 
										cout << "}" << endl;

										// get User Hall request
										cout << "Enter the number of the Performance Hall to be booked:" << endl;
										int num = GetIDRequest();

										// break if user input is of invalid type
										if(num == -1) { WarningInvalidInput(); break; }

										// break if Performance Hall not listed on SystemManager
										if(!SM.VerifiedHallNum(num, perfHallList)) { WarningUnlistedHall(); break; }

										PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
										if(h->GetIsBooked()) // break if Performance Hall is already booked
										{
											int perfID = h->GetScheduledPerf().GetPerfID();
											cout << "\nThe specified Performance Hall is already booked with a Performance (ID " << perfID << ")." << endl;
											cout << "Check your input and try again." << endl;
											break;
										}
										if(h->GetCapacity() < p->GetTicketsSold()) // break if Performance Hall has insufficient capacity
										{
											cout << "\nThe specified Performance Hall is unable to accommodate this Play (max capacity: " << h->GetCapacity() << ")." << endl;
											cout << "Check your input and try again." << endl;
											break;
										}
										SM.SchedulePlay(*p, *h);
										break;
									}
									case 2: // selected Schedule a Musical in a Performance Hall
									{
										// output info to User
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;
										cout << "Currently unscheduled Musical performance IDs: { ";
										SM.PrintUnscheduledMusicals(musicalList); 
										cout << "}" << endl;

										// get User Musical request
										cout << "Enter the performance ID of the Musical to be scheduled:" << endl;
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idP, musicalList)) { WarningUnlistedMusical(); break; }

										Musical* mu = SM.FindMusical(idP, musicalList);
										int inHallNum = mu->GetInHallNum();	
										if(inHallNum != -1) // break if Musical is already scheduled
										{
											cout << "\nThe specified Musical is already scheduled in Performance Hall number " << inHallNum << "." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}

										// output info to User
										cout << "\nCurrently listed Performance Hall numbers: { ";
										SM.PrintHalls(perfHallList); 
										cout << "}" << endl;
										cout << "Currently available Performance Hall numbers: { ";
										SM.PrintAvailableHalls(perfHallList); 
										cout << "}" << endl;

										// get User Hall request
										cout << "Enter the number of the Performance Hall to be booked:" << endl;
										int num = GetIDRequest();

										// break if user input is of invalid type
										if(num == -1) { WarningInvalidInput(); break; }

										// break if Performance Hall not listed on SystemManager
										if(!SM.VerifiedHallNum(num, perfHallList)) { WarningUnlistedHall(); break; }

										PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
										if(h->GetIsBooked()) // break if Performance Hall is already booked
										{
											int perfID = h->GetScheduledPerf().GetPerfID();
											cout << "\nThe specified Performance Hall is already booked with a Performance (ID " << perfID << ")." << endl;
											cout << "Check your input and try again." << endl;
											break;
										}
										if(h->GetCapacity() < mu->GetTicketsSold()) // break if Performance Hall has insufficient capacity
										{
											cout << "\nThe specified Performance Hall is unable to accommodate this Musical (max capacity: " << h->GetCapacity() << ")." << endl;
											cout << "Check your input and try again." << endl;
											break;
										}
										SM.ScheduleMusical(*mu, *h);
										break;
									}
									case 0:
									{
										reqSP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 4: // selected Unschedule a Performance
						{
							int reqUP = -1;
							while(reqUP != 0)
							{
								reqUP = GetPerformanceToUnschedule(); // open Menu to Unschedule Performance (2+1 cases)
								switch(reqUP)
								{
									case 1: // selected Unschedule a Play
									{
										// output info to User
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;
										cout << "Currently scheduled Play performance IDs: { ";
										SM.PrintScheduledPlays(playList); 
										cout << "}" << endl;

										// get User Play request
										cout << "Enter the performance ID of the Play to be unassigned:" << endl;
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Play not listed on SystemManager
										if(!SM.VerifiedPlayID(idP, playList)) { WarningUnlistedPlay(); break; }

										Play* p = SM.FindPlay(idP, playList);
										int num = p->GetInHallNum();	
										if(num == -1) // break if Play is not already scheduled
										{
											cout << "\nThe specified Play is not currently scheduled in a Performance." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
										SM.UnschedulePlay(*p, *h);										
										break;
									}
									case 2: // selected Unschedule a Musical
									{
										// output info to User
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;
										cout << "Currently scheduled Musical performance IDs: { ";
										SM.PrintScheduledMusicals(musicalList); 
										cout << "}" << endl;

										// get User Musical request
										cout << "Enter the performance ID of the Musical to be unassigned:" << endl;
										int idP = GetIDRequest();

										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idP, musicalList)) { WarningUnlistedMusical(); break; }

										Musical* mu = SM.FindMusical(idP, musicalList);
										int num = mu->GetInHallNum();	
										if(num == -1) // break if Musical is not already scheduled
										{
											cout << "\nThe specified Musical is not currently scheduled in a Performance." << endl;
											cout << "Check your input and try again.\n" << endl;
											break;
										}
										PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
										SM.UnscheduleMusical(*mu, *h);										
										break;
									}
									case 0:
									{
										reqUP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 0:
						{
							req2 = 0;
							break;
						}
						default:
							WarningInvalidInput();								
					}
				}
				break;
			}


			case 3: // selected Menu3 : Utility
			{
				int req3 = -1;
				while(req3 != 0)
				{
					req3 = GetMenu3Request(); // open Menu3 (6+1 cases)
					switch(req3)
					{
						case 1: // selected Toggle Specify mode
						{
							SM.ToggleSpecifyMode(specifyMode);
							break;
						}
						case 2: // selected Check status of all listed Actors
						{
							SM.CheckActorsStatus(actorList);
							break;
						}
						case 3: // selected Check status of all listed Singers
						{
							SM.CheckSingersStatus(singerList);
							break;
						}
						case 4: // selected check status of all listed Musicians
						{
							SM.CheckMusiciansStatus(musicianList);
							break;
						}
						case 5: // selected check status of all listed Plays
						{
							SM.CheckPlaysStatus(playList);
							break;
						}
						case 6: // selected check status of all listed Musicals
						{
							SM.CheckMusicalsStatus(musicalList);
							break;
						}
						case 7: // selected check status of all listed Performance Halls
						{
							SM.CheckHallsStatus(perfHallList);
							break;
						}
						case 0:
						{
							req3 = 0;
							break;
						}
						default:
							WarningInvalidInput();
					}
				}
				break;
			}


			case 4: // selected Menu4 : Modify/Calculate
			{
				int req4 = -1;
				while(req4 != 0)
				{
					req4 = GetMenu4Request(); // open Menu4 (2+1 cases)
					switch(req4)
					{
						case 1: // selected Modify Performer salary
						{
							int reqMP = -1;
							while(reqMP != 0)
							{
								reqMP = GetPerformerSalaryToModify(); // open Menu to modify salary of a Performer (3+1 cases)
								switch(reqMP)
								{
									case 1: // selected Modify salary of a Actor
									{
										// output info to User
										cout << "\nCurrently listed Actor IDs: { ";
										SM.PrintActors(actorList); 
										cout << "}" << endl;

										// get User Actor request
										cout << "Enter the ID number of the Actor to be modified:" << endl;
										int idA = GetIDRequest();
										
										// break if user input is of invalid type
										if(idA == -1) { WarningInvalidInput(); break; }

										// break if Actor not listed on SystemManager
										if(!SM.VerifiedActorID(idA, actorList)) { WarningUnlistedActor(); break; }
										Actor* a = SM.FindActor(idA, actorList);
										cout << "\nThis Actor currently earns " << a->GetSalary() << " per day.";

										// get User salary request
										float newSalary = GetNewSalary();

										// break if user input is invalid
										if(newSalary == -1.0f) { WarningInvalidInput(); break; }
 
										// determine appropriate version of overloaded ModifyActorSalary() to call
										if(a->GetIsAssigned())
										{
											int perfID = a->GetInPerfID();
											Play* p = SM.FindPlay(perfID, playList);
											if(p->GetIsScheduled())
											{
												int hallNum = p->GetInHallNum();
												PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
												SM.ModifyActorSalary(*a, *p, *h, newSalary);
											}
											else{ SM.ModifyActorSalary(*a, *p, newSalary); }
										}
										else { SM.ModifyActorSalary(*a, newSalary); } 
										break;
									}
									case 2: // selected Modify salary of a Singer
									{
										// output info to User
										cout << "\nCurrently listed Singer IDs: { ";
										SM.PrintSingers(singerList); 
										cout << "}" << endl;

										// get User Singer request
										cout << "Enter the ID number of the Singer to be modified:" << endl;
										int idS = GetIDRequest();
										
										// break if user input is of invalid type
										if(idS == -1) { WarningInvalidInput(); break; }

										// break if Singer not listed on SystemManager
										if(!SM.VerifiedSingerID(idS, singerList)) { WarningUnlistedSinger(); break; }
										Singer* s = SM.FindSinger(idS, singerList);
										cout << "\nThis Singer currently earns " << s->GetSalary() << " per day.";

										// get User salary request
										float newSalary = GetNewSalary();

										// break if user input is invalid
										if(newSalary == -1.0f) { WarningInvalidInput(); break; }
 
										// determine appropriate version of overloaded ModifySingerSalary() to call
										if(s->GetIsAssigned())
										{
											int perfID = s->GetInPerfID();
											Musical* mu = SM.FindMusical(perfID, musicalList);
											if(mu->GetIsScheduled())
											{
												int hallNum = mu->GetInHallNum();
												PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
												SM.ModifySingerSalary(*s, *mu, *h, newSalary);
											}
											else{ SM.ModifySingerSalary(*s, *mu, newSalary); }
										}
										else { SM.ModifySingerSalary(*s, newSalary); } 
										break;
									}
									case 3: // selected Modify salary of a Musician
									{
										// output info to User
										cout << "\nCurrently listed Musician IDs: { ";
										SM.PrintMusicians(musicianList); 
										cout << "}" << endl;

										// get User Musician request
										cout << "Enter the ID number of the Musician to be modified:" << endl;
										int idM = GetIDRequest();
										
										// break if user input is of invalid type
										if(idM == -1) { WarningInvalidInput(); break; }

										// break if Musician not listed on SystemManager
										if(!SM.VerifiedMusicianID(idM, musicianList)) { WarningUnlistedMusician(); break; }
										Musician* m = SM.FindMusician(idM, musicianList);
										cout << "\nThis Musician currently earns " << m->GetSalary() << " per day.";

										// get User salary request
										float newSalary = GetNewSalary();

										// break if user input is invalid
										if(newSalary == -1.0f) { WarningInvalidInput(); break; }
 
										// determine appropriate version of overloaded ModifyMusicianSalary() to call
										if(m->GetIsAssigned())
										{
											int perfID = m->GetInPerfID();
											Musical* mu = SM.FindMusical(perfID, musicalList);
											if(mu->GetIsScheduled())
											{
												int hallNum = mu->GetInHallNum();
												PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
												SM.ModifyMusicianSalary(*m, *mu, *h, newSalary);
											}
											else{ SM.ModifyMusicianSalary(*m, *mu, newSalary); }
										}
										else { SM.ModifyMusicianSalary(*m, newSalary); } 
										break;
									}
									case 0:
									{
										reqMP = 0;
										break;
									}
									default:
										WarningInvalidInput();					
								}
							}
							break;
						}
						case 2: // selected Modify Performance ticket price
						{
							int reqMP = -1;
							while(reqMP != 0)
							{
								reqMP = GetPerformanceTicketPriceToModify(); // open Menu to Modify ticket price of a performance (2+1 cases)
								switch(reqMP)
								{
									case 1: // selected Modify ticket price of a Play
									{
										// output info to User
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;

										// get User Play request
										cout << "Enter the performance ID number of the Play to be modified:" << endl;
										int idP = GetIDRequest();
										
										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Play not listed on SystemManager
										if(!SM.VerifiedPlayID(idP, playList)) { WarningUnlistedPlay(); break; }
										Play* p = SM.FindPlay(idP, playList);
										cout << "\nThis Play currently generates " << p->GetTicketPrice() << " per ticket sold.";

										// get User price request
										float newPrice = GetNewPrice();

										// break if user input is invalid
										if(newPrice == -1.0f) { WarningInvalidInput(); break; }

										// determine appropriate version of overloaded ModifyPlayTicketPrice() to call
										if(p->GetIsScheduled())
										{
											int hallNum = p->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.ModifyPlayTicketPrice(*p, *h, newPrice);
										}
										else { SM.ModifyPlayTicketPrice(*p, newPrice); }
										break;
									}
									case 2: // selected modify ticket price of a Musical
									{
										// output info to User
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;

										// get User Musical request
										cout << "Enter the performance ID number of the Musical to be modified:" << endl;
										int idMu = GetIDRequest();
										
										// break if user input is of invalid type
										if(idMu == -1) { WarningInvalidInput(); break; }

										// break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idMu, musicalList)) {WarningUnlistedMusical(); break; }
										Musical* mu = SM.FindMusical(idMu, musicalList);
										cout << "\nThis Musical currently generates " << mu->GetTicketPrice() << " per ticket sold.";

										// get User price request
										float newPrice = GetNewPrice();

										// break if user input is invalid
										if(newPrice == -1.0f) { WarningInvalidInput(); break; }

										// determine appropriate version of overloaded ModifyMusicalTicketPrice() to call
										if(mu->GetIsScheduled())
										{
											int hallNum = mu->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											SM.ModifyMusicalTicketPrice(*mu, *h, newPrice);
										}
										else { SM.ModifyMusicalTicketPrice(*mu, newPrice); }
										break;
									}
									case 0:
									{
										reqMP = 0;
										break;
									}
									default:
										WarningInvalidInput();
								}
							}
							break;
						}
						case 3: // selected Modify Performance ticket sales
						{
							int reqMP = -1;
							while(reqMP != 0)
							{
								reqMP = GetPerformanceTicketSalesToModify(); // open Menu to Modify ticket sales of a performance (2+1 cases)
								switch(reqMP)
								{
									case 1: // selected Modify ticket sales of a Play
									{
										// output info to User
										cout << "\nCurrently listed Play performance IDs: { ";
										SM.PrintPlays(playList); 
										cout << "}" << endl;

										// get User Play request
										cout << "Enter the performance ID number of the Play to be modified:" << endl;
										int idP = GetIDRequest();
										
										// break if user input is of invalid type
										if(idP == -1) { WarningInvalidInput(); break; }

										// break if Play not listed on SystemManager
										if(!SM.VerifiedPlayID(idP, playList)) { WarningUnlistedPlay(); break; }
										Play* p = SM.FindPlay(idP, playList);
										cout << "\nThis Play has currently sold " << p->GetTicketsSold() << " tickets.";

										// get User sales request
										int newSales = GetNewSales();

										// break if user input is invalid
										if(newSales == -1) { WarningInvalidInput(); break; }

										// determine appropriate version of overloaded ModifyPlayTicketsSold() to call
										if(p->GetIsScheduled())
										{
											int hallNum = p->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											if(h->GetCapacity() < newSales)
											{
												cout << "\nThis Play is currently scheduled in a Performance Hall with an insufficient capacity." << endl;
												cout << "Unschedule the Play before modifying its ticket sales, or enter a number <= " << h->GetCapacity() << ".\n";
												break;
											}
											SM.ModifyPlayTicketsSold(*p, *h, newSales);
										}
										else { SM.ModifyPlayTicketsSold(*p, newSales); }
										break;
									}
									case 2: // selected modify ticket sales of a Musical
									{
										// output info to User
										cout << "\nCurrently listed Musical performance IDs: { ";
										SM.PrintMusicals(musicalList); 
										cout << "}" << endl;

										// get User Musical request
										cout << "Enter the performance ID number of the Musical to be modified:" << endl;
										int idM = GetIDRequest();
										
										// break if user input is of invalid type
										if(idM == -1) { WarningInvalidInput(); break; }

										// break if Musical not listed on SystemManager
										if(!SM.VerifiedMusicalID(idM, musicalList)) { WarningUnlistedMusical(); break; }
										Musical* mu = SM.FindMusical(idM, musicalList);
										cout << "\nThis Musical has currently sold " << mu->GetTicketsSold() << " tickets.";

										// get User sales request
										int newSales = GetNewSales();

										// break if user input is invalid
										if(newSales == -1) { WarningInvalidInput(); break; }

										// determine appropriate version of overloaded ModifyMusicalTicketsSold() to call
										if(mu->GetIsScheduled())
										{
											int hallNum = mu->GetInHallNum();
											PerformanceHall* h = SM.FindPerfHall(hallNum, perfHallList);
											if(h->GetCapacity() < newSales)
											{
												cout << "\nThis Musical is currently scheduled in a Performance Hall with an insufficient capacity." << endl;
												cout << "Unschedule the Musical before modifying its ticket sales, or enter a number <= " << h->GetCapacity() << ".\n";
												break;
											}
											SM.ModifyMusicalTicketsSold(*mu, *h, newSales);
										}
										else { SM.ModifyMusicalTicketsSold(*mu, newSales); }
										break;
									}
									case 0:
									{
										reqMP = 0;
										break;
									}
									default:
										WarningInvalidInput();
								}
							}
							break;
						}
						case 4: // selected Modify Performance Hall capacity
						{
							// output info to User
							cout << "\nCurrently listed Performance Hall numbers: { ";
							SM.PrintHalls(perfHallList); 
							cout << "}" << endl;

							// get User Hall request
							cout << "Enter the number of the Performance Hall to be modified:" << endl;
							int num = GetIDRequest();

							// break if user input is of invalid type
							if(num == -1) { WarningInvalidInput(); break; }

							// break if Performance Hall not listed on SystemManager
							if(!SM.VerifiedHallNum(num, perfHallList)) { WarningUnlistedHall(); break; }

							PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
							cout << "\nThis Performance Hall can currently hold " << h->GetCapacity() << " people.";

							// get User price request
							int newCapacity = GetNewCapacity();

							// break if user input is invalid
							if(newCapacity == -1) { WarningInvalidInput(); break; }

							// determine whether Hall capacity can be modified
							if(h->GetIsBooked())
							{
								Performance p = h->GetScheduledPerf();
								if(p.GetTicketsSold() > newCapacity)
								{
									cout << "\nThe Performance currently scheduled in this Hall has sold more tickets than there would be seats available." << endl;
									cout << "Unschedule the Performance before modifying the Hall capacity, or enter a number >= " << p.GetTicketsSold() << ".\n";
									break;
								}
								else{ SM.ModifyHallCapacity(*h, newCapacity); }
							}
							else { SM.ModifyHallCapacity(*h, newCapacity); }
							break;
						}
						case 5: // selected Calculate profit of a scheduled Performance
						{
							// output info to User
							cout << "\nCurrently listed Performance Hall numbers: { ";
							SM.PrintHalls(perfHallList); 
							cout << "}" << endl;
							cout << "Currently booked Performance Hall numbers: { ";
							SM.PrintBookedHalls(perfHallList); 
							cout << "}" << endl;

							// get User Hall request
							cout << "Enter the number of the Performance Hall to compute its expected profit:" << endl;
							int num = GetIDRequest();

							// break if user input is of invalid type
							if(num == -1) { WarningInvalidInput(); break; }

							// break if Performance Hall not listed on SystemManager
							if(!SM.VerifiedHallNum(num, perfHallList)) { WarningUnlistedHall(); break; }

							PerformanceHall* h = SM.FindPerfHall(num, perfHallList);
							if(!h->GetIsBooked()) // break if Performance Hall is not booked
							{
								cout << "\nThe specified Performance Hall is not currently booked with a Performance." << endl;
								cout << "Check your input and try again.\n" << endl;
								break;
							}
							SM.CalcPerfProfit(*h, true);
							break;
						}
						case 6: // selected Calculate profit of all scheduled Performances
						{
							cout << "View a per-performance breakdown? (y/n)" << endl;
							char response = 'z';
							cin >> response;
							switch(response)
							{
								case 'Y':
								case 'y':
								{
									SM.CalcTotalProfit(perfHallList, true); break;
								}
								case 'N':
								case 'n':
								{
									cout << "\nTotal profit of scheduled Performances: " << SM.CalcTotalProfit(perfHallList, false); break;
								}
								default:
									WarningInvalidInput();
							}
							break;
						}
						case 0:
						{
							req4 = 0;
							break;
						}
						default:
							WarningInvalidInput();
					}
				}
				break;
			}


			case 5: // requested Help
			{
				Help();
				break;	
			}


			case 0: // requested Exit program
			{
				Exiting();
				return 0;
			}

			default:
				WarningInvalidInput();
		}
	}



	return 0;
} // end main



// ------ DEFINITIONS ------
void Welcome()
{
	cout << "()()()()()()()()()()()()()()()()" << endl;
	cout << "() Welcome to THEATRE MANAGER ()" << endl;
	cout << "()()()()()()()()()()()()()()()()" << endl;
}
void Exiting()
{
	cout << "\n()()()()()()()()()()()()()()()" << endl;
	cout << "()    Exited the program    ()" << endl;
	cout << "()()()()()()()()()()()()()()()" << endl;
}

float GetMainMenuRequest()
{
	float req = -1;
	cout << "\nSelect a menu option:" << endl;
	cout << "-------------------------------" << endl;
	cout << "1 ....... Modify System Rosters" << endl;
	cout << "2 ....... Assignment/Scheduling" << endl;
	cout << "3 ....... Utility" << endl;
	cout << "4 ....... Modify/Calculate" << endl;
	cout << "5 ....... Help" << endl;
	cout << "0 ....... Exit the program" << endl;
	cout << "-------------------------------" << endl;
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

void Help()
{
	cout << "\nOption 1: Modify System Rosters" << endl;
	cout << "-------------------------------" << endl;
	cout << "Use this menu to add/remove Performers, Performances, and Performance Halls to/from the System lists.\n" << endl;
	cout << "Option 2: Assignment/Scheduling" << endl;
	cout << "-------------------------------" << endl;
	cout << "Use this menu to assign/unassign Performers to/from Performances, and to schedule/unschedule Performances.\n" << endl;
	cout << "Option 3: Utility" << endl;
	cout << "-----------------" << endl;
	cout << "Use this menu to check the status of all listed Performers, Performances, and Performance Halls.\n" << endl;
	cout << "When \'Specify mode\' is enabled from this menu, the following conditions apply:\n";
	cout << "- User must specify a daily salary when adding a Performer to the system (default 120.00)." << endl;
	cout << "- User must specify a ticket price when adding a Performance to the system (default 15.00)." << endl;
	cout << "- User must specify a capacity when adding a Performance Hall to the system (default 150).\n" << endl;
	cout << "Option 4: Modify/Calculate" << endl;
	cout << "--------------------------" << endl;
	cout << "Use this menu to modify Performer salaries, Performance ticket sales, and Hall capacities." << endl; 
	cout << "Use also to calculate expected profits from all scheduled Performances.\n" << endl;
}


// --- MENU1 ---
float GetMenu1Request()
{
	float req = -1;
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

float GetPerformerToAdd()
{
	float req = -1;
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

float GetPerformerToRm()
{
	float req = -1;
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

float GetPerformanceToAdd()
{
	float req = -1;
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

float GetPerformanceToRm()
{
	float req = -1;
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


// --- MENU2 ---
float GetMenu2Request()
{
	float req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "1 ....... Assign a Performer to a Performance" << endl;
	cout << "2 ....... Unassign a Performer" << endl;
	cout << "3 ....... Schedule a Performance in a Performance Hall" << endl;
	cout << "4 ....... Unschedule a Performance" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "------------------------------------------------------" << endl;
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

float GetPerformerToAssign()
{
	float req = -1;
	cout << "\nSelect a Performer to assign:" << endl;
	cout << "----------------------------------------" << endl;
	cout << "1 ....... Assign an Actor to a Play" << endl;
	cout << "2 ....... Assign a Singer to a Musical" << endl;
	cout << "3 ....... Assign a Musician to a Musical" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "----------------------------------------" << endl;
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

float GetPerformerToUnassign()
{
	float req = -1;
	cout << "\nSelect a Performer to unassign:" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1 ....... Unassign an Actor from a Play" << endl;
	cout << "2 ....... Unassign a Singer from a Musical" << endl;
	cout << "3 ....... Unassign a Musician from a Musical" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------------" << endl;
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

float GetPerformanceToSchedule()
{
	float req = -1;
	cout << "\nSelect a Performance to schedule:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "1 ....... Schedule a Play in a Performance Hall" << endl;
	cout << "2 ....... Schedule a Musical in a Performance Hall" << endl;
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

float GetPerformanceToUnschedule()
{
	float req = -1;
	cout << "\nSelect a Performance to unschedule:" << endl;
	cout << "-------------------------------------" << endl;
	cout << "1 ....... Unschedule a Play" << endl;
	cout << "2 ....... Unschedule a Musical" << endl;
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

// ------------


// --- MENU3 ---
float GetMenu3Request()
{
	float req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "1 ....... Toggle Specify mode" << endl;
	cout << "2 ....... Check status of all listed Actors" << endl;
	cout << "3 ....... Check status of all listed Singers" << endl;
	cout << "4 ....... Check status of all listed Musicians" << endl;
	cout << "5 ....... Check status of all listed Plays" << endl;
	cout << "6 ....... Check status of all listed Musicals" << endl;
	cout << "7 ....... Check status of all listed Performance Halls" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "------------------------------------------------------" << endl;
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


// --- MENU4 ---
float GetMenu4Request()
{
	float req = -1;
	cout << "\nSelect an operation:" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "1 ....... Modify the salary of a Performer" << endl;
	cout << "2 ....... Modify the ticket price of a Performance" << endl;
	cout << "3 ....... Modify the ticket sales of a Performance" << endl;
	cout << "4 ....... Modify the capacity of a Performance Hall" << endl;
	cout << "5 ....... Calculate profit of a scheduled Performance" << endl;
	cout << "6 ....... Calculate total profit of all scheduled Performances" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "--------------------------------------------------------------" << endl;
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

float GetPerformerSalaryToModify()
{
	float req = -1;
	cout << "\nSelect a Performer to modify their salary:" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "1 ....... Modify the salary of a listed Actor" << endl;
	cout << "2 ....... Modify the salary of a listed Singer" << endl;
	cout << "3 ....... Modify the salary of a listed Musician" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "------------------------------------------------" << endl;
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

float GetNewSalary()
{
	cout << "\nEnter the new daily salary for the Performer:" << endl;
	float newSalary = -1.0f;
	cout << "> ";
	cin >> newSalary;
	if(cin.fail() || newSalary<0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		newSalary = -1.0f;
		return newSalary;
	}
	return newSalary;
}

float GetPerformanceTicketPriceToModify()
{
	float req = -1;
	cout << "\nSelect a Performance to modify its ticket price:" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "1 ....... Modify the ticket price of a listed Play" << endl;
	cout << "2 ....... Modify the ticket price of a listed Musical" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "-----------------------------------------------------" << endl;
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

float GetNewPrice()
{
	cout << "\nEnter the new ticket price for the Performance:" << endl;
	float newPrice = -1.0f;
	cout << "> ";
	cin >> newPrice;
	if(cin.fail() || newPrice<0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		newPrice = -1.0f;
		return newPrice;
	}
	return newPrice;
}

float GetPerformanceTicketSalesToModify()
{
	float req = -1;
	cout << "\nSelect a Performance to modify its ticket sales:" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "1 ....... Modify the ticket sales of a listed Play" << endl;
	cout << "2 ....... Modify the ticket sales of a listed Musical" << endl;
	cout << "0 ....... Return to the previous menu" << endl;
	cout << "-----------------------------------------------------" << endl;
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

float GetNewSales()
{
	cout << "\nEnter the new number of tickets sold for the Performance:" << endl;
	float newSales = -1.0f;
	cout << "> ";
	cin >> newSales;
	if(cin.fail() || newSales<0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		newSales = -1.0f;
		return newSales;
	}
	return newSales;
}

float GetNewCapacity()
{
	cout << "\nEnter the new capacity for the Performance Hall:" << endl;
	float newCapacity = -1;
	cout << "> ";
	cin >> newCapacity;
	if(cin.fail() || newCapacity<0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		newCapacity = -1;
		return newCapacity;
	}
	return newCapacity;
}

// ------------


// --- MISC ---
float GetIDRequest()
{
	float req = -1;
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

// WARNINGS
void WarningInvalidInput() { cout << "\nInvalid input, please review the input options and try again." << endl; }

void WarningUnlistedActor() { cout << "\nThe specified Actor is not currently listed.\nCheck your input and try again.\n" << endl; }
void WarningUnlistedSinger() { cout << "\nThe specified Singer is not currently listed.\nCheck your input and try again.\n" << endl; }
void WarningUnlistedMusician() { cout << "\nThe specified Musician is not currently listed.\nCheck your input and try again.\n" << endl; }
void WarningUnlistedPlay() { cout << "\nThe specified Play is not currently listed.\nCheck your input and try again.\n" << endl; }
void WarningUnlistedMusical() { cout << "\nThe specified Musical is not currently listed.\nCheck your input and try again.\n" << endl; }
void WarningUnlistedHall() { cout << "\nThe specified Performance Hall is not currently listed.\nCheck your input and try again.\n" << endl; }