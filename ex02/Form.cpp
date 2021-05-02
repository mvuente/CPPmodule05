
#include "Form.hpp"

Form::Form() : _grade_to_sign(0), _grade_to_exec(0)
{}

Form::Form(std::string const &name, int const &grade_to_sign, int const &grade_to_exec) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_sign = 0;
}

Form::Form(const Form &cpForm) : _name(cpForm._name), _grade_to_sign(cpForm._grade_to_sign), _grade_to_exec(cpForm._grade_to_exec)
{
	*this = cpForm;
	return ;
}

Form&			Form::operator=(const Form &cpForm)
{
	if (this != &cpForm)
	{
		this->_sign = cpForm._sign;
	}
	return (*this);
}

Form::~Form()
{}

std::string 	Form::getName() const
{
	return (this->_name);
}

bool 			Form::getSign() const
{
	return (this->_sign);
}

int 			Form::getGrade_to_sign() const
{
	return (this->_grade_to_sign);
}

int 			Form::getGrade_to_exec() const
{
	return (this->_grade_to_exec);
}

void 			Form::beSigned(Bureaucrat &bcrat)
{
	if (this->getSign())
	{
		std::cout << bcrat.getName() << " can't sign " << this->getName() << " because ";
		throw Form::FormSignedAlreadyException();
	}
	else
	{
		if (this->getGrade_to_sign() < bcrat.getGrade())
		{
			std::cout << bcrat.getName() << " can't sign " << this->getName() << " because ";
			throw Form::GradeTooLowException();
		}
		else
		{
			this->_sign = 1;
			std::cout << bcrat.getName() << " signs " << this->getName() << std::endl;
		}
	}
	return ;
}

void			Form::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
	{
		std::cout << executor.getName() << " can't execute " << this->getName() << " because ";
		throw Form::FormNotSignedException();
	}
	else
	{
		if (this->getGrade_to_exec() < executor.getGrade())
		{
			std::cout << executor.getName() << " can't execute " << this->getName() << " because ";
			throw Form::GradeTooLowException();
		}
		else
		{
			std::cout << executor.getName() << " executes " << this->getName() << std::endl;
		}
	}
}

Form::FormSignedAlreadyException::FormSignedAlreadyException()
{
	std::cout << "the form is signed already. Nothing to do with it." << std::endl;
}

Form::FormNotSignedException::FormNotSignedException()
{
	std::cout << "the form isn't signed yet." << std::endl;
}

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "the grade is too low." << std::endl;
}

Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "the grade is too high." << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	std::string	piece;
	if (form.getSign())
		piece = "signed";
	else
		piece = "not signed";
	out << "The form " << form.getName() << " is " << piece << ". It has grade " << form.getGrade_to_sign() << " to sign and grade " << form.getGrade_to_exec() << " to execute" << std::endl;
	return (out);
}
