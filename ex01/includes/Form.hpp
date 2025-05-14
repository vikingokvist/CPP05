#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string   name;
		bool                is_signed;
		const int           grade_required_to_sign;
		const int           grade_required_to_execute;
	
	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& src);
		Form& operator=(const Form &src);
		~Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void                        beSigned(Bureaucrat& entity);

		const std::string           getName() const;
		int                         getSignedGrade() const;
		int                         getExecutedGrade() const;
		bool                        getIfSigned() const;

		
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif