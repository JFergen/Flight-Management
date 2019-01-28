#include "Flights.h"
#include "Crews.h"
#include "Planes.h"
#include <fstream>

extern Planes planes;
extern Crews crew;


Flights::Flights()
{
	numFlights = 0;
	flightID = 1000;
	loadFlights();
}

Flights::~Flights()
{
	storeFlights();
}

void Flights::addFlight()
{
	string tailNum = planes.getPlane();
	int pilotID = crew.getAPilot();
	int coPilotID = crew.getACoPilot();
	int crewIDs[3];
	crewIDs[0] = crew.getCrew1();
	crewIDs[1] = crew.getCrew2();
	crewIDs[2] = crew.getCrew3();
	//int year;
	string sAP;
	string eAP;
	int numPassengers = 0;
	string fStatus;

	if (pilotID == -1)
	{
		cout << "No pilot avilable at this time." << endl << endl;
		return;
	}

	if (coPilotID == -1)
	{
		cout << "No copilot avilable at this time." << endl << endl;
		crew.fixPilot(pilotID);
		return;
	}

	if (crewIDs[0] == -1)
	{
		cout << "Not enough cabin members avilable at this time." << endl << endl;
		crew.fixPilot(pilotID);
		crew.fixCoPilot(coPilotID);
		return;
	}

	if (crewIDs[1] == -1)
	{
		cout << "Not enough cabin members avilable at this time." << endl << endl;
		crew.fixPilot(pilotID);
		crew.fixCoPilot(coPilotID);
		crew.fixCrew1(crewIDs[0]);
		return;
	}

	if (crewIDs[2] == -1)
	{
		cout << "Not enough cabin members avilable at this time." << endl << endl;
		crew.fixPilot(pilotID);
		crew.fixCoPilot(coPilotID);
		crew.fixCrew1(crewIDs[0]);
		crew.fixCrew2(crewIDs[1]);
		return;
	}

	if (tailNum == "none")
	{
		cout << "No planes avilable at this time." << endl << endl;
		planes.fixPlane(tailNum);
		crew.fixPilot(pilotID);
		crew.fixCoPilot(coPilotID);
		crew.fixCrew1(crewIDs[0]);
		crew.fixCrew1(crewIDs[1]);
		crew.fixCrew3(crewIDs[2]);
		return;
	}

	/*cout << "Enter the year of the flight (1 - 12):";
	cin >> year;
	year = year - 1; NOT SURE HOW TO GET TIME WORKING */

	cout << "Enter the starting airport (3 letter code):";
	cin >> sAP;
	cin.ignore();

	cout << "Enter the ending airport (3 letter code):";
	cin >> eAP;
	cin.ignore();

	cout << "Enter number of passengers for flight:";
	cin >> numPassengers;
	cin.ignore();

	while (numPassengers > planes.getSeat(tailNum))
	{
		cout << "Number of passengers (" << numPassengers << ") exceeds number of seats (" << planes.getSeat(tailNum) << ")" << endl;
		cout << "Enter new number of passengers:";
		cin >> numPassengers;
		cin.ignore();
	}

	cout << "Enter status of flight (active, canceled, completed):";
	cin >> fStatus;

	Flight tmpFlight(flightID, tailNum, pilotID, coPilotID, crewIDs[0], crewIDs[1], crewIDs[2], -1, -1, sAP, eAP, numPassengers);

	tmpFlight.SetStatus(fStatus);

	flightList.push_back(tmpFlight);
	flightID = flightID + 5;
	numFlights++;

	cout << "Flight added" << endl;
}

