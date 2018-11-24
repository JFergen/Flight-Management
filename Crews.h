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
	int* getACrew();
	void fixPilot(int ID);
	void fixCoPilot(int ID);
private:
	int numCrew;
	vector<Crew> crewList;
};