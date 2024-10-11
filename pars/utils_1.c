/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:52 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:53 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_token(char token)
{
	if (token == '<')
	{
		printf("%s: %s\n", ERROR_NAME, IN);
		return (1);
	}
	else if (token == '>')
	{
		printf("%s: %s\n", ERROR_NAME, OUT);
		return (1);
	}
	else if (token == '|')
	{
		printf("%s: %s\n", ERROR_NAME, PIPE);
		return (1);
	}
	return (0);
}

int	validate_redirection_token(char token, int *err)
{
	if (token == '<')
	{
		ft_printf("%s: %s\n", ERROR_NAME, IN);
		*err = 2;
		return (1);
	}
	else if (token == '>')
	{
		ft_printf("%s: %s\n", ERROR_NAME, OUT);
		*err = 2;
		return (1);
	}
	return (0);
}

char	*create_error_message(char *file)
{
	char	*error;
	char	*tmp;

	error = ft_strjoin(ERROR_NAME, ": ");
	tmp = error;
	error = ft_strjoin(error, file);
	free(tmp);
	return (error);
}

char	*expand_file(char *file, t_shell_context *o)
{
	int	i;
	int	err;

	i = 0;
	while (file[i])
	{
		err = -1;
		if (file[i] == '\'')
			file = parse_for_quote(file, &i, &err);
		else if (file[i] == '"')
			file = parse_for_dquote(file, &i, o, &err);
		else if (file[i] == '$')
			file = parse_dollar(file, &i, o);
		if (!file)
			return (NULL);
		if (ft_strlen(file) == 0)
			break ;
		i++;
	}
	return (file);
}

void	free_existing_heredoc(t_shell_context *o)
{
	if (o->heredoc)
	{
		free(o->heredoc);
		o->heredoc = NULL;
	}
}
