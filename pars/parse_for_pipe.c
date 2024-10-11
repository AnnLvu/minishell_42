/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:36 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:37 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_pipe_conditions(char *input, t_shell_context *o, int *err)
{
	if (!o->list && !o->is_heredoc)
	{
		ft_printf("%s: %s\n", ERROR_NAME, PIPE);
		free(input);
		*err = 2;
		return (1);
	}
	return (0);
}

int	check_for_pipe_error(char *input, int i, int *err)
{
	if (input[i] == '|')
	{
		ft_printf("%s: %s\n", ERROR_NAME, PIPE);
		free(input);
		*err = 2;
		return (1);
	}
	return (0);
}

int	check_unclosed_pipe(char *input, char *end, int *err)
{
	if (ft_strlen(end) == 0)
	{
		ft_printf("%s: %s\n", ERROR_NAME, TOKEN);
		free_two_str(input, end);
		*err = 2;
		return (1);
	}
	return (0);
}

char	*check_and_free_empty_string(char *str)
{
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*parse_pipe(char *input, int *index, t_shell_context *o, int *err)
{
	char	*str;
	char	*end;
	int		i;

	i = *index;
	str = ft_strdup(input);
	str[i++] = 0;
	if (ft_strlen(str) != 0)
		put_str_to_list(str, o);
	else
		free(str);
	if (validate_pipe_conditions(input, o, err))
		return (NULL);
	put_list_to_pipe(o);
	skip_leading_spaces(input, &i);
	if (check_for_pipe_error(input, i, err))
		return (NULL);
	end = ft_substr(input, i, ft_strlen(input));
	if (check_unclosed_pipe(input, end, err))
		return (NULL);
	*index = -1;
	free(input);
	end = check_and_free_empty_string(end);
	return (end);
}
