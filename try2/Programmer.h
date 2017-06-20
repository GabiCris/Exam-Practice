#pragma once
#include <string>

class Programmer {
private:
	std::string name;
	int id;
public:
	Programmer(const std::string& n, const int& i) : name(n), id(i) {}
	std::string getName() { return this->name; }
	int getId() { return this->id; }
};