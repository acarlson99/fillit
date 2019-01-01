# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/20 17:03:10 by callen            #+#    #+#              #
#    Updated: 2019/01/01 15:38:52 by acarlson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
DNAME = d_$(NAME)

SRCDIR = srcs/
SRCS =	main.c check_errs.c lst_functions.c solve_box.c map_funcs.c
OBJ = $(SRCS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -g
CINC = -I libft/ -I includes/
LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(CINC) $(LIBFT) $(OBJ) -o $(NAME)

$(OBJ): %.o: $(addprefix $(SRCDIR), %.c)
	@$(CC) $(CFLAGS) $(CINC) -c $< -o $@

debug:
	@make -C libft
	@$(CC) $(DFLAGS) $(CINC) $(LIBFT) $(SRCS) -o $(DNAME)

memdbg:
	@make -C libft
	@$(CC) $(DFLAGS) -fsanitize=address $(CINC) $(LIBFT) $(SRCS) -o $(DNAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

dclean:
	@/bin/rm -rf $(DNAME) $(DNAME).dSYM/ $(DBJ)

re: fclean $(NAME)

relib:
	@make -C libft re

.PHONY: all debug memdbg clean dclean fclean re relib
