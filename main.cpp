#include <iostream>
#include <string>
#include <vector>

#include "gymequipment.h"
#include "treadmill.h"
#include "dumbbell.h"


using namespace std;

int main(int argc, char* argv[])
{
	cout << "This is a simple gym." << endl;

	GymEquipment* e = new Treadmill("treadmill1", 12, 24.2f, false); 
	
	string json = e->Jsonify();

	cout << json;

	int i;
	cin >> i;

	return 0;
}