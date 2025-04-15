#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
public:
	AForm( std::string name, bool isSigned, int toSigne, int Execute );
	AForm ( const AForm & src );
	~AForm( void );
	AForm & operator=( AForm const & rhs );

	std::string	getName( void ) const;
	bool		getIsSigned( void ) const;
	int			getRequiredGradeToSign( void ) const;
	int			getRequiredGradeToExecute( void ) const;

	void			beSigned(const Bureaucrat & src);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high!";
		}
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too low!";
		}
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Form is not signed!";
			}
	};

private:

const std::string	_name;
bool				_isSigned;
const int			_requiredGradeToSign;
const int			_requiredGradeToExecute;

};

std::ostream & operator<<( std::ostream & o, AForm const & i );

#endif