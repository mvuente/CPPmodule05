
#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern &cpIntern)
{
	*this = cpIntern;
	return ;
}

Intern&	Intern::operator=(const Intern &cpIntern)
{
	if (this != &cpIntern)
		return (*this);
	return (*this);
}

Form*	Intern::makeForm(std::string fname, std::string ftarget)
{
	void**			set = new void*[4];
	std::string* 	msg = new std::string[2];

	Form* (*shrub)(std::string) = shrubForm;
	Form* (*robot)(std::string) = robotForm;
	Form* (*president)(std::string) = presidentForm;

	int 			setnum = 0;
	int 			msgnum = 0;

	Form*			resform;

	set[0] = NULL;
	set[1] = shrub(ftarget);
	set[2] = robot(ftarget);
	set[3] = president(ftarget);
	msg[1] = "Intern can't create this unknown ";
	msg[0] = "Intern creates ";
	setnum = (int)(1 - fabs(fname.compare("shrubbery creation")) / 257.0f) * 1 +
			(int)(1 - fabs(fname.compare("robotomy request")) / 257.0f) * 2 +
			(int)(1 - fabs(fname.compare("presidential pardon")) / 257.0f) * 3;
	msgnum = (int)(1 - setnum / 4.0f);
	std::cout << msg[msgnum] << fname << std::endl;
	resform = (Form *)set[setnum];
	delete[] set;
	delete[] msg;
	return (resform);
}

Form*	shrubForm(std::string ftarget)
{
	return (new ShrubberyCreationForm(ftarget));
}

Form*	robotForm(std::string ftarget)
{
	return (new RobotomyRequestForm(ftarget));
}

Form*	presidentForm(std::string ftarget)
{
	return (new PresidentialPardonForm(ftarget));
}