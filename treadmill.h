#pragma once

#include <string>
#include "gymequipment.h"

using namespace std;

class Treadmill : public GymEquipment
{
	float topSpeed;
	bool hasTelevision;
public:
	Treadmill(string name, int floorSpace, float topSpeed, bool hasTelevision);
	virtual ~Treadmill();

	void SetTopSpeed(float newTopSpeed);
	float GetTopSpeed();

	void SetHasTelevision(bool newHasTelevision);
	bool HasTelevision();

	virtual GymEquipment* Clone();

private:
	Treadmill(const Treadmill& original);
};