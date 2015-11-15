#pragma once

#include <string>
#include "rapidjson/document.h"

using namespace std;

class GymEquipment
{
protected:
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
	virtual string Jsonify() = 0;

private:
	GymEquipment(const GymEquipment& original);
};