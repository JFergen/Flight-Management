#include "Crew.h"

Crew::Crew()
{
	name = " ";
	ID = -1;

}

Crew::Crew(string n, int i, string peStat)
{
	name = n;
	ID = i;
	SetStatus(peStat);
}

void Crew::SetName(string n)
{
	name = n;
}

void Crew::SetID(int i)
{
	ID = i;
}


void Crew::SetStatus(string peStat)
{
	if (peStat == "available")
	{
		personStatus = avilable;
	}
	else if (peStat == "leave")
	{
		personStatus = leave;
	}
	else if (peStat == "sick")
	{
		personStatus = sick;
	}
}

string Crew::GetName()
{
	return name;
}

int Crew::GetID()
{
	return ID;
}


string Crew::GetStatus()
{
	switch (personStatus)
	{
	case 0:
		return "available";
	case 1:
		return "leave";
	case 2:
		return "sick";
	}

	return "invalid status";
}

void Crew::PrintInfo()
{
	cout << "Name: " << name << endl;
	cout << "ID: " << ID << endl;
	cout << "Status: " << GetStatus() << endl;
}

Pilot::Pilot(string r, int h, string n, int i, string peStat) : Crew (n, i, peStat)
{
	rating = r;
	fHours = h;
}

void Pilot::SetRating(string r)
{
	rating = r;
}

void Pilot::SetHours(int h)
{
	fHours = h;
}

string Pilot::GetRating()
{
	return rating;
}

int Pilot::GetHours()
{
	return fHours;
}

void Pilot::PrintInfo()
{
	Crew::PrintInfo();
	cout << "Pilot Rating: " << rating << endl;
	cout << "Pilot Hours: " << fHours << endl;
}

CoPilot::CoPilot(string r, int h, string n, int i, string peStat) : Crew(n, i, peStat)
{
	rating = r;
	fHours = h;
}

void CoPilot::SetRating(string r)
{
	rating = r;
}

void CoPilot::SetHours(int h)
{
	fHours = h;
}

string CoPilot::GetRating()
{
	return rating;
}

int CoPilot::GetHours()
{
	return fHours;
}

void CoPilot::PrintInfo()
{
	Crew::PrintInfo();
	cout << "CoPilot Rating: " << rating << endl;
	cout << "CoPilot Hours: " << fHours << endl;
}

void Cabin::SetPos(int p)
{
	switch (p)
	{
	case 1:
		cabPosition = First;
		break;
	case 2:
		cabPosition = Business;
		break;
	case 3:
		cabPosition = Front;
		break;
	case 4:
		cabPosition = Rear;
		break;
	case 5:
		cabPosition = Lead;
		break;
	default:
		cabPosition = Invalid;
		break;
	}
}
Cabin::Cabin(int p, string n, int i, string peStat) : Crew(n, i, peStat)
{
	SetPos(p);
}

string Cabin::GetPos()
{
	switch (cabPosition)
	{
	case 1:
		return "First Class";
		break;
	case 2:
		return "Bussiness Class";
		break;
	case 3:
		return "Economy Front";
		break;
	case 4:
		return "Economy Rear";
		break;
	case 5:
		return "Lead";
		break;
	default:
		return "Invalid Position";
		break;
	}
}

int Cabin::GetPosNum()
{
	switch (cabPosition)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	default:
		return 0;
		break;
	}
}

void Cabin::PrintInfo()
{
	Crew::PrintInfo();
	cout << "Cabin position: " << GetPos() << endl;
}
