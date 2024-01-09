# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 18:14:48 by rsaueia-          #+#    #+#              #
#    Updated: 2024/01/09 18:19:08 by rsaueia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c

OBJS = $(SRC:.c=.o)

NAME = getnextline.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
