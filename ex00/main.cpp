#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		//Bureaucrat a = Bureaucrat("Aristophan", 151); // to close
		//Bureaucrat b = Bureaucrat("Avessalom", 0); //to close
		Bureaucrat c = Bureaucrat("Amenkhotep", 150);
		Bureaucrat d = Bureaucrat("Antiokhey", 1);
		std::cout << c << d;
		c.incrementGrade();
		//d.incrementGrade();// to close
		d.decrementGrade();
		std::cout << c << d;
	}
	catch (std::exception& e)
	{}
	return 0;
}
