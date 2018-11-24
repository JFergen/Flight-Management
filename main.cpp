#include "Planes.h"
#include "Crews.h"
#include "Flights.h"

Planes planes;
Crews crew;
Flights flights;

int main()
{
	// Initial output (course stuff)
	cout << "+----------------------------------------------+" << endl;
	cout << "|       Computer Science and Engineering       |" << endl;
	cout << "|        CSCE 1040.003 - Computer Science II   |" << endl;
	cout << "| 	  	   Homework 4                  |" << endl;
	cout << "|       Joseph Fergen josephfergen@my.unt.edu  |" << endl;
	cout << "+----------------------------------------------+" << endl << endl << endl;

	int choice = -1; // User's choice


	do
	{
		cout << "MAIN MENU OPTIONS:" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - PLANES MENU" << endl;
		cout << "2 - CREW MENU" << endl;
		cout << "3 - FLIGHT MENU" << endl;
		
		cout << "Enter choice:";
		cin >> choice;

		switch (choice)
		{
			case 1: 
				do
				{
					cout << endl << "PLANE MENU OPTIONS:" << endl;
					cout << "1 - Return to MAIN MENU" << endl;
					cout << "2 - Add New Plane" << endl;
					cout << "3 - Edit Plane" << endl;
					cout << "4 - Delete Plane" << endl;
					cout << "5 - Print Planes" << endl;
					cout << "6 - Print Plane by Tail Number" << endl;
					cout << "7 - Load Planes (Also done automatically at start)" << endl;
					cout << "8 - Store Planes (Also done automatically at end)" << endl;

					cout << "Enter choice:";
					cin >> choice;
					cin.ignore();

					cout << endl;

					switch (choice)
					{
					case 2: 
						cout << "ADDING NEW PLANE" << endl;
						planes.addPlane();
						cout << "Plane added" << endl;
						break;
					case 3:
						cout << "EDITING PLANE" << endl;
						planes.editPlane();
						break;
					case 4:
						cout << "DELETING PLANE" << endl;
						planes.deletePlane();
						break;
					case 5:
						cout << "PRINTING PLANES" << endl;
						planes.printPlanes();
						cout << "Finished printing" << endl << endl;
						break;
					case 6:
						cout << "PRINTING PLANE BY ID" << endl;
						planes.printPlaneByID();
						break;
					case 7:
						cout << "LOADING PLANES" << endl;
						planes.loadPlanes();
						cout << "Finished loading planes" << endl << endl;
						break;
					case 8:
						cout << "STORING PLANES" << endl;
						planes.storePlanes();
						cout << "Finished storing planes" << endl << endl;
						break;
					}
				} while (choice != 1);
				break;
			case 2:
				do
				{
					cout << endl << "CREW MENU OPTIONS:" << endl;
					cout << "1 - Return to MAIN MENU" << endl;
					cout << "2 - Add New Crew Member" << endl;
					cout << "3 - Edit Crew Member" << endl;
					cout << "4 - Delete Crew Member" << endl;
					cout << "5 - Print Crew" << endl;
					cout << "6 - Print Crew Member by ID" << endl;
					cout << "7 - Load Crew (Also done automatically at start)" << endl;
					cout << "8 - Store Crew (Also done automatically at end)" << endl;

					cout << "Enter choice:";
					cin >> choice;
					cin.ignore();

					cout << endl;

					switch (choice)
					{
					case 2:
						cout << "ADDING NEW CREW MEMBER" << endl;
						crew.addCrew();
						cout << "Crew member added" << endl;
						break;
					case 3:
						cout << "EDITING CREW MEMBER" << endl;
						crew.editCrew();
						break;
					case 4:
						cout << "DELETING CREW MEMBER" << endl;
						crew.deleteCrew();
						break;
					case 5:
						cout << "PRINTING CREW MEMBERS" << endl;
						crew.printCrew();
						cout << "Finished printing" << endl << endl;
						break;
					case 6:
						cout << "PRINTING CREW MEMBER BY ID" << endl;
						crew.printCrewByID();
						break;
					case 7:
						cout << "LOADING CREW MEMBERS" << endl;
						crew.loadCrew();
						cout << "Finished loading crew members" << endl << endl;
						break;
					case 8:
						cout << "STORING CREW MEMBERS" << endl;
						crew.storeCrew();
						cout << "Finished storing crew members" << endl << endl;
						break;
					}
				} while (choice != 1);
				break;
			case 3:
				do
				{
					cout << endl << "FLIGHT MENU OPTIONS:" << endl;
					cout << "1 - Return to MAIN MENU" << endl;
					cout << "2 - Add New Flight" << endl;
					cout << "3 - Edit Flight" << endl;
					cout << "4 - Delete Flight" << endl;
					cout << "5 - Print Flights" << endl;
					cout << "6 - Print Flight by ID" << endl;
					cout << "7 - Load Flights (Also done automatically at start)" << endl;
					cout << "8 - Store Flights (Also done automatically at end)" << endl;
					cout << "9 - Search Flights specifically by plane, crew member, or status" << endl;

					cout << "Enter choice:";
					cin >> choice;
					cin.ignore();

					cout << endl;

					switch (choice)
					{
					case 2:
						cout << "ADDING NEW FLIGHT" << endl;
						flights.addFlight();
						break;
					case 3:
						cout << "EDITING FLIGHT" << endl;
						//flights.editFlight();
						break;
					case 4:
						cout << "DELETING FLIGHT" << endl;
						flights.deleteFlight();
						break;
					case 5:
						cout << "PRINTING FLIGHTS" << endl;
						flights.printFlights();
						cout << "Finished printing" << endl << endl;
						break;
					case 6:
						cout << "PRINTING FLIGHT BY ID" << endl;
						flights.printFlightByID();
						break;
					case 7:
						cout << "LOADING FLIGHTS" << endl;
						flights.loadFlights();
						cout << "Finished loading flights" << endl << endl;
						break;
					case 8:
						cout << "STORING FLIGHTS" << endl;
						flights.storeFlights();
						cout << "Finished storing flights" << endl << endl;
						break;
					case 9:
						cout << "SEARCHING SPECIFIC FLIGHTS" << endl;
						flights.printSomeFlights();
						break;
					}
				} while (choice != 1);
				break;
		}
	} while (choice != 0);

	return 0;
}
