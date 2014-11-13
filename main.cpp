#include "main.hpp"


int main(int argc, char** argv)
{
	Human *h = new Human();
	std::cout << "Hallo, " << h->getName() << std::endl;
	delete h;

	Human *c = new Human("Chuck Norris");
	std::cout << "Hello, " << c->getName() << std::endl;
	delete c;
	return(0);
}

