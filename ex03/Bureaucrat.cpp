
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpBureaucrat)
{
	*this = cpBureaucrat;
	return ;
}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat &cpBureaucrat)
{
	if (this != &cpBureaucrat)
	{
		this->_grade = cpBureaucrat._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string const	Bureaucrat::getName() const
{
	return (this->_name);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "the grade will be too high." << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "the grade will be too low." << std::endl;
}

int 				Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void 				Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
	return ;
}

void 				Bureaucrat::incrementGrade()
{
	if (this->getGrade() == 1)
	{
		std::cout << "It's impossible because ";
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->setGrade(this->getGrade() - 1);
	return ;
}
void 				Bureaucrat::decrementGrade()
{
	if (this->getGrade() == 150)
	{
		std::cout << "It's impossible because ";
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->setGrade(this->getGrade() + 1);
	return ;
}

void				Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

void 				Bureaucrat::executeForm(Form const & form)
{
	form.execute(*this);
}

std::ostream		&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " has grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}

