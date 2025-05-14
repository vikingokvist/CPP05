#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Request", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string input_target) : AForm("Shrubbery Creation Request", 145, 137), target(input_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) {

    *this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {

    if (this != &src) {

        this->target = src.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    if (executor.getGrade() >= this->getExecutedGrade()) {

        throw (Bureaucrat::GradeTooLowException());
    }
    else if (this->getIfSigned() == false) {

        throw (AForm::FormNotSignedException());
    }
    else {

        std::ofstream outfile((this->getTarget() + "_shrubbery"));
        if (!outfile) {

            std::cerr << "Failed to create " << (this->getTarget() + "_shrubbery") << " file" << std::endl;
            return ;
        }
        outfile << "                                              ." << std::endl;
        outfile << "                                   .         ;" << std::endl;
        outfile << "      .              .              ;%     ;;" << std::endl;
        outfile << "        ,           ,                :;%  %;" << std::endl;
        outfile << "         :         ;                   :;%;'     .," << std::endl;
        outfile << ",.        %;     %;            ;        %;'    ,;" << std::endl;
        outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
        outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        outfile << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        outfile << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
        outfile << "           `@%:.  :;%.         ;@@%;'" << std::endl;
        outfile << "             `@%.  `;@%.      ;@@%;" << std::endl;
        outfile << "               `@%%. `@%%    ;@@%;" << std::endl;
        outfile << "                 ;@%. :@%%  %@@%;" << std::endl;
        outfile << "                   %@bd%%%bd%%:;" << std::endl;
        outfile << "                     #@%%%%%:;;" << std::endl;
        outfile << "                     %@@%%%::;" << std::endl;
        outfile << "                     %@@@%(o);  . '" << std::endl;
        outfile << "                     %@@@o%;:(.,'" << std::endl;
        outfile << "                 `.. %@@@o%::;" << std::endl;
        outfile << "                    `)@@@o%::;" << std::endl;
        outfile << "                     %@@(o)::;" << std::endl;
        outfile << "                    .%@@@@%::;" << std::endl;
        outfile << "                    ;%@@@@%::;." << std::endl;
        outfile << "                   ;%@@@@%%:;;;." << std::endl;
        outfile << "               ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;
    }
}

std::string    ShrubberyCreationForm::getTarget() const {

    return (this->target);
}

