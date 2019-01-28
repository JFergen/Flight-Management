#include <fstream>
#include <iterator>
#include <typeinfo>
#include "Crews.h"

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
	int cJob;
	string cStat;
	string pRating;
	int totHours;
	int cabPos;
	Crew *temp;

	cout << "Enter crew member name:";
	getline(cin, cName);

	cout << "Enter crew member ID:";
	cin >> cID;
	cin.ignore();

	cout << "Enter status of crew member (available, leave, sick):";
	cin >> cStat;

	cout << "Enter job of crew member (1 for Pilot, 2 for CoPilot, 3 for Cabin):";
	cin >> cJob;

	switch (cJob)
	{
	case 1:
		cout << "Enter 5 character Pilot rating:";
		cin >> pRating;

		cout << "Enter Pilot's total flying hours:";
		cin >> totHours;

		temp = new Pilot(pRating, totHours, cName, cID, cStat);
		break;
	case 2:
		cout << "Enter 4 character CoPilot rating:";
		cin >> pRating;

		cout << "Enter CoPilot's total flying hours:";
		cin >> totHours;

		temp = new CoPilot(pRating, totHours, cName, cID, cStat);
		break;
	case 3:
		cout << "Enter position of cabin member (1 for First Class, 2 for Business Class, 3 for Economy Front, 4 for Economy Rear, 5 for Lead):";
		cin >> cabPos;

		temp = new Cabin(cabPos, cName, cID, cStat);
		break;
	default:
		cout << "Invalid Job. Try again." << endl;
		cout << "Enter job of crew member (1 for Pilot, 2 for CoPilot, 3 for Cabin):";
		cin >> cJob;
		break;
	}

	crewList.push_back(temp);
	numCrew++;
}

void Crews::editCrew()
{
	int cID;
	string newName;
	int newJob;
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
			crewList[index]->SetName(newName);
			cout << "Name has been updated" << endl;
			break;
		case 2:
			cout << "Enter new job (1 for pilot, 2 for copilot, 3 for cabin):";
			cin >> newJob;

			/*switch (newJob)
			{
			case 1:
				// Delete Old one and add new one with required info
			}
			crewList[index].SetJob(newJob);
			cout << "Job has been updated" << endl;
			break;*/
		case 3:
			cout << "Enter new status of crew member (available, leave, sick):";
			cin >> newStatus;
			crewList[index]->SetStatus(newStatus);
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
		if (crewList[index]->GetID() == i)
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
	Crew *temp;
	int i = 1;
	for (auto it = crewList.begin(); it != crewList.end(); it++)
	{
		temp = *it;
		cout << "Crew member #" << i << endl;
		cout << "Name: " << temp->GetName() << endl;
		cout << "ID: " << temp->GetID() << endl;
		cout << "Status: " << temp->GetStatus() << endl;

		if (typeid(*temp) == typeid (Pilot))
		{
			Pilot *tempPi = dynamic_cast<Pilot*> (temp);
			cout << "Pilot rating: " << tempPi->GetRating() << endl; 
			cout << "Total Hours: " << tempPi->GetHours() << endl << endl;
		}

		else if (typeid(*temp) == typeid (CoPilot))
		{
			CoPilot *tempPi = dynamic_cast<CoPilot*> (temp);
			cout << "CoPilot rating: " << tempPi->GetRating() << endl;
			cout << "Total Hours: " << tempPi->GetHours() << endl << endl;
		}

		else if (typeid(*temp) == typeid (Cabin))
		{
			Cabin *tempCab = dynamic_cast<Cabin*> (temp);
			cout << "Cabin position: " << tempCab->GetPos() << endl << endl;
		}
		i++;
	}
}

