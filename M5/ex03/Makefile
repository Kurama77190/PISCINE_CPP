# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 18:05:26 by sben-tay          #+#    #+#              #
#    Updated: 2025/04/15 19:53:27 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = INTERN

CC = c++
CLFAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -I.

SRCS := main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean rez