
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : virtual public Form
{
private:
	std::string	_target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(const ShrubberyCreationForm &cpShrubberyCreationForm);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &cpShrubberyCreationForm);
	virtual ~ShrubberyCreationForm();
	virtual void			execute(Bureaucrat const & executor) const;
	void 					draw(void) const;
};


#endif
