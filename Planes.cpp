#include "Planes.h"
#include <fstream>

Planes::Planes()
{
	numPlanes = 0;
	loadPlanes();
}

Planes::~Planes()
{
	storePlanes();
}

void Planes::addPlane()
{
	string pMake;
	string pModel;
	string pTN;
	int numSeats;
	int maxRange;
	string planeStat;

	cout << "Enter plane make:";
	cin >> pMake;
	cin.ignore();

	cout << "Enter plane model:";
	cin >> pModel;
	cin.ignore();

	cout << "Enter plane tail number:";
	cin >> pTN;
	cin.ignore();

	cout << "Enter max number of seats:";
	cin >> numSeats;

	cout << "Enter max range of plane (miles):";
	cin >> maxRange;

	cout << "Enter status of plane (in, out, repair):";
	cin >> planeStat;

	Plane tmpPlane(pMake, pModel, pTN, numSeats, maxRange);

	tmpPlane.SetStatus(planeStat);

	planeList.push_back(tmpPlane);
	numPlanes++;
}

void Planes::editPlane()
{
	string tailNum;
	int newNumSeats;
	int newRange;
	string newStatus;
	int choice = 0;

	cout << "Enter tail number of plane to edit:";
	cin >> tailNum;
	cin.ignore();

	if (searchPlane(tailNum) != -1)
	{
		int index = searchPlane(tailNum);
		cout << "Plane found" << endl << endl;

		cout << "Choose what you would like to edit:" << endl;
		cout << "1 - Number of seats" << endl;
		cout << "2 - Max range of plane" << endl;
		cout << "3 - Status of plane" << endl;

		cout << "Enter choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter new number of seats:";
			cin >> newNumSeats;
			planeList[index].SetSeats(newNumSeats);
			cout << "New number of seats has been updated" << endl;
			break;
		case 2:
			cout << "Enter new max range (miles):";
			cin >> newRange;
			planeList[index].SetRange(newRange);
			cout << "Max range has been updated" << endl;
			break;
		case 3:
			cout << "Enter new status of plane (in, out, repair):";
			cin >> newStatus;
			planeList[index].SetStatus(newStatus);
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
		cout << "Plane can not be found" << endl;
		return;
	}
}

int Planes::searchPlane(string tN)
{
	int index = 0;

	for (index; index < numPlanes; index++)
	{
		if (planeList[index].GetTailNum() == tN)
		{
			return index;
		}
	}

	if (index == numPlanes)
	{
		return -1;
	}

	return -1;
}

void Planes::deletePlane()
{
	string tailNum;

	cout << "Enter tail number of plane to delete:";
	cin >> tailNum;

	if (searchPlane(tailNum) != -1)
	{
		cout << "Plane found" << endl;
		int index = searchPlane(tailNum);

		planeList.erase(planeList.begin() + index);
		numPlanes--;
		cout << "Plane has been erased" << endl;
		return;
	}
	else
	{
		cout << "Plane can not be found" << endl;
		return;
	}
}

void Planes::printPlanes()
{
	for (int i = 0; i < numPlanes; i++)
	{
		cout << "Plane #" << i + 1 << endl;
		cout << "Make: " << planeList[i].GetMake() << endl;
		cout << "Model: " << planeList[i].GetModel() << endl;
		cout << "Tail number: " << planeList[i].GetTailNum() << endl;
		cout << "Number of seats: " << planeList[i].GetSeats() << endl;
		cout << "Range: " << planeList[i].GetRange() << endl;
		cout << "Status: " << planeList[i].GetStatus() << endl << endl;
	}
}

void Planes::printPlaneByID()
{
	string tailNum;

	cout << "Enter tail number:";
	cin >> tailNum;

	if (searchPlane(tailNum) != -1)
	{
		int index = searchPlane(tailNum);

		cout << "Plane found. Printing information:" << endl << endl;
		cout << "Make: " << planeList[index].GetMake() << endl;
		cout << "Model: " << planeList[index].GetModel() << endl;
		cout << "Tail number: " << planeList[index].GetTailNum() << endl;
		cout << "Number of seats: " << planeList[index].GetSeats() << endl;
		cout << "Range: " << planeList[index].GetRange() << endl;
		cout << "Status: " << planeList[index].GetStatus() << endl << endl;
		return;
	}
	else
	{
		cout << "Plane can not be found." << endl;
		return;
	}
}

void Planes::storePlanes()
{
	ofstream fout;
	fout.open("planes.dat");

	fout << numPlanes << endl;

	for (int i = 0; i < numPlanes; i++)
	{
		fout << planeList[i].GetMake() << " " << planeList[i].GetModel() << " " << planeList[i].GetTailNum() << " " << planeList[i].GetSeats() << " " << planeList[i].GetRange() << " " << planeList[i].GetStatus() << endl;
	}

	fout.close();
}

void Planes::loadPlanes()
{
	ifstream fin;

	string make;
	string model;
	string tailNum;
	int seats;
	int range;
	string pStatus;

	fin.open("planes.dat");

	fin >> numPlanes;
	fin.ignore();

	for (int i = 0; i < numPlanes; i++)
	{
		fin >> make >> model >> tailNum >> seats >> range >> pStatus;
		Plane tmp(make, model, tailNum, seats, range);
		tmp.SetStatus(pStatus);

		planeList.push_back(tmp);
	}

	fin.close();
}

string Planes::getPlane()
{
	for (int i = 0; i < numPlanes; i++)
	{
		if (planeList[i].GetStatus() == "in")
		{
			planeList[i].SetStatus("out");
			return planeList[i].GetTailNum();
		}

		if (i == numPlanes)
		{
			return "none";
		}
	}

	return "none";
}

void Planes::fixPlane(string tN)
{
	int index;

	index = searchPlane(tN);

	planeList[index].SetStatus("in");

	return;
}

int Planes::getSeat(string tN)
{
	int index;

	index = searchPlane(tN);

	return planeList[index].GetSeats();
}
