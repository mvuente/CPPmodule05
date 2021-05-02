#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
		Form fa = Form("avans", 3, 1);
		std::cout << fa;
		//c.signForm(fa);//to close
		d.signForm(fa);
		//d.signForm(fa);//to close
		std::cout << fa;
		//fa.execute(d);//to close
		d.incrementGrade();
		fa.execute(d);
		Intern	bill;
		Form*	paper;
		if ((paper = bill.makeForm("роботомия", "boss")))
			d.signForm(*paper);
		if ((paper = bill.makeForm("robotomyrequest", "boss")))
			d.signForm(*paper);
		paper = bill.makeForm("robotomy request", "boss");
		d.signForm(*paper);
		//paper->execute(c);//to close
		paper->execute(d);
		delete paper;
	}
	catch (std::exception& e)
	{}
	return 0;
}
