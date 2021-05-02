
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : virtual public Form
{
private:
	std::string	_target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(const PresidentialPardonForm &cpPresidentialPardonForm);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &cpPresidentialPardonForm);
	virtual ~PresidentialPardonForm();
	virtual void			execute(Bureaucrat const & executor) const;
};

#endif
