#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>

# include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string input_target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        
        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif