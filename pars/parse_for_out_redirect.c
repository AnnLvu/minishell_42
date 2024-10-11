/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_out_redirect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:33 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:34 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_for_writing(char *file, t_shell_context *o, int *err)
{
	int		fd;
	char	*error;

	file = expand_file(file, o);
	if (!file)
		return (1);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		*err = 2;
		error = create_error_message(file);
		perror(error);
		free_two_str(error, file);
		g_exit = 1;
		return (1);
	}
	free(file);
	if (o->fd_out > -1)
		close(o->fd_out);
	o->fd_out = fd;
	return (0);
}

char	*check_and_free_empty_input(char *input)
{
	if (ft_strlen(input) == 0)
	{
		free(input);
		return (NULL);
	}
	return (input);
}

int	check_input_validity(char *input, int i, int *err)
{
	if (validate_non_empty(input + i) || validate_token(input[i]))
	{
		*err = 2;
		return (1);
	}
	return (0);
}

char	*parse_out_redirect(char *input, int *index, \
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
	if (open_file_for_writing(file, o, err))
		return (free_three_str(start, input, end));
	file = input;
	input = ft_strjoin(start, end);
	free_three_str(file, start, end);
	input = check_and_free_empty_input(input);
	return (input);
}
