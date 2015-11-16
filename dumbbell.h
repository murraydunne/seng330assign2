#pragma once

#include <string>
#include "gymequipment.h"

using namespace std;

/// Represents a dumbbell at the gym.
class Dumbbell : public GymEquipment
{
	float weight;

public:
	/// Creates a new dumbbell in the gym.
	/// \param name The name of this dumbbell.
	/// \param floorSpace The number of square meters of floor space occuplied.
	/// \param weight The weight of this dumbbell.
	Dumbbell(string name, int floorSpace, float weight);

	/// Destroys this dumbbell.
	virtual ~Dumbbell();

	/// Sets weight of this dumbbell.
	/// \param newWeight The weight of this dumbbell.
	void SetWeight(float newWeight);

	/// Gets the weight of this dumbbell.
	float GetWeight();

	/// Implementation of clone method for the prototype pattern.
	virtual GymEquipment* Clone();

	/// Serializes this object into a json string.
	virtual string Serialize();

	/// Deserializes this object from a json string.
	/// \param line The string to desirialize from.
	virtual bool Deserialize(string line);

private:
	Dumbbell(const Dumbbell& original);
};