#pragma once
#include "../main.hpp"

class Human
{
public:
	Human();
	Human(std::string name);
	virtual ~Human();
	std::string getName();
	unsigned int Factorial( unsigned int number ) {
 	   return number <= 1 ? number : Factorial(number-1)*number;
	}

private:
	std::string name;

};

