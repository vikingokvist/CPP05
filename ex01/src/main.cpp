#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"


int main() {
    try {
        Bureaucrat john("John", 50);
        Bureaucrat sarah("Sarah", 1);
        Bureaucrat mike("Mike", 150);

        std::cout << john << std::endl;
        std::cout << sarah << std::endl;
        std::cout << mike << std::endl;

        Form taxForm("Tax Form", 40, 30);
        Form passportForm("Passport Form", 1, 1);
        Form easyForm("Easy Form", 150, 150);

        std::cout << taxForm << std::endl;
        std::cout << passportForm << std::endl;
        std::cout << easyForm << std::endl;

        std::cout << "\nTrying to sign forms:\n" << std::endl;

        john.signForm(taxForm);         // Should fail (50 > 40)
        sarah.signForm(passportForm);   // Should succeed (1 <= 1)
        mike.signForm(easyForm);        // Should succeed (150 == 150)
        john.signForm(easyForm);        // Should already be signed

        std::cout << "\nAfter signing attempts:\n" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << passportForm << std::endl;
        std::cout << easyForm << std::endl;

        // Uncomment this to test invalid form grades
        // Form invalidForm("Invalid", 0, 151); // Should throw exception

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
