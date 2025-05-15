# include "../includes/AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_required_to_sign(150), grade_required_to_execute(150) {}


AForm::AForm(std::string input_name, int input_grade_sign, int input_grade_exec) : 
name(input_name), is_signed(false), grade_required_to_sign(input_grade_sign), grade_required_to_execute(input_grade_exec) {

	const int grade1 = this->getSignedGrade();
	const int grade2 = this->getExecutedGrade();

	if (grade1 > 150 || grade2 > 150) {

		throw (AForm::GradeTooLowException());
	}
	else if (grade1 < 1 || grade2 < 1) {

		throw (AForm::GradeTooHighException());
	}
}

AForm::AForm(const AForm& src) :
name(src.getName()), is_signed(src.getIfSigned()), grade_required_to_sign(src.getSignedGrade()), grade_required_to_execute(src.getExecutedGrade()) {

	*this = src;
}

AForm&	AForm::operator=(const AForm& src) {

	if (this == &src) {

		return (*this);
	}
	return (*this);
}

AForm::~AForm() {}


void	AForm::beSigned(Bureaucrat& entity) {

	if (this->getSignedGrade() >= entity.getGrade()) {

		if (this->getIfSigned() == false) {
		
			this->is_signed = true;
			std::cout << this->getName() << " AForm was signed by " << entity.getName() << std::endl;
		}
		else {

			std::cout << entity.getName() << " couldn't sign " << this->getName() << " because its already signed." << std::endl;
		}
	}
	else
		throw (Bureaucrat::GradeTooLowException());
}    

const char*	AForm::FormNotSignedException::what() const throw() {

	return ("Form Not Signed");
}

const char*	AForm::GradeTooHighException::what() const throw() {

	return ("Grade Too High");
}

const char*	AForm::GradeTooLowException::what() const throw() {

	return ("Grade Too Low");
}

const std::string	AForm::getName() const {

	return (this->name);
}

int	AForm::getSignedGrade() const {

	return (this->grade_required_to_sign);
}

int	AForm::getExecutedGrade() const {

	return (this->grade_required_to_execute);
}

bool	AForm::getIfSigned() const {

	return (this->is_signed);
}


std::ostream&	operator<<(std::ostream& os, const AForm& b) {

	os << b.getName() << std::endl
	<< "\tSigned Grade: " << b.getSignedGrade() << std::endl
	<< "\tExecuted Grade: " << b.getExecutedGrade() << std::endl
	<< "\tSigned: " << (b.getIfSigned() ? "True" : "False") << std::endl;
	return (os);
}