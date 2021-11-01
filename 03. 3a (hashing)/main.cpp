#include <iostream>
#include <unordered_set>

using namespace std;
struct Test {
	int key;
	string name;
	Test(int k, string s) : key(k), name(s) {}
	bool operator == (const Test& t2) const { return key == t2.key; }
};

template<>
class hash<Test> {
public:
	size_t operator() (const Test& t) const { return t.key % 7; }
	bool operator() (const Test& t1, const Test& t2) { return t1.key == t2.key; }
};

int main(int argc, char* argv[])
{
	hash<Test> hashtabell;
	unordered_set<Test> uordnet_sett;
	
	Test t1(12, "num1");
	Test t2(13, "num2");
	Test t3(20, "num3");
	Test t4(21, "num4");
	Test t5(1, "num5");
	Test t6(2, "num6");
	Test t7(3, "num7");
	Test t8(4, "num8");
	Test t9(5, "num9");
	Test t10(6, "num10");

	uordnet_sett.insert(t1);
	uordnet_sett.insert(t2);
	uordnet_sett.insert(t3);
	uordnet_sett.insert(t4);
	uordnet_sett.insert(t5);
	uordnet_sett.insert(t6);
	uordnet_sett.insert(t7);
	uordnet_sett.insert(t8);
	uordnet_sett.insert(t9);
	uordnet_sett.insert(t10);

	for (auto a: uordnet_sett)
	{
		cout << "key: " << a.key << "\tname: " << a.name << endl;
	}

	return 0;
}