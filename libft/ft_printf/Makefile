# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 22:48:55 by meroshen          #+#    #+#              #
#    Updated: 2024/04/27 22:48:57 by meroshen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs
HEAD = ft_printf.h
LIBFT_PATH = ../libft/
SRC = ft_printf \
	print_char \
	print_str \
	print_int \
	print_hexadec \
	print_unsign \
	print_pointer \

SRC_LIBFT_1 = ft_strlen \
	ft_strchr \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_itoa \
	ft_calloc \
	ft_bzero \
	ft_memset \
	ft_memmove \

SRC_LIBFT = libft/ft_strlen \
	libft/ft_strchr \
	libft/ft_putchar_fd \
	libft/ft_putstr_fd \
	libft/ft_itoa \
	libft/ft_calloc \
	libft/ft_bzero \
	libft/ft_memset \
	libft/ft_memmove \


SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

SRCS_LIBFT = $(addsuffix .c, $(SRC_LIBFT))
#OBJS_LIBFT = $(addsuffix .o, $(SRC_LIBFT))
OBJS_LIBFT = $(SRCS_LIBFT_1:%.c=obj/%.o)

%.o: libft/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<	

$(NAME): $(OBJS) $(HEAD) 
#	make -C $(LIBFT_PATH)
	cp	../$(NAME_LIBFT) $(NAME)
	$(AR) $@ $(OBJS_LIBFT) $(OBJS)


all: $(NAME)

clean:
#	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)
#	rm -f $(LIBFT_PATH)$(NAME_LIBFT)

re: fclean all

bonus: all

.PHONY: all clean fclean re	
