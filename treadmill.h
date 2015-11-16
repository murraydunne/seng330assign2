#pragma once

#include <string>
#include "gymequipment.h"

using namespace std;

/// Represents a treadmill at the gym.
class Treadmill : public GymEquipment
{
	float topSpeed;
	bool hasTelevision;
public:
	/// Creates a new treadmill in the gym.
	/// \param name The name of this treadmill.
	/// \param floorSpace The number of square meters of floor space occuplied.
	/// \param topSpeed The top speed of this treadmill.
	/// \param hasTelevision True if this treadmill has a build in television.
	Treadmill(string name, int floorSpace, float topSpeed, bool hasTelevision);

	/// Destroys this treadmill.
	virtual ~Treadmill();

	/// Sets the top speed of this treadmill.
	/// \param newTopSpeed The new top speed.
	void SetTopSpeed(float newTopSpeed);

	/// Gets the top speed of this treadmill.
	float GetTopSpeed();

	/// Sets if this treadmill has a build in television.
	/// \param newHasTelevision True if this treadmill has a build in television.
	void SetHasTelevision(bool newHasTelevision);

	/// Does this treadmill have a build it television.
	bool HasTelevision();

	/// Implementation of clone method for the prototype pattern.
	virtual GymEquipment* Clone();

	/// Serializes this object into a json string.
	virtual string Serialize();

	/// Deserializes this object from a json string.
	/// \param line The string to desirialize from.
	virtual bool Deserialize(string line);

private:
	Treadmill(const Treadmill& original);
};