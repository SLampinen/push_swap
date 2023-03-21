# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slampine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 09:11:49 by slampine          #+#    #+#              #
#    Updated: 2023/02/06 09:11:53 by slampine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = push_swap.c check.c stack.c actions.c init.c logic.c do_actions.c
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS) 
		cc $(CFLAGS) $(SOURCES) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJECTS)
	

fclean: clean
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re