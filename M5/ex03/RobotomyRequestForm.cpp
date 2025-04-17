/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:56:11 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/17 18:18:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", false, 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target){}
RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
  if (this != &rhs)
  {
    AForm::operator=(rhs);
    this->_target = rhs._target;
  }
  return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &src) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (src.getGrade() > this->getRequiredGradeToExecute())
      throw AForm::GradeTooLowException();

    std::cout << "*drilling noises*" << std::endl;
    std::srand(time(NULL));
    int random = rand() % 2;
    if (random == 0)
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << this->_target << " has failed to be robotomized." << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
  return (this->_target);
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i)
{
  o << "RobotomyRequestForm: " << i.getName() << ", target: " << i.getTarget()
    << ", is signed: " << i.getIsSigned()
    << ", required grade to sign: " << i.getRequiredGradeToSign()
    << ", required grade to execute: " << i.getRequiredGradeToExecute();
  return (o);
}
