#pragma once

#include <string>
#include "gymequipment.h"

using namespace std;

class Dumbbell : public GymEquipment
{
	float weight;

public:
	Dumbbell(string name, int floorSpace, float weight);
	virtual ~Dumbbell();

	void SetWeight(float newWeight);
	float GetWeight();

	virtual GymEquipment* Clone();
	virtual string Jsonify();

private:
	Dumbbell(const Dumbbell& original);
};