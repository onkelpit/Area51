#include "../main.hpp"

Human::Human()
{
	name = "Peter Johennecken";
}

Human::Human(std::string name)
{
	this->name = name;
}

Human::~Human() {}

std::string Human::getName()
{
	return(name);
}

