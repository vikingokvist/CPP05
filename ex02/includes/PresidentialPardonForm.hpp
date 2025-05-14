#ifndef PRESIDENTIAL_REQUEST_FORM_HPP
# define PRESIDENTIAL_REQUEST_FORM_HPP

# include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        std::string target;

    private:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string input_target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        
        void execute(Bureaucrat const &executor) const override;
        std::string    getTarget() const;
};

#endif