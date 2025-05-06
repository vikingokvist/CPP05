#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        std::string name;
        int     grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string inputName, int inputGrade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
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
        
        void                setName(const std::string& inputName);
        void                setGrade(int inputGrade);
        const std::string&  getName() const;
        const int&          getGrade() const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
