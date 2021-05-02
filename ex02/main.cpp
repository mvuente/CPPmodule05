#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		//Bureaucrat a = Bureaucrat("Aristophan", 151); //to close
		//Bureaucrat b = Bureaucrat("Avessalom", 0); //to close
		Bureaucrat c = Bureaucrat("Amenkhotep", 150);
		Bureaucrat d = Bureaucrat("Antiokhey", 1);
		std::cout << c << d;
		//c.decrementGrade(); //to close
		c.incrementGrade();
		d.decrementGrade();
		std::cout << c << d;
		//Form fo = Form("avans", 3, 0); //to close
		Form fa = Form("avans", 3, 1);
		Form *shrub = new ShrubberyCreationForm("home");
		Form *robomed = new RobotomyRequestForm("boss");
		Form *pardon = new PresidentialPardonForm("Avessalom");
		std::cout << fa;
		//c.signForm(fa); //to close
		d.signForm(fa);
		//d.signForm(fa); //to close
		std::cout << fa;
		//fa.execute(d); //to close
		d.incrementGrade();
		fa.execute(d);
		d.signForm(*shrub);
		d.signForm(*robomed);
		d.signForm(*pardon);
		//shrub->execute(c); //to close
		shrub->execute(d);
		robomed->execute(d);
		pardon->execute(d);
	}
	catch (std::exception& e)
	{}
	return 0;
}
