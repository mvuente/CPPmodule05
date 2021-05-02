
#ifndef INTERN_HPP
#define INTERN_HPP

#include <cmath>
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	virtual ~Intern();
	Intern(const Intern &cpIntern);
	Intern			&operator=(const Intern &cpIntern);
	Form*			makeForm(std::string fname, std::string ftarget);
};
Form*				shrubForm(std::string ftarget);
Form*				robotForm(std::string ftarget);
Form*				presidentForm(std::string ftarget);

#endif
