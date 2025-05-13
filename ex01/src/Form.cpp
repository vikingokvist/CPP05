# include "../includes/Form.hpp"

Form::Form() : name("default"), is_signed(false), grade_signed(150), grade_executed(150) {}


Form::Form(std::string input_name, int input_grade_sign, int input_grade_exec) : 
name(input_name), is_signed(false), grade_signed(input_grade_sign), grade_executed(input_grade_exec) {

    const int grade1 = this->getSignedGrade();
    const int grade2 = this->getExecutedGrade();

    if (grade1 > 150 || grade2 > 150) {

        throw (Form::GradeTooLowException());
    }
    else if (grade1 < 1 || grade2 < 1) {

        throw (Form::GradeTooLowException());
    }
}

Form::Form(const Form& src) :
name(src.getName()), is_signed(src.getIfSigned()), grade_signed(src.getSignedGrade()), grade_executed(src.getExecutedGrade()) {

    *this = src;
}

Form& Form::operator=(const Form& src) {

    if (this == &src) {

        return (*this);
    }
	return (*this);
}

Form::~Form() {}


void                Form::beSigned(Bureaucrat& entity) {

    if (entity.getGrade() > this->getSignedGrade()) {

        throw (Bureaucrat::GradeTooLowException());
    }
    else if (this->getIfSigned() == false) {
        
        this->is_signed = true;
        std::cout << this->getName() << " Form was signed by " << entity.getName() << std::endl;
    }
    else {

        std::cout << this->getName() << " Form already signed." << std::endl;
    }
}    

const char*         Form::GradeTooHighException::what() const throw() {

	return ("Grade Too High");
}

const char*         Form::GradeTooLowException::what() const throw() {

	return ("Grade Too Low");
}

const std::string   Form::getName() const {

    return (this->name);
}

int           Form::getSignedGrade() const {

    return (this->grade_signed);
}

int           Form::getExecutedGrade() const {

    return (this->grade_executed);
}

bool                Form::getIfSigned() const {

    return (this->is_signed);
}


std::ostream&       operator<<(std::ostream& os, const Form& b) {

    os << b.getName() << std::endl
    << "\tSigned Grade: " << b.getSignedGrade() << std::endl
    << "\tExecuted Grade: " << b.getExecutedGrade() << std::endl
    << "\tSigned: " << (b.getIfSigned() ? "True" : "False") << std::endl;
    return (os);
}