#pragma once
#include <string>
#include <vector>

using namespace std;

enum sex {male, female};

class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;

	string _name;
	int _id;

public:
	Slav();

	sex _sex()
	{
		if(_name[_name.length()-1]=='a')
			return female;
		else return male;
	}

	static int counter() { return _counter; }
	
	string name() { return _name; }
	int id() { return _id; }

	string description();
};
