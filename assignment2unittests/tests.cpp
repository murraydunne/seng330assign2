#include "CppUnitTest.h"
#include <string>
#include "../dumbbell.h"
#include "../treadmill.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace assignment2unittests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCloneCreatesIdenticalCopyOfDumbbell)
		{
			Dumbbell* db = new Dumbbell("test", 1, 4.0f);
			Dumbbell* db2 = (Dumbbell*)db->Clone();

			Assert::AreEqual(db->GetName().c_str(), db2->GetName().c_str(), L"Dumbbell names do not match!");
			Assert::AreEqual(db->GetFloorSpace(), db2->GetFloorSpace(), L"Dumbbell floor spaces do not match!");
			Assert::AreEqual(db->GetWeight(), db2->GetWeight(), L"Dumbbell weights do not match!");
			Assert::IsFalse(db == db2, L"The clone of the first dumbbell is the same object as the second!");

			delete db;
			delete db2;
		}

		TEST_METHOD(TestCloneCreatesIdenticalCopyOfTreadmill)
		{
			Treadmill* tr = new Treadmill("test", 1, 23.0f, false);
			Treadmill* tr2 = (Treadmill*)tr->Clone();

			Assert::AreEqual(tr->GetName().c_str(), tr2->GetName().c_str(), L"Treadmill names do not match!");
			Assert::AreEqual(tr->GetFloorSpace(), tr2->GetFloorSpace(), L"Treadmill floorSpaces do not match!");
			Assert::AreEqual(tr->GetTopSpeed(), tr2->GetTopSpeed(), L"Treadmill top speeds do not match!");
			Assert::AreEqual(tr->HasTelevision(), tr2->HasTelevision(), L"Treadmill television statuses do not match!");
			Assert::IsFalse(tr == tr2, L"The clone of the first treadmill is the same object as the second!");

			delete tr;
			delete tr2;
		}

		TEST_METHOD(TestDumbbellSerialization)
		{
			Dumbbell* db = new Dumbbell("test", 1, 4.0f);
			string json = db->Serialize();

			Dumbbell* db2 = new Dumbbell("different", 2, 8.0f);
			db2->Deserialize(json);

			Assert::AreEqual(db->GetName().c_str(), db2->GetName().c_str(), L"Dumbbell names do not match!");
			Assert::AreEqual(db->GetFloorSpace(), db2->GetFloorSpace(), L"Dumbbell floor spaces do not match!");
			Assert::AreEqual(db->GetWeight(), db2->GetWeight(), L"Dumbbell weights do not match!");
		}

		TEST_METHOD(TestTreadmillSerialization)
		{
			Treadmill* tr = new Treadmill("test", 1, 23.0f, false);
			string json = tr->Serialize();

			Treadmill* tr2 = new Treadmill("different", 2, 46.0f, false);
			tr2->Deserialize(json);

			Assert::AreEqual(tr->GetName().c_str(), tr2->GetName().c_str(), L"Treadmill names do not match!");
			Assert::AreEqual(tr->GetFloorSpace(), tr2->GetFloorSpace(), L"Treadmill floorSpaces do not match!");
			Assert::AreEqual(tr->GetTopSpeed(), tr2->GetTopSpeed(), L"Treadmill top speeds do not match!");
			Assert::AreEqual(tr->HasTelevision(), tr2->HasTelevision(), L"Treadmill television statuses do not match!");
		}
	};
}