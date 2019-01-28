#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Crew
{
public:
	Crew();
	enum status { avilable = 0, leave = 1, sick = 2 };
	Crew(string n, int i, string peStat);
	void SetName(string n);
	void SetID(int i);
	void SetStatus(string pStat);
	string GetName();
	int GetID();
	string GetStatus();
	virtual void PrintInfo();
private:
	string name;
	int ID;
	status personStatus;
};

class Pilot : public Crew
{
public:
	Pilot(string r, int h, string n, int i, string peStat);
	void SetRating(string r);
	void SetHours(int h);
	string GetRating();
	int GetHours();
	void PrintInfo();
private:
	string rating; // 5 Character
	int fHours;
};

class CoPilot : public Crew
{
public:
	CoPilot(string r, int h, string n, int i, string peStat);
	void SetRating(string r);
	void SetHours(int h);
	string GetRating();
	int GetHours();
	void PrintInfo();
private:
	string rating; // 4 Character
	int fHours;
};

class Cabin : public Crew
{
public:
	Cabin(int p, string n, int i, string peStat);
	enum position {First = 1, Business, Front, Rear, Lead, Invalid };
	void SetPos(int p);
	string GetPos();
	int GetPosNum();
	void PrintInfo();
private:
	int pos; // 1 - First Class, 2 - Bussiness Class, 3 - Economy Front, 4 - Economy Rear, 5 - Lead
	position cabPosition;
};
