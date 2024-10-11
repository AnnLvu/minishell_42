/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:54 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:55 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_file_error(int fd, char *file_name)
{
	if (fd == -1)
	{
		perror("heredoc error");
		free(file_name);
		g_exit = 1;
		return (1);
	}
	return (0);
}

int	validate_non_empty(char *s)
{
	if (ft_strlen(s) == 0)
	{
		printf("%s: %s\n", ERROR_NAME, NEW);
		return (1);
	}
	return (0);
}

void	skip_leading_spaces(char *input, int *i)
{
	while (input[*i] == ' ')
		(*i)++;
}

void	skip_until_token_or_space(char *input, int *i)
{
	while (input[*i] && input[*i] != ' '
		&& input[*i] != '<' && input[*i] != '>' && input[*i] != '|')
		(*i)++;
}

void	put_str_to_list(char *str, t_shell_context *o)
{
	if (!o->list)
		o->list = ft_lstnew(str);
	else
		ft_lstadd_back(&o->list, ft_lstnew(str));
}
