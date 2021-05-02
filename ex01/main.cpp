#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		//Bureaucrat a = Bureaucrat("Aristophan", 151);//to close
		//Bureaucrat b = Bureaucrat("Avessalom", 0);//to close
		Bureaucrat c = Bureaucrat("Amenkhotep", 150);
		Bureaucrat d = Bureaucrat("Antiokhey", 1);
		std::cout << c << d;
		//c.decrementGrade();//to close
		c.incrementGrade();
		d.decrementGrade();
		std::cout << c << d;
		//Form fo = Form("avans", 3, 0); //to close
		Form fa = Form("avans", 3, 1);
		std::cout << fa;
		//c.signForm(fa); //to close
		d.signForm(fa);
		d.signForm(fa); //to close
		std::cout << fa;
	}
	catch (std::exception& e)
	{}
	return 0;
}
