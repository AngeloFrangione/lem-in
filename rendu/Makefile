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

NAME			=	lem-in
CC				=	clang
CFLAGS			=	-Wall	\
					-Wextra	\
					-Werror
#CFLAGS			=	-Wall	\
					-Wextra	\
					-g -fsanitize=address	\
					-fno-omit-frame-pointer		\
					-fsanitize-address-use-after-scope

SOURCES			=	errors.c \
					find_path.c \
					main.c \
					node.c \
					parsing.c \
					run_through.c \
					tools_algo.c \
					tools_ants.c \
					tools_comments.c \
					tools_common.c \
					tools_links.c \
					tools_printants.c \
					tools_rooms.c \

INCLUDES		=	includes/lem_in.h

SRCS = $(addprefix srcs/, $(SOURCES))

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	make -C libft/
	$(CC) $(CFLAGS) $(SRCS) -Iincludes -Ilibft/includes libft/libft.a -o $(NAME)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM/

re: fclean all
