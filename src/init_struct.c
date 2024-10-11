/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:33:00 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:33:01 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lst_add_back(t_shell_context	*o, t_env_var *lst)
{
	t_env_var	*begin;

	if (lst == NULL)
		return (1);
	if (o->env_st == NULL)
		o->env_st = lst;
	else
	{
		begin = o->env_st;
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = lst;
	}
	return (0);
}

t_shell_context	*init_o(char **env)
{
	t_shell_context	*o;

	o = (t_shell_context *)malloc(sizeof(t_shell_context));
	if (!o)
		return (NULL);
	o->exit = 0;
	o->is_pipe = 0;
	o->env = env;
	o->env_st = NULL;
	o->heredoc = NULL;
	o->fd_in = -1;
	o->fd_out = -1;
	o->is_heredoc = 0;
	o->is_was_dollar = 0;
	o->pipe_index = 0;
	o->pipes = NULL;
	o->pipe_fds = NULL;
	o->list = NULL;
	o->pid_last_cmd = -1;
	o->counter = 0;
	o->origin_fd_in = -1;
	o->origin_fd_out = -1;
	create_upd_env_st(env, o, 1);
	return (o);
}

void	re_init_o_fd(t_shell_context *o)
{
	o->fd_in = -1;
	o->fd_out = -1;
	o->is_heredoc = 0;
	o->is_was_dollar = 0;
}
