#include "Crew.h"

class Crews
{
public:
	Crews();
	~Crews();
	void addCrew();
	void editCrew();
	void deleteCrew();
	int searchCrew(int i);
	void printCrew();
	void printCrewByID();
	void storeCrew();
	void loadCrew();
	int getAPilot();
	int getACoPilot();
	int getCrew1();
	int getCrew2();
	int getCrew3();
	void fixPilot(int ID);
	void fixCoPilot(int ID);
	void fixCrew1(int ID);
	void fixCrew2(int ID);
	void fixCrew3(int ID);
	string getCrewStatus(int ID);
private:
	int numCrew;
	vector<Crew*> crewList;
};
