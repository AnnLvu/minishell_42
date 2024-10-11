# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 11:33:34 by alvutina          #+#    #+#              #
#    Updated: 2024/09/24 11:33:35 by alvutina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	src/main.c\
			src/key_value.c\
			src/key_value_2.c\
			src/list.c\
			src/init_struct.c\
			pars/pars.c\
			pars/for_pipe.c\
			pars/free.c\
			pars/pars_for_dquote.c\
			pars/parse_for_dollar.c\
			pars/parse_for_dollar_2.c\
			pars/parse_for_in_redirect.c\
			pars/parse_for_heredoc.c\
			pars/parse_for_out_redirect.c\
			pars/pars_for_reredirect.c\
			pars/parse_for_pipe.c\
			pars/parse_for_quote.c\
			pars/parse_for_redirects_global.c\
			pars/parse_for_space.c\
			pars/utils_1.c\
			pars/utils_2.c\
			pars/space_remove.c\
			src/free_all.c\
			exec/utils.c\
			exec/utils2.c\
			exec/get_path.c\
			exec/exec.c\
			exec/builtins/echo.c\
			exec/builtins/cd.c\
			exec/builtins/pwd.c\
			exec/builtins/export.c\
			exec/builtins/unset.c\
			exec/builtins/env.c\
			exec/builtins/exit.c\
			pipes/pipes_utils.c\
			pipes/pipes.c\




OBJS_DIR =	obj
OBJS	=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDE	=	include/
LIB_PATH	=	usr/lib/
HEADER	=	minishell.h

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE) -g
LDFLAGS	=	-L$(LIB_PATH) -lreadline

CC	=	cc

LIB		=	libft/libft.a
FT_PRINTF_LIB = libft/ft_printf/libftprintf.a

all: $(LIB) $(FT_PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(FT_PRINTF_LIB) $(LDFLAGS) -o $@


$(LIB):
	@make -C libft

$(FT_PRINTF_LIB):
	@make -C libft/ft_printf

$(OBJS_DIR)/%.o: %.c $(INCLUDE)$(HEADER)
	@mkdir -p $(OBJS_DIR)/$(dir $<)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@make $@ -C libft
	@make $@ -C libft/ft_printf
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
