# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:38:08 by sben-tay          #+#    #+#              #
#    Updated: 2025/08/11 09:55:16 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -I.

SRCS := account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re