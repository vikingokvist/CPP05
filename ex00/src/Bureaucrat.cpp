#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string inputName, int inputGrade) : name(inputName) {

	this->setGrade(inputGrade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()) {

	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &src)  {

	if (this != &src) {

		this->grade = src.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

void	Bureaucrat::setGrade(int inputGrade) {

	if (inputGrade < 1) {
		
		throw Bureaucrat::GradeTooHighException();
	}
	else if (inputGrade > 150) {

		throw Bureaucrat::GradeTooLowException();
	}
	else {
		
		this->grade = inputGrade;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {

	return ("Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {

	return ("Grade Too Low");
}

void	Bureaucrat::incrementGrade(void) {

	this->setGrade(this->grade - 1);
}

void	Bureaucrat::decrementGrade(void) {

	this->setGrade(this->grade + 1);
}

const std::string	Bureaucrat::getName() const {

	return (this->name);
}

int	Bureaucrat::getGrade() const {

	return (this->grade);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {

	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
