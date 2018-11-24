#include "Plane.h"

class Planes
{
	public:
		Planes();
		~Planes();
		void addPlane();
		void editPlane();
		void deletePlane();
		int searchPlane(string tN);
		void printPlanes();
		void printPlaneByID();
		void storePlanes();
		void loadPlanes();
		string getPlane();
		void fixPlane(string tN);
		int getSeat(string tN);
	private:
		int numPlanes;
		vector<Plane> planeList;
};