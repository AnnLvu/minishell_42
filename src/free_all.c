/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:32:52 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:37:06 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_struct(t_shell_context *o)
{
	t_env_var	*list;
	t_env_var	*begin;

	list = o->env_st;
	while (list)
	{
		free(list->key);
		free(list->value);
		begin = list;
		list = list->next;
		free(begin);
	}
}

void	free_env_arr(char **env_arr)
{
	int	i;

	i = 0;
	while (env_arr[i])
	{
		free(env_arr[i]);
		i++;
	}
	free(env_arr);
}

void	free_all(t_shell_context *o)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	rl_clear_history();
	if (o->heredoc)
		free(o->heredoc);
	free_env_struct(o);
	if (o->pipe_fds)
	{
		free_fd_pipes(o->pipe_fds, pipes_size(o->pipes) - 1);
		o->pipe_fds = NULL;
	}
	if (o->pipes)
	{
		free_pipes(&(o->pipes));
		o->pipes = NULL;
	}
	free(o);
}

void	close_fd(t_shell_context *o)
{
	t_pipe_node	*pipe;

	pipe = o->pipes;
	while (pipe)
	{
		if (pipe->fd_in > -1)
		{
			close (pipe->fd_in);
			pipe->fd_in = -1;
		}
		if (pipe->fd_out > -1)
		{
			close (pipe->fd_out);
			pipe->fd_out = -1;
		}
		pipe = pipe->next;
	}
}
