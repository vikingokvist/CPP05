#ifndef INTERN_HPP
# define INTERN_HPP


# include "./PresidentialPardonForm.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./AForm.hpp"


class Intern
{
    public:
        Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& src);
        ~Intern();


        class FormDoesNotExistException : public std::exception {
            public:
                const char* what() const throw();
        };

        AForm*  makeForm(std::string form_name, std::string form_target);
        AForm*  makePresidentForm(std::string target);
        AForm*  makeRobotomyForm(std::string target);
        AForm*  makeShrubberyForm(std::string target);
        
};

#endif