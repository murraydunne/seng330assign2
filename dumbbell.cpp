#include "dumbbell.h"

Dumbbell::Dumbbell(string name, int floorSpace, float weight)
	: GymEquipment(name, floorSpace)
{
	SetWeight(weight);
}

Dumbbell::~Dumbbell() { }
Dumbbell::Dumbbell(const Dumbbell& original) : GymEquipment("", 0) 
{ 
	// private copy constructor, must use prototype to clone
}

void Dumbbell::SetWeight(float newWeight)
{
	this->weight = newWeight;
}

float Dumbbell::GetWeight()
{
	return this->weight;
}

GymEquipment* Dumbbell::Clone()
{
	return new Dumbbell(GetName(), GetFloorSpace(), GetWeight());
}