#include "Bureaucrat.hpp"

int main(void)
{
//---------------------------------------------------------------------------------
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

    }
    catch (const Bureaucrat::GradeTooHighException& error)
    {
        std::cerr << "Caught exception: " << error.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& error)
    {
        std::cerr << "Caught exception: " << error.what() << std::endl;
    }
//---------------------------------------------------------------------------------
    std::cout << "\n---\n" << std::endl;
//---------------------------------------------------------------------------------
    try
    {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << "After another decrement: " << b2 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& error)
    {
        std::cerr << "Caught exception: " << error.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& error)
    {
        std::cerr << "Caught exception: " << error.what() << std::endl;
    }
//---------------------------------------------------------------------------------
    return (0);
}
