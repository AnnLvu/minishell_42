/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_in_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:27 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:28 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_for_reading(char *file, t_shell_context *o)
{
	int		fd;
	char	*error;

	file = expand_file(file, o);
	if (!file)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error = create_error_message(file);
		perror(error);
		free_two_str(error, file);
		g_exit = 1;
		return (1);
	}
	free(file);
	if (o->fd_in > -1)
		close(o->fd_in);
	o->fd_in = fd;
	return (0);
}

char	*initialize_redirect_start(int *i, int *index, char *input)
{
	char	*start;

	*i = (*index)--;
	start = ft_strdup(input);
	start[(*i)++] = 0;
	if (input[*i] == '-' && input[*i - 1] == '<' && input[*i - 2] == '<')
		(*i)++;
	skip_leading_spaces(input, i);
	return (start);
}

char	*parse_in_redirect(char *input, int *index, \
t_shell_context *o, int *err)
{
	char	*start;
	char	*file;
	char	*end;
	int		i;
	int		j;

	start = initialize_redirect_start(&i, index, input);
	if (check_input_validity(input, i, err))
		return (free_two_str(start, input));
	j = i;
	skip_until_token_or_space(input, &i);
	end = ft_substr(input, i, ft_strlen(input));
	end = space_remove(end);
	if (validate_redirection_token(input[i], err))
		return (free_three_str(start, input, end));
	start[i++] = 0;
	file = ft_strdup(start + j);
	if (open_file_for_reading(file, o))
		return (free_three_str(start, input, end));
	file = input;
	input = ft_strjoin(start, end);
	free_three_str(file, start, end);
	input = check_and_free_empty_input(input);
	return (input);
}
