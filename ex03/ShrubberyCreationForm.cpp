
#include <unistd.h>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("shrubbery creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpShrubberyCreationForm) : Form("shrubbery creation", 145, 137), _target(cpShrubberyCreationForm._target)
{
	*this = cpShrubberyCreationForm;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpShrubberyCreationForm)
{
	if (this != &cpShrubberyCreationForm)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void					ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
			std::cout << executor.getName() << " draws trees in " << this->_target << " cause of " << this->getName() << " form." << std::endl;
			this->draw();
		}
	}
	return ;
}

void 					ShrubberyCreationForm::draw(void) const
{
	std::string 	tmpfname = this->_target;
	tmpfname += "_shrubbery";
	std::ofstream 	outf(tmpfname);
	if (!outf)
	{
		std::cerr << "Sorry, but the file you've offered couldn't be opened for writing!" << std::endl;
		exit(1);
	}
	int shift;
	for (int i = 1; i <= 4; ++i)
	{
		shift = 0;
		for (int k = 0; k <= i; ++k)
		{
			int tmp = 3 - k;
			for (int j = 0; j <= tmp; ++j)
				outf << ' ';
			for (int j = 0; j <= k; ++j)
				outf << j;
			for (int j = k - 1; j >= 0; --j)
				outf << j;
			for (int z = 0; z <= 15 - shift; ++z)
				outf << ' ';
			for (int j = 0; j <= tmp; ++j)
				outf << ' ';
			for (int j = 0; j <= k; ++j)
				outf << j;
			for (int j = k - 1; j >= 0; --j)
				outf << j;
			shift++;
			outf << '\n';
		}
	}
	outf.close();
	return ;
}