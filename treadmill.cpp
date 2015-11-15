#include "treadmill.h"

Treadmill::Treadmill(string name, int floorSpace, float topSpeed, bool hasTelevision)
	: GymEquipment(name, floorSpace)
{
	SetTopSpeed(topSpeed);
	SetHasTelevision(hasTelevision);
}

Treadmill::~Treadmill() { }
Treadmill::Treadmill(const Treadmill& original) : GymEquipment("", 0) 
{
	// private copy constructor, must use prototype to clone
}

void Treadmill::SetTopSpeed(float newTopSpeed)
{
	this->topSpeed = newTopSpeed;
}

float Treadmill::GetTopSpeed()
{
	return this->topSpeed;
}

void Treadmill::SetHasTelevision(bool newHasTelevision)
{
	this->hasTelevision = newHasTelevision;
}

bool Treadmill::HasTelevision()
{
	return this->hasTelevision;
}

GymEquipment* Treadmill::Clone()
{
	return new Treadmill(GetName(), GetFloorSpace(), GetTopSpeed(), HasTelevision());
}