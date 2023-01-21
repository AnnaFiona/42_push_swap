# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ip <ip@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 12:24:01 by aplank            #+#    #+#              #
#    Updated: 2023/01/21 17:10:01 by ip               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MY_SOURCES = algorithm_utils.c algorithm.c atoi_with_int_check.c cases_threes.c checks_and_frees.c
			 functions.c get_divider_and_redirect.c help_list.c main.c mixed_bubble_sort.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@$(MAKE) bonus -C libft
	@cc $(CFLAGS) $(MY_OBJECTS) libft/libft.a -o $(NAME)
	@echo making mandatory .o files

clean:
	@$(MAKE) -C libft fclean
	@rm -f $(MY_OBJECTS)
	@echo all .o-files deleted

fclean: clean
	@rm -f push_swap
	@echo
	@echo ...and the push_swap too

re: fclean all

debug: CFLAGS += -g
debug: re