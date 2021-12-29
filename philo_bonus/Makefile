# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prranges <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 13:58:50 by prranges          #+#    #+#              #
#    Updated: 2021/10/11 13:58:52 by prranges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo_bonus

SRCS	= philo_bonus.c\
		  parse_bonus.c \
		  semaphores_bonus.c \
		  print_bonus.c \
		  utils_bonus.c

CC	= gcc
CFLAGS 	= -Wall -Wextra -Werror -pthread

RM	= rm -rf

OBJS_DIR 	= temp

OBJS	= $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

HDR	= -I./

all: $(NAME)

$(OBJS_DIR):
	mkdir $@

$(OBJS_DIR)/%.o: %.c Makefile $(OBJS_DIR)
	gcc -g $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJS) ./philo_bonus.h
	gcc -g $(OBJS) -o $@

clean:
	$(RM) $(OBJS_DIR)

bonus:	re
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

