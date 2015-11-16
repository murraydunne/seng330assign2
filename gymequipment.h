#pragma once

#include <string>
#include "rapidjson/document.h"

using namespace std;

/// Represents any type of equipment for the gym.
class __declspec(dllexport) GymEquipment
{
protected:
	string name;
	int floorSpace;

public:
	/// While GymEquipment is an abstract class, this constructor
	/// exists to be called from the constructors of child classes.
	/// \param name The name of this equipment.
	/// \param floorSpace The number of square meters of floor space occuplied.
	GymEquipment(string name, int floorSpace);

	/// Destroys this piece of gym equipment.
	virtual ~GymEquipment();

	/// Sets the name of this piece of equipment.
	/// \param newName The name of the equipment.
	void SetName(string newName);

	/// Gets the name of the equipment.
	string GetName();

	/// Sets the number of square meters of floor space occuplied.
	/// \param newFloorSpace The number of square meters of floor space occuplied.
	void SetFloorSpace(int newFloorSpace);

	/// Gets the number of square meters of floor space occuplied.
	int GetFloorSpace();

	/// Pure virtual clone method for the prototype pattern.
	virtual GymEquipment* Clone() = 0;

	/// Serializes this object into a json string.
	virtual string Serialize() = 0;

	/// Deserializes this object from a json string.
	/// \param line The string to desirialize from.
	virtual bool Deserialize(string line) = 0;

private:
	GymEquipment(const GymEquipment& original);
};