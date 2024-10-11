/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:35:43 by meroshen          #+#    #+#             */
/*   Updated: 2024/08/19 12:03:16 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_echo(t_pipe_node *pipe, t_shell_context *o)
{
	int		sign_flag;
	int		i;
	int		sign_space;
	char	**arg;

	arg = pipe->arg;
	(void)o;
	sign_flag = 0;
	i = 1;
	while (arg[i] != NULL && ft_strcmp(arg[i], "-n") == 0)
	{
		sign_flag = 1;
		i++;
	}
	sign_space = 0;
	while (arg[i++])
	{
		if (sign_space == 1)
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(arg[i - 1], 1);
		sign_space = 1;
	}
	if (sign_flag == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}
