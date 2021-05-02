
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Form;

#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const 	_name;
	int const	 		_grade_to_sign;
	int const			_grade_to_exec;
	bool 				_sign;
	Form();
public:

	Form(std::string const name, int const grade_to_sign, int const grade_to_exec);
	Form(const Form &cpForm);
	Form&			operator=(const Form &cpForm);
	virtual ~Form();

	std::string 	getName() const;
	bool 			getSign() const;
	int 			getGrade_to_sign() const;
	int 			getGrade_to_exec() const;
	void 			beSigned(Bureaucrat &bcrat);

	class FormSignedAlreadyException : public std::exception
	{
	public:
		FormSignedAlreadyException();
	};

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

std::ostream		&operator<<(std::ostream &out, const Form &form);

#endif
