/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:50:52 by meroshen          #+#    #+#             */
/*   Updated: 2024/08/19 17:50:52 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_env(t_shell_context *o)
{
	t_env_var	*list;
	size_t		i;

	list = o->env_st;
	while (list)
	{
		if (list->value != NULL && \
			(ft_strcmp(list->key, "_") != 0) && list->sign_exp == 1)
		{
			ft_printf("declare -x %s=\"", list->key);
			i = 0;
			while ((list->value)[i])
			{
				if ((list->value)[i] == '$' || (list->value)[i] == '"')
					ft_printf("\\%c", (list->value)[i++]);
				else
					ft_printf("%c", (list->value)[i++]);
			}
			ft_printf("\"\n");
		}
		else if (list->value == NULL && \
			(ft_strcmp(list->key, "_") != 0) && list->sign_exp == 1)
			ft_printf("declare -x %s\n", list->key);
		list = list->next;
	}
}

int	exec_export(t_pipe_node *pipe, t_shell_context *o)
{
	char	**arg;

	arg = pipe->arg;
	(void)o;
	if (!arg[1])
	{
		print_export_env(o);
		return (0);
	}
	create_upd_env_st((arg + 1), o, 1);
	return (0);
}
