#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Crew
{
public:
	Crew();
	enum type {pilot = 0, copilot = 1, cabin = 2};
	enum status { avilable = 0, leave = 1, sick = 2 };
	Crew(string n, int i, type j = pilot, status peStat = avilable);
	void SetName(string n);
	void SetID(int i);
	void SetJob(string j);
	void SetStatus(string pStat);
	string GetName();
	int GetID();
	string GetJob();
	string GetStatus();
private:
	string name;
	int ID;
	type job;
	status personStatus;
};
