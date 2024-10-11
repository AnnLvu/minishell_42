/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:03:08 by meroshen          #+#    #+#             */
/*   Updated: 2024/08/19 21:03:08 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*This finction delets enviromantal variable by key.
In case when  there is no variable with given key, it returns 0!*/
int	delete_env_st(char *key, t_shell_context *o)
{
	t_env_var	*list;
	t_env_var	*prev_list;

	list = o->env_st;
	prev_list = NULL;
	while (list)
	{
		if (ft_strcmp(list->key, key) == 0)
			break ;
		prev_list = list;
		list = list->next;
	}
	if (!list)
		return (0);
	if (list == o->env_st)
		o->env_st = list->next;
	else if (list != o->env_st)
		prev_list->next = list->next;
	if (list)
	{
		free(list->key);
		free(list->value);
		free(list);
	}
	return (0);
}

int	exec_unset(t_pipe_node *pipe, t_shell_context *o)
{
	int		i;
	int		res;
	char	**arg;

	arg = pipe->arg;
	i = 1;
	if (!arg[1])
		return (0);
	res = 0;
	while (arg[i])
	{
		if (!is_valid_key(arg[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			res = 1;
		}
		else
			res = delete_env_st(arg[i], o);
		i++;
	}
	return (res);
}
