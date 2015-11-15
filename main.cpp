#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "gymequipment.h"
#include "treadmill.h"
#include "dumbbell.h"


using namespace std;

int main(int argc, char* argv[])
{
	vector<GymEquipment*> equipment;

	Dumbbell* cannonicalDumbbell = new Dumbbell("prototype", 1, 5.0f);
	Treadmill* cannonicalTreadmill = new Treadmill("prototype", 20, 30.5f, false);

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
		cout << "gym.json not found, assuming new and empty gym." << endl;
	}

	delete cannonicalDumbbell;
	delete cannonicalTreadmill;
	cannonicalDumbbell = new Dumbbell("prototype", 1, 5.0f);
	cannonicalTreadmill = new Treadmill("prototype", 20, 30.5f, false);

	while (true)
	{
		cout << "There are currently " << equipment.size() << " pieces of equipment in the gym:" << endl;
		
		for (int i = 0; i < equipment.size(); i++) 
		{
			cout << equipment[i]->GetName() << endl;
		}

		cout << "Please enter a name and either \"Dumbbell\" or \"Treadmill\" to create a new piece of equipment (press q to save and quit):";

		string line;
		getline(std::cin, line);

		stringstream ss(line);
		string name;
		string type;

		ss >> name;

		if (name == "q")
		{
			break;
		}

		ss >> type;

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

		newItem->SetName(name);
		equipment.push_back(newItem);
	}

	delete cannonicalDumbbell;
	delete cannonicalTreadmill;

	ofstream out("gym.json", ios::out | ios::trunc);
	if (out.is_open())
	{
		for (int i = 0; i < equipment.size(); i++)
		{
			out << equipment[i]->Serialize() << endl;
		}
		out.close();
	}
	else
	{
		cout << "Error writing output.";
	}

	for (int i = 0; i < equipment.size(); i++)
	{
		delete equipment[i];
	}

	return 0;
}