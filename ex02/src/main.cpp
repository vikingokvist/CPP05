
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"


int main()
{
    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 150);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl<< std::endl;

        ShrubberyCreationForm shrubForm("Home");
        RobotomyRequestForm roboForm("Bender");
        PresidentialPardonForm pardonForm("Ford Prefect");

        try 
        {
            charlie.signAForm(shrubForm);
            std::cout << std::endl;
            charlie.executeForm(shrubForm);
            std::cout << std::endl;
        } 
        catch (std::exception &e)
        {
            std::cout << std::endl << "Exception caught: " << e.what() << std::endl;
        }
        try
        {
            bob.signAForm(shrubForm);
            std::cout << std::endl;
            bob.executeForm(shrubForm);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        try
        {
            bob.signAForm(roboForm);
            std::cout << std::endl;
            bob.executeForm(roboForm);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try
        {
            alice.executeForm(roboForm);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try
        {
            alice.signAForm(pardonForm);
            alice.executeForm(pardonForm);
            std::cout << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}