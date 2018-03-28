#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 21:31:26 by akupriia          #+#    #+#              #
#    Updated: 2017/12/03 21:31:26 by akupriia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fillit

SRCS = 	funcs.c \
		input_check.c \
		mapgen.c \
		mapfill.c \
		libft/ft_lstnew.c \
		libft/ft_lstpush.c \
		libft/ft_sqrt.c \
		libft/ft_strsplit.c \
		libft/ft_memcpy.c \
		libft/ft_strdup.c \
		output.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
