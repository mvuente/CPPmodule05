
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("robotomy request", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpRobotomyRequestForm) : Form("robotomy request", 72, 45), _target(cpRobotomyRequestForm._target)
{
	*this = cpRobotomyRequestForm;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &cpRobotomyRequestForm)
{
	if (this != &cpRobotomyRequestForm)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void					RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
			std::cout << executor.getName() << " robotomizes " << this->_target << " in accordance with " << this->getName() << std::endl;
			for (int i = 0; i < 20; ++i)
			{
				std::cout << "\a";
				std::cout.flush();
				usleep(105000);
			}
		}
	}
	return ;
}
