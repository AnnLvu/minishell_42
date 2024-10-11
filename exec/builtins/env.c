/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:14:59 by meroshen          #+#    #+#             */
/*   Updated: 2024/09/20 13:42:01 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_env(t_pipe_node *pipe, t_shell_context *o)
{
	t_env_var	*list;

	(void)pipe;
	list = o->env_st;
	while (list)
	{
		if (list->value)
		{
			ft_putstr_fd(list->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(list->value, 1);
			ft_putstr_fd("\n", 1);
		}
		list = list->next;
	}
	return (0);
}
