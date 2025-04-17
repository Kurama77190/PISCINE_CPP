/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:38:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/17 17:50:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", false, 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
  if (this != &rhs)
  {
    AForm::operator=(rhs);
    this->_target = rhs._target;
  }
  return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &src) const
{
  if (this->getIsSigned() == false)
    throw AForm::FormNotSignedException();
  if (src.getGrade() > this->getRequiredGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << RED << this->_target
            << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {
  return (this->_target);
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
  o << "PresidentialPardonForm: " << i.getName()
    << ", target: " << i.getTarget() << ", is signed: " << i.getIsSigned()
    << ", required grade to sign: " << i.getRequiredGradeToSign()
    << ", required grade to execute: " << i.getRequiredGradeToExecute();
  return (o);
}
