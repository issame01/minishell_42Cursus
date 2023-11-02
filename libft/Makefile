# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osabir <osabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:40:27 by osabir            #+#    #+#              #
#    Updated: 2023/08/05 23:56:25 by osabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			ft_strstr.c ft_strcmp.c ft_charjoin.c ft_doller.c ft_cmp_to_str.c 

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror

CC		=	 cc 

RM 		= 	rm -rf

NAME 	= 	libft.a

AR 		= 	ar -cr 

HR 		= 	libft.h

all 	: 	$(NAME) 

$(NAME) : 	$(OBJ) 
	$(AR) $(NAME) $(OBJ)

%.o 	: 	%.c $(HR)
	$(CC) $(CFLAGS) -c $< -o $@

clean 	:
	$(RM) $(OBJ)

fclean 	: 	clean 
	$(RM) $(NAME)

re		 : 	fclean all 

.PHONY 	 : 	all clean fclean re 