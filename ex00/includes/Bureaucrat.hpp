#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int     grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string inputName, int inputGrade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        void                incrementGrade(void);
		void                decrementGrade(void);
        
        void                setGrade(int inputGrade);
        const std::string   getName() const;
        int                 getGrade() const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
