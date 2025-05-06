#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {

	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {

    if (this != &other) {

        this->name = other.name;
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string inputName, int inputGrade) {

    this->setName(inputName);
    this->setGrade(inputGrade);

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

void    Bureaucrat::setName(const std::string& inputName) {

    name = inputName;
}

void    Bureaucrat::setGrade(int inputGrade) {

    if (inputGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (inputGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = inputGrade;
}


const std::string& Bureaucrat::getName() const {

    return (name);
}

const int&         Bureaucrat::getGrade() const {

    return (grade);
}

void    Bureaucrat::incrementGrade(void) {

    this->setGrade(this->grade - 1);
}

void    Bureaucrat::decrementGrade(void) {

    this->setGrade(this->grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {

    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
