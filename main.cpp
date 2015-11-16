#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "gymequipment.h"
#include "treadmill.h"
#include "dumbbell.h"

using namespace std;

/// \mainpage Gym Program
/// \section intro_sec Introduction
/// This program simulates the equipment management of a simple gym. The
/// gym has only treadmills and dumbbells.
///

/// The entry point of the program. Loads the current gym state
/// from gym.json, handles the addition of new equipment, and then
/// writes it out to gym.json on quit.
int main(int argc, char* argv[])
{
	vector<GymEquipment*> equipment;

	// the standard equipment to clone with the prototype pattern
	Dumbbell* cannonicalDumbbell = new Dumbbell("prototype", 1, 5.0f);
	Treadmill* cannonicalTreadmill = new Treadmill("prototype", 20, 30.5f, false);

	// read the input file
	ifstream in("gym.json");
	if (in.is_open())
	{
		Dumbbell* currentDumbbell = new Dumbbell("", 0, 0.0);

		while (in)
		{
			string line;
			getline(in, line);

			if (line.length() == 0)
			{
				continue;
			}

			// deserialize into the cannonical equipment, then clone that
			// equipment into the gym vector
			if (cannonicalTreadmill->Deserialize(line))
			{
				equipment.push_back(cannonicalTreadmill->Clone());
			}
			else if (cannonicalDumbbell->Deserialize(line))
			{
				equipment.push_back(cannonicalDumbbell->Clone());
			}
			else
			{
				cout << "Invalid piece of equipment found in gym.json.";
			}
		}

		in.close();
	}
	else
	{
		// if the file is not found, assume we have an empty gym
		cout << "gym.json not found, assuming new and empty gym." << endl;
	}

	// reset the cannonical items
	delete cannonicalDumbbell;
	delete cannonicalTreadmill;
	cannonicalDumbbell = new Dumbbell("prototype", 1, 5.0f);
	cannonicalTreadmill = new Treadmill("prototype", 20, 30.5f, false);

	// while the user has not quit
	while (true)
	{
		// print the current gym equipment
		cout << "There are currently " << equipment.size() << " pieces of equipment in the gym:" << endl;
		
		for (size_t i = 0; i < equipment.size(); i++) 
		{
			cout << equipment[i]->GetName() << endl;
		}

		// prompt the user for input
		cout << "Please enter a name and either \"Dumbbell\" or \"Treadmill\" to create a new piece of equipment (press q to save and quit):";

		string line;
		getline(std::cin, line);

		stringstream ss(line);
		string name;
		string type;

		ss >> name;

		// break on quit
		if (name == "q")
		{
			break;
		}

		ss >> type;

		// clone the cannonical equipment as requested by the user
		GymEquipment* newItem = NULL;
		if (type == "Dumbbell")
		{
			newItem = cannonicalDumbbell->Clone();
		} 
		else if (type == "Treadmill")
		{
			newItem = cannonicalTreadmill->Clone();
		}
		else
		{
			cout << "Invalid type, try again." << endl;
			continue;
		}

		// and put it in the gym list
		newItem->SetName(name);
		equipment.push_back(newItem);
	}

	// free the cannonical equipment
	delete cannonicalDumbbell;
	delete cannonicalTreadmill;

	// output the gym state to the file
	ofstream out("gym.json", ios::out | ios::trunc);
	if (out.is_open())
	{
		for (size_t i = 0; i < equipment.size(); i++)
		{
			out << equipment[i]->Serialize() << endl;
		}
		out.close();
	}
	else
	{
		cout << "Error writing output.";
	}

	// free the gym state list
	for (size_t i = 0; i < equipment.size(); i++)
	{
		delete equipment[i];
	}

	return 0;
}