#ifndef SHRUBERY_CREATION_FORM_HPP
# define SHRUBERY_CREATION_FORM_HPP

# include <fstream>

# include "./AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string input_target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
        std::string     getTarget() const;
};

#endif