void Flights::editFlight()
{
	int fID;
	string newTN;
	int newPID;
	int whichCabin = -1;
	string newSA;
	int newPassengers = -1;
	string newStatus;
	int choice = 0;

	cout << "Enter ID of flight to edit:";
	cin >> fID;
	cin.ignore();
	
	if (searchFlight(fID) != -1)
	{
		int index = searchFlight(fID);
		cout << "Flight found" << endl << endl;

		cout << "Choose what you would like to edit:" << endl;
		cout << "1 - Tail number" << endl;
		cout << "2 - Pilot ID" << endl;
		cout << "3 - CoPilot ID" << endl;
		cout << "4 - Cabin member ID" << endl;
		cout << "5 - Start time" << endl;
		cout << "6 - End time" << endl;
		cout << "7 - Starting airport" << endl;
		cout << "8 - Ending airport" << endl;
		cout << "9 - Number of passengers" << endl;
		cout << "10 - Status of flight" << endl;

		cout << "Enter choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter new Tail number:";
			cin >> newTN;
			cin.ignore();

			if (planes.searchPlane(newTN) == -1)
			{
				cout << "Plane does not exist." << endl;
				break;
			}

			flightList[index].SetPlaneID(newTN);
			cout << "Plane tail number has been updated" << endl;
			break;

		case 2:
			cout << "Enter new pilot ID";
			cin >> newPID;

			if (crew.searchCrew(newPID) == -1)
			{
				cout << "Pilot does not exist." << endl;
				break;
			}

			if (crew.getCrewStatus(newPID) != "pilot")
			{
				cout << "Not a pilot." << endl;
				break;
			}

			flightList[index].SetPilotID(newPID);
			cout << "Pilot ID has been updated" << endl;
			break;

		case 3:
			cout << "Enter new copilot ID";
			cin >> newPID;

			if (crew.searchCrew(newPID) == -1)
			{
				cout << "coPilot does not exist." << endl;
				break;
			}

			if (crew.getCrewStatus(newPID) != "copilot")
			{
				cout << "Not a copilot." << endl;
				break;
			}

			flightList[index].SetCoPilotID(newPID);
			cout << "coPilot ID has been updated" << endl;
			break;

		case 4:
			cout << "Which cabin member to change (1, 2, 3):";
			cin >> whichCabin;

			cout << "Enter new cabin member ID";
			cin >> newPID;

			if (crew.searchCrew(newPID) == -1)
			{
				cout << "cabin member does not exist." << endl;
				break;
			}

			if (crew.getCrewStatus(newPID) != "cabin")
			{
				cout << "Not a cabin member." << endl;
				break;
			}

			switch (whichCabin)
			{
			case 1:
				flightList[index].SetCrew1ID(newPID);
				break;
			case 2:
				flightList[index].SetCrew2ID(newPID);
				break;
			case 3:
				flightList[index].SetCrew3ID(newPID);
				break;
			default:
				cout << "Not a valid cabin member to edit. Try again (1, 2, 3):";
				cin >> whichCabin;
			}

			cout << "coPilot ID has been updated." << endl;
			break;

		case 5:
			// New start time
			break;

		case 6:
			// New end time
			break;

		case 7:
			cout << "Enter new starting airport 3 letter code:";
			cin >> newSA;
			cin.ignore();

			flightList[index].SetStartPort(newSA);
			cout << "Starting airport has been updated." << endl;
			break;

		case 8:
			cout << "Enter new ending airport 3 letter code:";
			cin >> newSA;
			cin.ignore();

			flightList[index].SetStartPort(newSA);
			cout << "Ending airport has been updated." << endl;
			break;

		case 9:
			cout << "Enter new number of passengers:" << endl;
			cin >> newPassengers;

			while (newPassengers > planes.getSeat(flightList[index].GetPlaneID()))
			{
				cout << "Number of passengers (" << newPassengers << ") exceeds number of seats (" << planes.getSeat(flightList[index].GetPlaneID()) << ")" << endl;
				cout << "Enter new number of passengers:";
				cin >> newPassengers;
				cin.ignore();
			}

			flightList[index].SetNumPassengers(newPassengers);
			cout << "Number of passengers has been updated." << endl;
			break;

		case 10:
			cout << "Enter new status of flight (active, cancelled, completed):";
			cin >> newStatus;
			cin.ignore();

			flightList[index].SetStatus(newStatus);
			cout << "Status has been updated" << endl;
			break;

		default:
			cout << "Not a valid option. Try again." << endl;
			cout << "Enter choice:";
			cin >> choice;
			break;
		}
	}
	else
	{
		cout << "Flight can not be found" << endl;
		return;
	}
}

int Flights::searchFlight(int fID)
{
	int index = 0;

	for (index; index < numFlights; index++)
	{
		if (flightList[index].GetFlightID() == fID)
		{
			return index;
		}
	}

	if (index == numFlights)
	{
		return -1;
	}

	return -1;
}

void Flights::deleteFlight()
{
	int fID;

	cout << "Enter ID of flight to delete:";
	cin >> fID;

	if (searchFlight(fID) != -1)
	{
		cout << "Flight found" << endl;
		int index = searchFlight(fID);

		flightList.erase(flightList.begin() + index);
		numFlights--;
		cout << "Flight has been deleted from list" << endl;
		return;
	}
	else
	{
		cout << "Flight can not be found" << endl;
		return;
	}
}

