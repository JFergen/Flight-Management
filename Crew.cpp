#include "Crew.h"

Crew::Crew()
{
	name = " ";
	ID = -1;
}

Crew::Crew(string n, int i, type j, status peStat)
{
	name = n;
	ID = i;
	job = j;
	personStatus = peStat;
}

void Crew::SetName(string n)
{
	name = n;
}

void Crew::SetID(int i)
{
	ID = i;
}

void Crew::SetJob(string j)
{
	if (j == "pilot")
	{
		job = pilot;
	}
	else if (j == "copilot")
	{
		job = copilot;
	}
	else if (j == "cabin")
	{
		job = cabin;
	}

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

string Crew::GetJob()
{
	switch (job)
	{
	case 0:
		return "pilot";
	case 1:
		return "copilot";
	case 2:
		return "cabin";
	}

	return "invalid job";
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