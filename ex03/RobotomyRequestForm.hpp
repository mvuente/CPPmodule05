
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : virtual public Form
{
private:
	std::string	_target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(const RobotomyRequestForm &cpRobotomyRequestForm);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &cpRobotomyRequestForm);
	virtual ~RobotomyRequestForm();
	virtual void			execute(Bureaucrat const & executor) const;
};

#endif
