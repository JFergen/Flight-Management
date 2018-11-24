#include "Flight.h"

class Flights
{
public:
	Flights();
	~Flights();
	void addFlight();
	//void editFlight();
	void deleteFlight();
	int searchFlight(int fID);
	void printFlights();
	void printFlightByID();
	void printSomeFlights();
	void deleteFinishedFlights();
	void updateFlights();
	void storeFlights();
	void loadFlights();
private:
	int numFlights;
	int flightID;
	vector<Flight> flightList;
};