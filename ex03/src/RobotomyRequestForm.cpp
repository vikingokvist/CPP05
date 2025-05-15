#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Creation Request", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string input_target) : AForm("Robotomy Creation Request", 145, 137), target(input_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) {

    *this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {

    if (this != &src) {

        this->target = src.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    if (executor.getGrade() >= this->getExecutedGrade()) {

        throw (Bureaucrat::GradeTooLowException());
    }
    else if (this->getIfSigned() == false) {

        throw (AForm::FormNotSignedException());
    }
    else {

        std::cout
        << "***(Drilling noises)***" << std::endl
        << "***BZRZRZRZRZRZRZRZRZRZ***" << std::endl
        << "···TRRRRRTAKAKAKAKAKAKA···" << std::endl
        << "###TZZZZRZRZRZRZRZRZRZR###" << std::endl
        << "***PEEP-PEEP-PEEP-PEEP***" << std::endl
        << "...BZRZRZRZRZRZRZRZRZRZ..." << std::endl;

        std::srand(std::time(NULL));
        int random_number = (std::rand() % 2) + 1;
        if (random_number == 2) {

            std::cout << this->getTarget() << " has been robotomized" << std::endl;
        }
        else {

            std::cout << "Robotimization failed" << std::endl;
        }
    }
}

std::string    RobotomyRequestForm::getTarget() const {

    return (this->target);
}