void Crews::printCrewByID()
{
	int cID;

	cout << "Enter crew member ID:";
	cin >> cID;

	Crew *temp;
	if (searchCrew(cID) != -1)
	{
		int index = searchCrew(cID);

		auto it = (crewList.begin() + index);
		temp = *it;

		cout << "Crew member found. Printing information:" << endl << endl;
		cout << "Name: " << crewList[index]->GetName() << endl;
		cout << "ID: " << crewList[index]->GetID() << endl;
		cout << "Status: " << crewList[index]->GetStatus() << endl;

		if (typeid(*temp) == typeid (Pilot))
		{
			Pilot *tempPi = dynamic_cast<Pilot*> (temp);
			cout << "Pilot rating: " << tempPi->GetRating() << endl;
			cout << "Total Hours: " << tempPi->GetHours() << endl << endl;
		}

		else if (typeid(*temp) == typeid (CoPilot))
		{
			CoPilot *tempPi = dynamic_cast<CoPilot*> (temp);
			cout << "CoPilot rating: " << tempPi->GetRating() << endl;
			cout << "Total Hours: " << tempPi->GetHours() << endl << endl;
		}

		else if (typeid(*temp) == typeid (Cabin))
		{
			Cabin *tempCab = dynamic_cast<Cabin*> (temp);
			cout << "Cabin position: " << tempCab->GetPos() << endl << endl;
		}

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

	Crew *temp;
	for (auto it = crewList.begin(); it != crewList.end(); ++it)
	{
		temp = *it;
		fout << temp->GetName() << endl;
		fout << temp->GetID() << " " << temp->GetStatus() << " ";

		if (typeid(*temp) == typeid (Pilot))
		{
			Pilot *tempPi = dynamic_cast<Pilot*> (temp);
			fout << "1 " << tempPi->GetRating() << " " << tempPi->GetHours() << endl;
		}

		else if (typeid(*temp) == typeid (CoPilot))
		{
			CoPilot *tempCoPi = dynamic_cast<CoPilot*> (temp);
			fout << "2 " << tempCoPi->GetRating() << " " << tempCoPi->GetHours() << endl;
		}

		else if (typeid(*temp) == typeid (Cabin))
		{
			Cabin *tempCab = dynamic_cast<Cabin*> (temp);
			fout << "3 " << tempCab->GetPosNum() << endl;
		}
	}
	fout.close();
}

void Crews::loadCrew()
{
	ifstream fin;

	string name;
	int ID;
	int job;
	string pStatus;
	string rating;
	int hours;
	int pos;

	fin.open("crews.dat");

	fin >> numCrew;
	fin.ignore();

	for (int i = 0; i < numCrew; i++)
	{
		getline(fin, name);
		fin >> ID >> pStatus >> job;
		fin.ignore();

		if (job == 1)
		{
			fin >> rating >> hours;
			fin.ignore();
			Pilot *newPilot = new Pilot(rating, hours, name, ID, pStatus);
			crewList.push_back(newPilot);
		}

		else if (job == 2)
		{
			cout << "CoPilot" << endl;
			fin >> rating >> hours;
			fin.ignore();
			CoPilot *newCoPilot = new CoPilot(rating, hours, name, ID, pStatus);
			crewList.push_back(newCoPilot);
		}

		else if (job == 3)
		{
			cout << "Cabin" << endl;
			fin >> pos;
			fin.ignore();
			Cabin *newCab = new Cabin(pos, name, ID, pStatus);
			crewList.push_back(newCab);
		}
	}
	fin.close();
}

int Crews::getAPilot()
{
	Crew *temp;
	for (auto it = crewList.begin(); it != crewList.end(); ++it)
	{
		temp = *it;
		if (typeid(*temp) == typeid (Pilot) && (temp->GetStatus() == "available"))
		{
			temp->SetStatus("leave");
			return temp->GetID();
		}

		if (it == crewList.end())
		{
			return -1;
		}
	}

	return -1;
}

int Crews::getACoPilot()
{
	Crew *temp;
	for (auto it = crewList.begin(); it != crewList.end(); ++it)
	{
		temp = *it;
		if (typeid(*temp) == typeid (CoPilot) && (temp->GetStatus() == "available"))
		{
			temp->SetStatus("leave");
			return temp->GetID();
		}

		if (it == crewList.end())
		{
			cout << "No copilots available at this time." << endl << endl;

			return -1;
		}
	}

	return -1;
}

int Crews::getCrew1()
{
	Crew *temp;
	for (auto it = crewList.begin(); it != crewList.end(); ++it)
	{
		temp = *it;
		if (typeid(*temp) == typeid (Cabin) && (temp->GetStatus() == "available"))
		{
			temp->SetStatus("leave");
			return temp->GetID();
		}

		if (it == crewList.end())
		{
			cout << "Not enough cabin crew available at this time." << endl << endl;

			return -1;
		}
	}

	return -1;
}

int Crews::getCrew2()
{
	Crew *temp;
	for (auto it = crewList.begin(); it != crewList.end(); ++it)
	{
		temp = *it;
		if (typeid(*temp) == typeid (Cabin) && (temp->GetStatus() == "available"))
		{
			temp->SetStatus("leave");
			return temp->GetID();
		}

		if (it == crewList.end())
		{
			cout << "Not enough cabin crew available at this time." << endl << endl;

			return -1;
		}
	}

	return -1;
}

int Crews::getCrew3()
{
	Crew *temp;
	for (auto it = crewList.begin(); it != crewList.end(); ++it)
	{
		temp = *it;
		if (typeid(*temp) == typeid (Cabin) && (temp->GetStatus() == "available"))
		{
			temp->SetStatus("leave");
			return temp->GetID();
		}

		if (it == crewList.end())
		{
			cout << "Not enough cabin crew available at this time." << endl << endl;

			return -1;
		}
	}

	return -1;
}


void Crews::fixPilot(int ID)
{
	int index;

	index = searchCrew(ID);

	Crew *temp;
	auto it = (crewList.begin() + index);
	temp = *it;

	temp->SetStatus("available");
	
	return;
}

void Crews::fixCoPilot(int ID)
{
	int index;

	index = searchCrew(ID);

	Crew *temp;
	auto it = (crewList.begin() + index);
	temp = *it;

	temp->SetStatus("available");

	return;
}

void Crews::fixCrew1(int ID)
{
	int index;

	index = searchCrew(ID);

	Crew *temp;
	auto it = (crewList.begin() + index);
	temp = *it;

	temp->SetStatus("available");

	return;
}

void Crews::fixCrew2(int ID)
{
	int index;

	index = searchCrew(ID);

	Crew *temp;
	auto it = (crewList.begin() + index);
	temp = *it;

	temp->SetStatus("available");

	return;
}

void Crews::fixCrew3(int ID)
{
	int index;

	index = searchCrew(ID);

	Crew *temp;
	auto it = (crewList.begin() + index);
	temp = *it;

	temp->SetStatus("available");

	return;
}

string Crews::getCrewStatus(int ID)
{
	int index;

	index = searchCrew(ID);

	Crew *temp;
	auto it = (crewList.begin() + index);
	temp = *it;

	return temp->GetStatus();
}
