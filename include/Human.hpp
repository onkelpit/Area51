#pragma once
#include "../main.hpp"

class Human
{
public:
	Human();
	Human(std::string name);
	virtual ~Human();
	std::string getName();

private:
	std::string name;

};
