#include "dumbbell.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

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

string Dumbbell::Jsonify()
{
	rapidjson::Document val;
	rapidjson::Value str;
	str.SetString(GetName().c_str(), GetName().length(), val.GetAllocator());

	val.SetObject();
	val.AddMember("name", str, val.GetAllocator());
	val.AddMember("floorSpace", GetFloorSpace(), val.GetAllocator());
	val.AddMember("weight", GetWeight(), val.GetAllocator());

	rapidjson::StringBuffer buf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
	val.Accept(writer);

	return buf.GetString();
}