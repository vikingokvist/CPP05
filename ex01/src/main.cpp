#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"


int main(void)
{
    try {

        Bureaucrat john("John", 50);
        Bureaucrat sarah("Sarah", 1);
        Bureaucrat mike("Mike", 150);

        std::cout << john << std::endl;
        std::cout << sarah << std::endl;
        std::cout << mike << std::endl << std::endl;

        Form taxForm("Tax", 51, 30);
        Form passportForm("Passport", 1, 1);
        Form easyForm("Easy", 150, 150);

        std::cout << taxForm << std::endl;
        std::cout << passportForm << std::endl;
        std::cout << easyForm << std::endl;

        std::cout << "\nTrying to sign forms:\n" << std::endl;

        john.signForm(taxForm);
        sarah.signForm(passportForm);
        mike.signForm(easyForm);
        john.signForm(easyForm);

        std::cout << "\nAfter signing attempts:\n" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << passportForm << std::endl;
        std::cout << easyForm << std::endl;


        // Form invalidForm("Invalid", 0, 151); // Should throw exception

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
