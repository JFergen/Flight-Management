#include "Plane.h"

Plane::Plane()
{
	make = " ";
	model = " ";
	tailNum = " ";
	seats = 0;
	range = 0;
}

Plane::Plane(string m, string mo, string tN, int s, int r, status pStat)
{
	make = m;
	model = mo;
	tailNum = tN;
	seats = s;
	range = r;
	planeStatus = pStat;
}

void Plane::SetMake(string m)
{
	make = m;
}

void Plane::SetModel(string mo)
{
	model = mo;
}

void Plane::SetTailNum(string tN)
{
	tailNum = tN;
}

void Plane::SetSeats(int s)
{
	seats = s;
}

void Plane::SetRange(int r)
{
	range = r;
}

void Plane::SetStatus(string pStat)
{
	if (pStat == "in")
	{
		planeStatus = in;
	}
	else if (pStat == "out")
	{
		planeStatus = out;
	}
	else if (pStat == "repair")
	{
		planeStatus = repair;
	}
}

string Plane::GetMake()
{
	return make;
}

string Plane::GetModel()
{
	return model;
}

string Plane::GetTailNum()
{
	return tailNum;
}

int Plane::GetSeats()
{
	return seats;
}

int Plane::GetRange()
{
	return range;
}

string Plane::GetStatus()
{
	switch (planeStatus)
	{
	case 0:
		return "in";
	case 1:
		return "out";
	case 2:
		return "repair";
	}

	return "invalid status";
}
