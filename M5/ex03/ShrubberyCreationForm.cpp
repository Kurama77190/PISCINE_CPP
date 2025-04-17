/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:02:14 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/17 17:58:08 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ::ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
  if (this != &rhs) {
    AForm::operator=(rhs);
    this->_target = rhs._target;
  }
  return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &src) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (src.getGrade() > this->getRequiredGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream ofs(this->_target + "_shrubbery");
    if (!ofs)
    {
    std::cerr << "Error: could not open file" << std::endl;
    return;
    }
    ofs << "        _-_\n";
    ofs << "     /~~   ~~\\\n";
    ofs << "   /~~         ~~\\\n";
    ofs << "  |               |\n";
    ofs << "   \\             /\n";
    ofs << "     \\_________/\n";
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
    o << "ShrubberyCreationForm: " << i.getName()
    << ", isSigned: " << i.getIsSigned()
    << ", requiredGradeToSign: " << i.getRequiredGradeToSign()
    << ", requiredGradeToExecute: " << i.getRequiredGradeToExecute();
    return (o);
}
