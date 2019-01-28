#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Plane
{
	public:
		Plane();
		enum status {in = 0, out = 1, repair = 2};
		Plane(string m, string mo, string tN, int s, int r, status pStat = in);
		void SetMake(string m);
		void SetModel(string mo);
		void SetTailNum(string tN);
		void SetSeats(int s);
		void SetRange(int r);
		void SetStatus(string pStat);
		string GetMake();
		string GetModel();
		string GetTailNum();
		int GetSeats();
		int GetRange();
		string GetStatus();
	private:
		string make;
		string model;
		string tailNum;
		int seats;
		int range;
		status planeStatus;
};

