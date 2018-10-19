# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 18:09:05 by afrangio          #+#    #+#              #
#    Updated: 2018/10/20 00:48:37 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in
CC				= clang
#CFLAGS			=	-Wall	\
					-Wextra	\
					-g

CFLAGS			=	-Wall	\
					-Wextra	\
					-g -fsanitize=address	\
					-fno-omit-frame-pointer		\
					-fsanitize-address-use-after-scope
SOURCES			= srcs/*.c
INCLUDES		= includes/*.h
all: $(NAME)

$(NAME): $(SOURCES) $(INCLUDES)
	make -C libft/
	$(CC) $(CFLAGS) $(SOURCES) -Iincludes -Ilibft/includes libft/libft.a -o $(NAME)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM/

re: fclean all
