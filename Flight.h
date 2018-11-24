#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Flight
{
public:
	Flight();
	enum status { active = 0, cancelled = 1, completed = 2 };
	Flight(int fID, string pID, int piID, int cpiID, int c1, int c2, int c3, int sTime,
		int eTime, string sPort, string ePort, int nP);
	void SetFlightID(int fID);
	void SetPlaneID(string pID);
	void SetPilotID(int piID);
	void SetCoPilotID(int cpiID);
	void SetCrewsID(int c1, int c2, int c3);
	void SetStartTime(int sTime);
	void SetEndTime(int eTime);
	void SetStartPort(string sPort);
	void SetEndPort(string ePort);
	void SetNumPassengers(int nP);
	void SetStatus(string fS);
	int GetFlightID();
	string GetPlaneID();
	int GetPilotID();
	int GetCoPilotID();
	int GetCrew1ID();
	int GetCrew2ID();
	int GetCrew3ID();
	int GetStartTime();
	int GetEndTime();
	string GetStartPort();
	string GetEndPort();
	int GetNumPassengers();
	string GetStatus();
private:
	int flightID;
	string planeID;
	int pilotID;
	int coPilotID;
//	int *crewID;
	int crewID[3];
	int startTime;
	int endTime;
	string startPort;
	string endPort;
	int numPassengers;
	status flightStatus;
};