void Flights::printFlights()
{
	for (int i = 0; i < numFlights; i++)
	{
		cout << "Flight #" << i + 1 << endl;
		cout << "Flight ID: " << flightList[i].GetFlightID() << endl;
		cout << "Plane ID: " << flightList[i].GetPlaneID() << endl;
		cout << "Pilot ID: " << flightList[i].GetPilotID() << endl;
		cout << "CoPilot ID: " << flightList[i].GetCoPilotID() << endl;
		cout << "Cabin 1 ID: " << flightList[i].GetCrew1ID() << endl;
		cout << "Cabin 2 ID: " << flightList[i].GetCrew2ID() << endl;
		cout << "Cabin 3 ID: " << flightList[i].GetCrew3ID() << endl;
		cout << "Start time: " << flightList[i].GetStartTime() << endl;
		cout << "End time: " << flightList[i].GetEndTime() << endl;
		cout << "Starting Airport: " << flightList[i].GetStartPort() << endl;
		cout << "Ending Airport: " << flightList[i].GetEndPort() << endl;
		cout << "Number of passengers: " << flightList[i].GetNumPassengers() << endl;
		cout << "Status: " << flightList[i].GetStatus() << endl << endl;
	}
}

void Flights::printFlightByID()
{
	int fID;

	cout << "Enter flight ID:";
	cin >> fID;

	if (searchFlight(fID) != -1)
	{
		int index = searchFlight(fID);

		cout << "Flight found. Printing information:" << endl << endl;
		cout << "Flight ID: " << flightList[index].GetFlightID() << endl;
		cout << "Plane ID: " << flightList[index].GetPlaneID() << endl;
		cout << "Pilot ID: " << flightList[index].GetPilotID() << endl;
		cout << "CoPilot ID: " << flightList[index].GetCoPilotID() << endl;
		cout << "Cabin 1 ID: " << flightList[index].GetCrew1ID() << endl;
		cout << "Cabin 2 ID: " << flightList[index].GetCrew2ID() << endl;
		cout << "Cabin 3 ID: " << flightList[index].GetCrew3ID() << endl;
		cout << "Start time: " << flightList[index].GetStartTime() << endl;
		cout << "End time: " << flightList[index].GetEndTime() << endl;
		cout << "Starting Airport: " << flightList[index].GetStartPort() << endl;
		cout << "Ending Airport: " << flightList[index].GetEndPort() << endl;
		cout << "Number of passengers: " << flightList[index].GetNumPassengers() << endl;
		cout << "Status: " << flightList[index].GetStatus() << endl << endl;
		return;
	}
	else
	{
		cout << "Flight can not be found." << endl;
		return;
	}
}

void Flights::storeFlights()
{
ofstream fout;
fout.open("flights.dat");

fout << numFlights << endl;

for (int i = 0; i < numFlights; i++)
{
	fout << flightList[i].GetFlightID() << " " << flightList[i].GetPlaneID() << " " << flightList[i].GetPilotID() << " " << flightList[i].GetCoPilotID() << " " << flightList[i].GetCrew1ID() << " " << flightList[i].GetCrew2ID();
	fout << " " << flightList[i].GetCrew3ID() << " " << flightList[i].GetStartTime() << " " << flightList[i].GetEndTime() << " " << flightList[i].GetStartPort() << " " << flightList[i].GetEndPort();
	fout << " " << flightList[i].GetNumPassengers() << " " << flightList[i].GetStatus() << endl;
}

fout.close();
}

void Flights::loadFlights()
{
	ifstream fin;

	int fID;
	string plID;
	int pID;
	int cpID;
	int c1ID;
	int c2ID;
	int c3ID;
	int sTime;
	int eTime;
	string sPort;
	string ePort;
	int nPeople;
	string fStatus;

	fin.open("flights.dat");

	fin >> numFlights;
	fin.ignore();

	for (int i = 0; i < numFlights; i++)
	{
		fin >> fID >> plID >> pID >> cpID >> c1ID >> c2ID >> c3ID >> sTime >> eTime >> sPort >> ePort >> nPeople >> fStatus;

		Flight tmp(fID, plID, pID, cpID, c1ID, c2ID, c3ID, sTime, eTime, sPort, ePort, nPeople);
		tmp.SetStatus(fStatus);

		flightList.push_back(tmp);
	}

	fin.close();
}

