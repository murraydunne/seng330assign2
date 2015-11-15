#include "gymequipment.h"

GymEquipment::GymEquipment(string name, int floorSpace)
{
	SetName(name);
	SetFloorSpace(floorSpace);
}

GymEquipment::~GymEquipment() { }
GymEquipment::GymEquipment(const GymEquipment& original)
{
	// private copy constructor, must use prototype to clone
}

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
