/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:41:11 by meroshen          #+#    #+#             */
/*   Updated: 2024/09/24 11:32:32 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_single_pipe(t_shell_context *o, int i)
{
	o->pipe_fds[i] = (int *)malloc(2 * sizeof(int));
	if (!o->pipe_fds[i])
	{
		ft_putstr_fd("malloc error in prepare_to_exec", 2);
		free_fd_pipes(o->pipe_fds, i);
		return (1);
	}
	if (pipe(o->pipe_fds[i]) == -1)
	{
		ft_putstr_fd("pipe error in prepare_to_exec", 1);
		free_fd_pipes(o->pipe_fds, i + 1);
		return (1);
	}
	return (0);
}

int	create_fd_pipes(t_shell_context *o)
{
	int	i;
	int	n;

	n = pipes_size(o->pipes) - 1;
	if (n > 0)
	{
		if (allocate_pipe_fds(o, n))
			return (1);
		i = 0;
		while (i < n)
		{
			if (create_single_pipe(o, i))
				return (1);
			i++;
		}
	}
	return (0);
}

void	save_original_pipes(t_shell_context *o)
{
	o->origin_fd_in = dup(STDIN_FILENO);
	o->origin_fd_out = dup(STDOUT_FILENO);
}

void	return_to_original_pipes(t_shell_context *o)
{
	if (o->origin_fd_in != -1)
	{
		dup2(o->origin_fd_in, STDIN_FILENO);
		close(o->origin_fd_in);
		o->origin_fd_in = -1;
	}
	if (o->origin_fd_out != -1)
	{
		dup2(o->origin_fd_out, STDOUT_FILENO);
		close(o->origin_fd_out);
		o->origin_fd_out = -1;
	}
}

void	set_pipes_fd(t_shell_context *o, int i, t_pipe_node *pipe, \
													int is_main_procs)
{
	int	n;

	n = pipes_size(o->pipes) - 1;
	if (pipe->fd_in > -1)
	{
		dup2(pipe->fd_in, STDIN_FILENO);
		close(pipe->fd_in);
		pipe->fd_in = -1;
	}
	else
		if (i != 0)
			dup2(o->pipe_fds[i - 1][0], STDIN_FILENO);
	if (pipe->fd_out > -1)
	{
		dup2(pipe->fd_out, STDOUT_FILENO);
		close(pipe->fd_out);
		pipe->fd_out = -1;
	}
	else
	{
		if (i != n)
			dup2(o->pipe_fds[i][1], STDOUT_FILENO);
	}
	if (is_main_procs != 1)
		close_all_pipes_fd(o);
}
