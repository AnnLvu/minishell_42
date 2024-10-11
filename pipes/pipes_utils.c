/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:40:56 by meroshen          #+#    #+#             */
/*   Updated: 2024/08/27 20:17:17 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_fd_pipes(int **pipe_fds, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(pipe_fds[j]);
		j++;
	}
	free(pipe_fds);
}

void	close_all_pipes_fd(t_shell_context *o)
{
	int	i;
	int	n;

	i = 0;
	n = pipes_size(o->pipes);
	while (i < n - 1)
	{
		close(o->pipe_fds[i][0]);
		close(o->pipe_fds[i][1]);
		i++;
	}
}

int	allocate_pipe_fds(t_shell_context *o, int n)
{
	o->pipe_fds = (int **)malloc(n * sizeof(int *));
	if (!o->pipe_fds)
	{
		ft_putstr_fd("malloc error in prepare_to_exec", 2);
		return (1);
	}
	return (0);
}
