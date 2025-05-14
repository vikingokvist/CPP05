#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>

# include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        std::string target;

    private:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string input_target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        
        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const override;
};

#endif