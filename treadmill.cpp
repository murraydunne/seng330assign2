#include "treadmill.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

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

string Treadmill::Serialize()
{
	rapidjson::Document val;
	rapidjson::Value str;
	str.SetString(GetName().c_str(), GetName().length(), val.GetAllocator());

	val.SetObject();
	val.AddMember("name", str, val.GetAllocator());
	val.AddMember("floorSpace", GetFloorSpace(), val.GetAllocator());
	val.AddMember("topSpeed", GetTopSpeed(), val.GetAllocator());
	val.AddMember("hasTelevision", HasTelevision(), val.GetAllocator());

	rapidjson::StringBuffer buf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
	val.Accept(writer);

	return buf.GetString();
}

bool Treadmill::Deserialize(string line)
{
	rapidjson::StringStream in(line.c_str());
	rapidjson::Document val;
	val.ParseStream(in);

	if (!val.HasMember("topSpeed"))
	{
		return false;
	}

	SetName(val["name"].GetString());
	SetFloorSpace(val["floorSpace"].GetInt());
	SetTopSpeed((float)val["topSpeed"].GetDouble());
	SetHasTelevision(val["hasTelevision"].GetBool());

	return true;
}