# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 14:45:59 by acarlson          #+#    #+#              #
#    Updated: 2018/11/04 16:43:12 by acarlson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp\
		ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
		ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi\
		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower\
		\
		ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri\
		ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim\
		ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd\
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
		\
		ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
		\
		get_next_line\
		\
		ft_isprime ft_strndup ft_itoabase ft_atoibase ft_strrev ft_isin ft_wordnum\
		ft_wordlen ft_reduce ft_memrealloc ft_floor ft_ceil ft_putflt ft_putflt_fd\
		ft_putdbl ft_putdbl_fd ft_abs ft_sqrt ft_numlen ft_strlcpy ft_round ft_swap
LIB_CFILES = $(addsuffix .c, $(FILES))
LIB_OFILES = $(addsuffix .o, $(FILES))
NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(LIB_CFILES)
	@ar rc $(NAME) $(LIB_OFILES)
	@ranlib libft.a

clean:
	@/bin/rm -f $(LIB_OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
