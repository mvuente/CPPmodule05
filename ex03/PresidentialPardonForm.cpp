
#include "../ex02/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("presidential pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpPresidentialPardonForm) :
						Form("presidential pardon", 25, 5), _target(cpPresidentialPardonForm._target)
{
	*this = cpPresidentialPardonForm;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &cpPresidentialPardonForm)
{
	if (this != &cpPresidentialPardonForm)
		return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void					PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
			std::cout << executor.getName() << " declares " << this->_target << " has been pardoned by Zafod Beeblebrox based on " << this->getName() << std::endl;
		}
	}
	return ;
}
