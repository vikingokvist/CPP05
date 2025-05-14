# include "../includes/Form.hpp"

Form::Form() : name("default"), is_signed(false), grade_required_to_sign(150), grade_required_to_execute(150) {}


Form::Form(std::string input_name, int input_grade_sign, int input_grade_exec) : 
name(input_name), is_signed(false), grade_required_to_sign(input_grade_sign), grade_required_to_execute(input_grade_exec) {

	const int grade1 = this->getSignedGrade();
	const int grade2 = this->getExecutedGrade();

	if (grade1 > 150 || grade2 > 150) {

		throw (Form::GradeTooLowException());
	}
	else if (grade1 < 1 || grade2 < 1) {

		throw (Form::GradeTooHighException());
	}
}

Form::Form(const Form& src) :
name(src.getName()), is_signed(src.getIfSigned()), grade_required_to_sign(src.getSignedGrade()), grade_required_to_execute(src.getExecutedGrade()) {

	*this = src;
}

Form&	Form::operator=(const Form& src) {

	if (this == &src) {

		return (*this);
	}
	return (*this);
}

Form::~Form() {}


void	Form::beSigned(Bureaucrat& entity) {

	if (this->getSignedGrade() >= entity.getGrade()) {

		if (this->getIfSigned() == false) {
		
			this->is_signed = true;
			std::cout << this->getName() << " Form was signed by " << entity.getName() << std::endl;
		}
		else {

			std::cout << entity.getName() << " couldn't sign " << this->getName() << " because its already signed." << std::endl;
		}
	}
	else
		throw (Bureaucrat::GradeTooLowException());
}    

const char*	Form::GradeTooHighException::what() const throw() {

	return ("Grade Too High");
}

const char*	Form::GradeTooLowException::what() const throw() {

	return ("Grade Too Low");
}

const std::string	Form::getName() const {

	return (this->name);
}

int	Form::getSignedGrade() const {

	return (this->grade_required_to_sign);
}

int	Form::getExecutedGrade() const {

	return (this->grade_required_to_execute);
}

bool	Form::getIfSigned() const {

	return (this->is_signed);
}


std::ostream&	operator<<(std::ostream& os, const Form& b) {

	os << b.getName() << std::endl
	<< "\tSigned Grade: " << b.getSignedGrade() << std::endl
	<< "\tExecuted Grade: " << b.getExecutedGrade() << std::endl
	<< "\tSigned: " << (b.getIfSigned() ? "True" : "False") << std::endl;
	return (os);
}