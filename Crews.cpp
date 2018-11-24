#include "Crews.h"
#include <fstream>

Crews::Crews()
{
	numCrew = 0;
	loadCrew();
}

Crews::~Crews()
{
	storeCrew();
}

void Crews::addCrew()
{
	string cName;
	int cID;
	string cJob;
	string cStat;

	cout << "Enter crew member name:";
	getline(cin, cName);

	cout << "Enter crew member ID:";
	cin >> cID;
	cin.ignore();

	cout << "Enter crew member job (pilot, copilot, cabin):";
	cin >> cJob;
	cin.ignore();

	cout << "Enter status of crew member (available, leave, sick):";
	cin >> cStat;

	Crew tmpCrew(cName, cID);

	tmpCrew.SetJob(cJob);
	tmpCrew.SetStatus(cStat);

	crewList.push_back(tmpCrew);
	numCrew++;
}

void Crews::editCrew()
{
	int cID;
	string newName;
	string newJob;
	string newStatus;
	int choice = 0;

	cout << "Enter ID of crew member to edit:";
	cin >> cID;
	cin.ignore();

	if (searchCrew(cID) != -1)
	{
		int index = searchCrew(cID);
		cout << "Crew member found" << endl << endl;

		cout << "Choose what you would like to edit:" << endl;
		cout << "1 - Name" << endl;
		cout << "2 - Job" << endl;
		cout << "3 - Status" << endl;

		cout << "Enter choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter new name:";
			getline(cin, newName);
			crewList[index].SetName(newName);
			cout << "Name has been updated" << endl;
			break;
		case 2:
			cout << "Enter new job (pilot, copilot, cabin):";
			cin >> newJob;
			crewList[index].SetJob(newJob);
			cout << "Job has been updated" << endl;
			break;
		case 3:
			cout << "Enter new status of crew member (available, leave, sick):";
			cin >> newStatus;
			crewList[index].SetStatus(newStatus);
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
		cout << "Crew member can not be found" << endl;
		return;
	}
}

int Crews::searchCrew(int i)
{
	int index = 0;

	for (index; index < numCrew; index++)
	{
		if (crewList[index].GetID() == i)
		{
			return index;
		}
	}

	if (index == numCrew)
	{
		return -1;
	}

	return -1;
}

void Crews::deleteCrew()
{
	int cID;

	cout << "Enter ID of crew member to delete:";
	cin >> cID;

	if (searchCrew(cID) != -1)
	{
		cout << "Crew member found" << endl;
		int index = searchCrew(cID);

		crewList.erase(crewList.begin() + index);
		numCrew--;
		cout << "Crew member has been deleted from list" << endl;
		return;
	}
	else
	{
		cout << "Crew member can not be found" << endl;
		return;
	}
}

void Crews::printCrew()
{
	for (int i = 0; i < numCrew; i++)
	{
		cout << "Crew member #" << i + 1 << endl;
		cout << "Name: " << crewList[i].GetName() << endl;
		cout << "ID: " << crewList[i].GetID() << endl;
		cout << "Job: " << crewList[i].GetJob() << endl;
		cout << "Status: " << crewList[i].GetStatus() << endl << endl;
	}
}

void Crews::printCrewByID()
{
	int cID;

	cout << "Enter crew member ID:";
	cin >> cID;

	if (searchCrew(cID) != -1)
	{
		int index = searchCrew(cID);

		cout << "Crew member found. Printing information:" << endl << endl;
		cout << "Name: " << crewList[index].GetName() << endl;
		cout << "ID: " << crewList[index].GetID() << endl;
		cout << "Job: " << crewList[index].GetJob() << endl;
		cout << "Status: " << crewList[index].GetStatus() << endl << endl;
		return;
	}
	else
	{
		cout << "Crew member can not be found." << endl;
		return;
	}
}

void Crews::storeCrew()
{
	ofstream fout;
	fout.open("crews.dat");

	fout << numCrew << endl;

	for (int i = 0; i < numCrew; i++)
	{
		fout << crewList[i].GetName() << endl;
		fout << crewList[i].GetID() << " " << crewList[i].GetJob() << " " << crewList[i].GetStatus() << endl;
	}

	fout.close();
}

void Crews::loadCrew()
{
	ifstream fin;

	string name;
	int ID;
	string j;
	string pStatus;

	fin.open("crews.dat");

	fin >> numCrew;
	fin.ignore();

	for (int i = 0; i < numCrew; i++)
	{
		getline(fin, name);
		fin >> ID >> j >> pStatus;
		fin.ignore();

		Crew tmp(name, ID);
		tmp.SetJob(j);
		tmp.SetStatus(pStatus);
		
		crewList.push_back(tmp);
	}

	fin.close();
}

int Crews::getAPilot()
{
	for (int i = 0; i < numCrew; i++)
	{
		if ((crewList[i].GetJob() == "pilot") && (crewList[i].GetStatus() == "available"))
		{
			crewList[i].SetStatus("leave");
			return crewList[i].GetID();
		}

		if (i == numCrew)
		{
			return -1;
		}
	}

	return -1;
}

int Crews::getACoPilot()
{
	for (int i = 0; i < numCrew; i++)
	{
		if ((crewList[i].GetJob() == "copilot") && (crewList[i].GetStatus() == "available"))
		{
			crewList[i].SetStatus("leave");
			return crewList[i].GetID();
		}

		if (i == numCrew)
		{
			cout << "No copilots available at this time." << endl << endl;

			return -1;
		}
	}

	return -1;
}

/*int* Crews::getACrew()
{
	int numCabin = 0;
	int crew1;
	int crew2;
	int crew3;
	int threeCrew[3];
	int *exitValue;
	int exitV = -1;
	exitValue = &exitV;

	for (int i = 0; i < numCrew; i++)
	{
		if ((crewList[i].GetJob() == "cabin") && (crewList[i].GetStatus() == "available"))
		{
			crewList[i].SetStatus("leave");
			if (numCabin == 2)
			{
				crew3 = crewList[i].GetID();
				numCabin++;
			}
			else if (numCabin == 1)
			{
				crew2 = crewList[i].GetID();
				numCabin++;
			}
			else if (numCabin == 0)
			{
				crew1 = crewList[i].GetID();
				numCabin++;
			}

			if (numCabin == 3)
			{
				threeCrew[0] = crew1;
				threeCrew[1] = crew2;
				threeCrew[2] = crew3;
				return threeCrew;
			}
		}
	}

	switch (numCabin)
	{
	case 1:
		crewList[searchCrew(crew1)].SetStatus("available");
		break;
	case 2:
		crewList[searchCrew(crew1)].SetStatus("available");
		crewList[searchCrew(crew2)].SetStatus("available");
		break;
	case 3:
		crewList[searchCrew(crew1)].SetStatus("available");
		crewList[searchCrew(crew2)].SetStatus("available");
		crewList[searchCrew(crew3)].SetStatus("available");
		break;
	}
	
	return exitValue;
}*/

void Crews::fixPilot(int ID)
{
	int index;

	index = searchCrew(ID);

	crewList[index].SetStatus("available");
	
	return;
}

void Crews::fixCoPilot(int ID)
{
	int index;

	index = searchCrew(ID);

	crewList[index].SetStatus("available");

	return;
}
