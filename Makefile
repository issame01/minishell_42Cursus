# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idryab <idryab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 15:24:25 by osabir            #+#    #+#              #
#    Updated: 2023/08/09 16:58:33 by idryab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc

INCLUDES	=	-I$(HOME)/.brew/opt/readline/include/
LIB			=	-L$(HOME)/.brew/opt/readline/lib/

FLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	minishell.c free_linked.c parsing/parsing_0.c parsing/parsing_1.c parsing/parsing_2.c \
				parsing/parsing_3.c link/link_0.c link/link_1.c link/link_2.c env/env_1.c \
				link/link_3.c link/link_4.c link/link_5.c link/link_6.c link/link_7.c env/env_0.c \
				final/final_list.c final/final_list_1.c final/final_list_2.c final/final_list_3.c \
				exec/minishell.c exec/ft_split.c exec/ft_substr.c exec/utils.c exec/ft_strcspn.c  \
				exec/exec_part1.c exec/exec_part2.c exec/run_built_ins.c exec/tools.c exec/tools2.c \
				exec/Builtin_functions/ft_cd.c exec/Builtin_functions/cd_tools.c exec/Builtin_functions/ft_echo.c \
				exec/Builtin_functions/ft_pwd.c exec/Builtin_functions/ft_env.c exec/Builtin_functions/ft_exitt.c \
				exec/Builtin_functions/ft_export/ft_export.c exec/Builtin_functions/ft_export/export_tools.c exec/Builtin_functions/ft_export/export_tools2.c \
				exec/Builtin_functions/ft_unset.c exec/err_n_exit.c

LIBFT_SRC 	= 	libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
				libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
				libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
				libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
				libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
				libft/ft_doller.c libft/ft_charjoin.c libft/ft_strstr.c libft/ft_strcmp.c libft/libft.h libft/ft_cmp_to_str.c 

OBJ			=  	$(SRC:.c=.o)
LIBFT_OBJ 	= 	$(LIBFT_SRC:.c=.o)

NAME 		= 	minishell
LIBFT 		= 	libft/libft.a

HEADERS 	= 	minishell.h

all 		: 	$(LIBFT) $(NAME)

$(LIBFT) 	: 	$(LIBFT_OBJ) 
	make -C  libft/


$(NAME) 	: 	$(OBJ) $(LIBFT) 
	$(CC) $(LIB) -lreadline -o $(NAME) $(OBJ) $(LIBFT)

%.o 		: 	%.c $(HEADERS)
	$(CC) $(INCLUDES) $(FLAGS) -c $< -o $@

clean 		: 
	rm -rf $(OBJ)
	make clean -C libft/

fclean 		: 	clean
	rm -rf $(NAME)
	make fclean -C libft/

re 			: 	fclean all