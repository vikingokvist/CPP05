#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Creation Request", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string input_target) : AForm("Presidential Creation Request", 25, 5), target(input_target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) {

    *this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {

    if (this != &src) {

        this->target = src.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const {

    if (executor.getGrade() >= this->getExecutedGrade()) {

        throw (Bureaucrat::GradeTooLowException());
    }
    else if (this->getIfSigned() == false) {

        throw (AForm::FormNotSignedException());
    }
    else {

        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}

std::string    PresidentialPardonForm::getTarget() const {

    return (this->target);
}
