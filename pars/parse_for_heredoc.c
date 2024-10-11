/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:22 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:23 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_heredoc_result(char *res, char *limit, char *str, \
t_shell_context *o)
{
	int	result;

	result = 0;
	o->heredoc = res;
	o->is_heredoc = 1;
	if (!str)
	{
		err_msg_cmd("warning: here-document delimited by \
		end-of-file. wanted", limit);
		result = 1;
		res = NULL;
	}
	free_two_str(limit, str);
	return (result);
}

int	check_str(char *str, char *limit, char *res)
{
	if (!str)
	{
		err_msg_cmd("warning: here-document delimited by \
		end-of-file. wanted", limit);
		free_two_str(limit, res);
		return (1);
	}
	return (0);
}

int	read_heredoc_lines(char *limit, t_shell_context *o)
{
	char	*line;
	char	*tmp;
	char	*res;
	char	*line_with_n;

	free_existing_heredoc(o);
	tmp = limit;
	limit = ft_strjoin(limit, "\n");
	free(tmp);
	res = ft_strdup("");
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (line[0] != '\0' && (ft_strncmp(line, limit, ft_strlen(line)) == 0))
			break ;
		tmp = res;
		line_with_n = ft_strjoin(line, "\n");
		res = ft_strjoin(res, line_with_n);
		free_three_str(tmp, line, line_with_n);
	}
	return (process_heredoc_result(res, limit, line, o));
}

int	put_heredoc_in_file(t_shell_context *o)
{
	int		file_fd;
	char	*file_name;
	char	*tmp;

	tmp = ft_itoa(o->counter);
	file_name = ft_strjoin("/tmp/heredoc_file_", tmp);
	free(tmp);
	file_fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (handle_file_error(file_fd, file_name))
		return (1);
	write(file_fd, o->heredoc, ft_strlen(o->heredoc));
	close(file_fd);
	file_fd = open(file_name, O_RDONLY);
	if (handle_file_error(file_fd, file_name))
		return (1);
	if (o->fd_in > -1)
		close(o->fd_in);
	o->fd_in = file_fd;
	(o->counter)++;
	free(file_name);
	return (0);
}

char	*parse_heredoc(char *input, int *index, t_shell_context *o, \
int *err)
{
	char	*start;
	char	*limit;
	char	*end;
	int		i;
	int		j;

	start = setup_redirect_start(&i, index, input);
	if (check_input_validity(input, i, err))
		return (free_two_str(start, input));
	j = i;
	skip_until_token_or_space(input, &i);
	end = ft_substr(input, i, ft_strlen(input));
	end = space_remove(end);
	start[i++] = 0;
	limit = ft_strdup(start + j);
	*err = read_heredoc_lines(limit, o);
	limit = input;
	input = ft_strjoin(start, end);
	free_three_str(limit, start, end);
	if (o->heredoc)
		put_heredoc_in_file(o);
	input = check_and_free_empty_input(input);
	return (input);
}