void Flights::printSomeFlights()
{
	int choice1 = -1;
	string tailNum;
	int cID;
	string fStatus;

	do
	{
		cout << "Choose whether to print by:" << endl;
		cout << "1 - RETURN TO FLIGHT MENU" << endl;
		cout << "2 - By Plane" << endl;
		cout << "3 - By Crew Member" << endl;
		cout << "4 - By Status" << endl;

		cin >> choice1;
		cin.ignore();

		switch (choice1)
		{
		case 2:
			cout << "Enter the tail number of the plane:";
			cin >> tailNum;
			cin.ignore();

			for (int i = 0; i < numFlights; i++)
			{
				if (flightList[i].GetPlaneID() == tailNum)
				{
					cout << "Flight found. Printing information:" << endl << endl;
					cout << "Flight ID: " << flightList[i].GetFlightID() << endl;
					cout << "Plane ID: " << flightList[i].GetPlaneID() << endl;
					cout << "Pilot ID: " << flightList[i].GetPilotID() << endl;
					cout << "CoPilot ID: " << flightList[i].GetCoPilotID() << endl;
					cout << "Cabin 1 ID: " << flightList[i].GetCrew1ID() << endl;
					cout << "Cabin 2 ID: " << flightList[i].GetCrew2ID() << endl;
					cout << "Cabin 3 ID: " << flightList[i].GetCrew3ID() << endl;
					cout << "Start time: " << flightList[i].GetStartTime() << endl;
					cout << "End time: " << flightList[i].GetEndTime() << endl;
					cout << "Starting Airport: " << flightList[i].GetStartPort() << endl;
					cout << "Ending Airport: " << flightList[i].GetEndPort() << endl;
					cout << "Number of passengers: " << flightList[i].GetNumPassengers() << endl;
					cout << "Status: " << flightList[i].GetStatus() << endl << endl;
				}
			}
			break;
		case 3:
			cout << "Enter the ID of the crew member to search by:";
			cin >> cID;

			for (int i = 0; i < numFlights; i++)
			{
				if ((flightList[i].GetPilotID() == cID) || (flightList[i].GetCoPilotID() == cID) || (flightList[i].GetCrew1ID() == cID) || (flightList[i].GetCrew2ID() == cID) || (flightList[i].GetCrew3ID() == cID))
				{
					cout << "Flight found. Printing information:" << endl << endl;
					cout << "Flight ID: " << flightList[i].GetFlightID() << endl;
					cout << "Plane ID: " << flightList[i].GetPlaneID() << endl;
					cout << "Pilot ID: " << flightList[i].GetPilotID() << endl;
					cout << "CoPilot ID: " << flightList[i].GetCoPilotID() << endl;
					cout << "Cabin 1 ID: " << flightList[i].GetCrew1ID() << endl;
					cout << "Cabin 2 ID: " << flightList[i].GetCrew2ID() << endl;
					cout << "Cabin 3 ID: " << flightList[i].GetCrew3ID() << endl;
					cout << "Start time: " << flightList[i].GetStartTime() << endl;
					cout << "End time: " << flightList[i].GetEndTime() << endl;
					cout << "Starting Airport: " << flightList[i].GetStartPort() << endl;
					cout << "Ending Airport: " << flightList[i].GetEndPort() << endl;
					cout << "Number of passengers: " << flightList[i].GetNumPassengers() << endl;
					cout << "Status: " << flightList[i].GetStatus() << endl << endl;
				}
			}
			break;
		case 4:
			cout << "Enter the status to search for (active, canceled, completed):";
			cin >> fStatus;
			cin.ignore();

			for (int i = 0; i < numFlights; i++)
			{
				if ((flightList[i].GetStatus() == fStatus))
				{
					cout << "Flight found. Printing information:" << endl << endl;
					cout << "Flight ID: " << flightList[i].GetFlightID() << endl;
					cout << "Plane ID: " << flightList[i].GetPlaneID() << endl;
					cout << "Pilot ID: " << flightList[i].GetPilotID() << endl;
					cout << "CoPilot ID: " << flightList[i].GetCoPilotID() << endl;
					cout << "Cabin 1 ID: " << flightList[i].GetCrew1ID() << endl;
					cout << "Cabin 2 ID: " << flightList[i].GetCrew2ID() << endl;
					cout << "Cabin 3 ID: " << flightList[i].GetCrew3ID() << endl;
					cout << "Start time: " << flightList[i].GetStartTime() << endl;
					cout << "End time: " << flightList[i].GetEndTime() << endl;
					cout << "Starting Airport: " << flightList[i].GetStartPort() << endl;
					cout << "Ending Airport: " << flightList[i].GetEndPort() << endl;
					cout << "Number of passengers: " << flightList[i].GetNumPassengers() << endl;
					cout << "Status: " << flightList[i].GetStatus() << endl << endl;
				}
			}
			break;
		}
	} while (choice1 != 1);

	return;
}

void Flights::deleteFinishedFlights()
{
	for (int i = 0; i < numFlights; i++)
	{
		if (flightList[i].GetStatus() != "active")
		{
			flightList.erase(flightList.begin() + i);
			numFlights--;
		}
	}
}
