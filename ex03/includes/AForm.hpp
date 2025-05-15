#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string   name;
		bool                is_signed;
		const int           grade_required_to_sign;
		const int           grade_required_to_execute;
	
	public:
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm& src);
		AForm& operator=(const AForm &src);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException: public std::exception {
			public:
				const char* what() const throw();
		};

		void                        beSigned(Bureaucrat& entity);
		virtual void				execute(Bureaucrat const &executor) const = 0;

		const std::string           getName() const;
		int                         getSignedGrade() const;
		int                         getExecutedGrade() const;
		bool                        getIfSigned() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif