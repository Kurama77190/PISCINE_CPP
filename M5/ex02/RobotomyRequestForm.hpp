/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:26:05 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/16 15:14:13 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &src);
  ~RobotomyRequestForm(void);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

  void execute(Bureaucrat const &src) const;
  std::string getTarget(void) const;

private:
  std::string _target;
  RobotomyRequestForm(void);
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif
