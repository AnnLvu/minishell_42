# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 09:47:53 by alvutina          #+#    #+#              #
#    Updated: 2024/04/29 09:47:57 by alvutina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CCFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAG = crs

RM = rm -f

SRCS = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_strcmp.c 

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:.c=.o))

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CCFLAG) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) ${NAME}

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAG) $@ $^

.PHONY: all clean fclean re
