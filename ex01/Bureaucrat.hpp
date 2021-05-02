
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

#include "Form.hpp"

class Bureaucrat
{
private:
	std::string const	_name;
	int 				_grade;
	Bureaucrat();
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat &cpBureaucrat);
	Bureaucrat			&operator=(const Bureaucrat &cpBureaucrat);
	virtual ~Bureaucrat();

	std::string const	getName() const;
	int 				getGrade() const;
	void 				setGrade(int grade);
	void 				incrementGrade();
	void 				decrementGrade();
	void				signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
	};
};

std::ostream		&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
