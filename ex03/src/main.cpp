
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"


int main() 
{
    Intern intern;

    try 
    {
        AForm* form1 = intern.makeForm("Presidential Creation Request", "Tax evation");
        delete form1;

        AForm* form2 = intern.makeForm("Robotomy Creation Request", "Bender");
        delete form2;

        AForm* form3 = intern.makeForm("Shrubbery Creation Request", "Botanic Garden");
        delete form3;

        AForm* invalid = intern.makeForm("Loler Creation Request", "John doe");
        delete invalid;

    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}