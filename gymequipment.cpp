#include "gymequipment.h"

GymEquipment::GymEquipment(string name, int floorSpace)
{
	SetName(name);
	SetFloorSpace(floorSpace);
}

GymEquipment::~GymEquipment() { }

void GymEquipment::SetName(string newName)
{
	this->name = newName;
}

string GymEquipment::GetName()
{
	return this->name;
}

void GymEquipment::SetFloorSpace(int newFloorSpace)
{
	this->floorSpace = newFloorSpace;
}

int GymEquipment::GetFloorSpace()
{
	return this->floorSpace;
}
