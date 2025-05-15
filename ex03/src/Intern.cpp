#include "../includes/Intern.hpp"

Intern::Intern() {}


Intern::Intern(const Intern& src) {

    *this = src;
}

Intern& Intern::operator=(const Intern& src) {

    (void)src;
    return (*this);
}


Intern::~Intern() {}


AForm* Intern::makePresidentForm(std::string target) {

    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyForm(std::string target) {

    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyForm(std::string target) {

    return (new ShrubberyCreationForm(target));
}

AForm*  Intern::makeForm(std::string form_name, std::string form_target) {


    typedef AForm* (Intern::*formMaker)(std::string);
    
    formMaker form_ref[] = {

        &Intern::makePresidentForm, 
        &Intern::makeRobotomyForm, 
        &Intern::makeShrubberyForm
    };
    std::string forms_list[] = {

        "Presidential Creation Request", 
        "Robotomy Creation Request", 
        "Shrubbery Creation Request"
    };

    for (int i = 0; i < 3; i++) {

        if (forms_list[i] == form_name) {

            std::cout << "Intern creates " << form_name << std::endl;
            return ((this->*form_ref[i])(form_target));
        }
    }
    throw (Intern::FormDoesNotExistException());
    return (NULL);
}

const char*	Intern::FormDoesNotExistException::what() const throw() {

	return ("Form Name does not match any available");
}

