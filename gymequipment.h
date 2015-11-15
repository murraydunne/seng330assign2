#pragma once

#include <string>

using namespace std;

class GymEquipment
{
	string name;
	int floorSpace;

public:
	GymEquipment(string name, int floorSpace);
	virtual ~GymEquipment();

	void SetName(string newName);
	string GetName();

	void SetFloorSpace(int newFloorSpace);
	int GetFloorSpace();

	virtual GymEquipment* Clone() = 0;

private:
	GymEquipment(const GymEquipment& original);
};