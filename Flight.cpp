#include "Flight.h"

Flight::Flight()
{
	flightID = 0;
	planeID = " ";
	pilotID = -1;
	coPilotID = -1;
	crewID[0] = -1;
	crewID[1] = -1;
	crewID[2] = -1;
	startTime = -1;
	endTime = -1;
	startPort = " ";
	endPort = " ";
	numPassengers = -1;
}

Flight::Flight(int fID, string pID, int piID, int cpiID, int c1, int c2, int c3, int sTime,
	int eTime, string sPort, string ePort, int nP)
{
	flightID = fID;
	planeID = pID;
	pilotID = piID;
	coPilotID = cpiID;
	crewID[0] = c1;
	crewID[1] = c2;
	crewID[2] = c3;
	startTime = sTime;
	endTime = eTime;
	startPort = sPort;
	endPort = ePort;
	numPassengers = nP;
}

void Flight::SetFlightID(int fID)
{
	flightID = fID;
}

void Flight::SetPlaneID(string pID)
{
	planeID = pID;
}

void Flight::SetPilotID(int piID)
{
	pilotID = piID;
}

void Flight::SetCoPilotID(int cpiID)
{
	coPilotID = cpiID;
}

void Flight::SetCrewsID(int c1, int c2, int c3)
{
	crewID[0] = c1;
	crewID[1] = c2;
	crewID[2] = c3;
}

void Flight::SetCrew1ID(int c1)
{
	crewID[0] = c1;
}

void Flight::SetCrew2ID(int c2)
{
	crewID[1] = c2;
}

void Flight::SetCrew3ID(int c3)
{
	crewID[2] = c3;
}

void Flight::SetStartTime(int sTime)
{
	startTime = sTime;
}

void Flight::SetEndTime(int eTime)
{
	endTime = eTime;
}

void Flight::SetStartPort(string sPort)
{
	startPort = sPort;
}

void Flight::SetEndPort(string ePort)
{
	endPort = ePort;
}

void Flight::SetNumPassengers(int nP)
{
	numPassengers = nP;
}

void Flight::SetStatus(string fS)
{
	if (fS == "active")
	{
		flightStatus = active;
	}
	else if (fS == "cancelled")
	{
		flightStatus = cancelled;
	}
	else if (fS == "completed")
	{
		flightStatus = completed;
	}
}

int Flight::GetFlightID()
{
	return flightID;
}

string Flight::GetPlaneID()
{
	return planeID;
}

int Flight::GetPilotID()
{
	return pilotID;
}

int Flight::GetCoPilotID()
{
	return coPilotID;
}

int Flight::GetCrew1ID()
{
	return crewID[0];
}

int Flight::GetCrew2ID()
{
	return crewID[1];
}

int Flight::GetCrew3ID()
{
	return crewID[2];
}

int Flight::GetStartTime()
{
	return startTime;
}

int Flight::GetEndTime()
{
	return endTime;
}

string Flight::GetStartPort()
{
	return startPort;
}

string Flight::GetEndPort()
{
	return endPort;
}

int Flight::GetNumPassengers()
{
	return numPassengers;
}

string Flight::GetStatus()
{
	switch (flightStatus)
	{
	case 0:
		return "active";
	case 1:
		return "cancelled";
	case 2:
		return "completed";
	}

	return "invalid status";
}
