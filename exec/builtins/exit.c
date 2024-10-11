/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:53:58 by meroshen          #+#    #+#             */
/*   Updated: 2024/09/24 12:12:29 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_atoi_long_256(const char *str)
{
	long long	num;
	int			neg;
	int			i;

	num = 0;
	neg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = num * neg;
	if (num >= 0)
		return (num % 256);
	return ((num % 256 + 256) % 256);
}

int	exec_exit(t_pipe_node *pipe, t_shell_context *o)
{
	int		exit_code;
	char	**arg;

	arg = pipe->arg;
	if (arg[1] && (str_is_num(arg[1]) == 1 || ft_strlen(arg[1]) > 18))
	{
		g_exit = 2;
		err_msg_cmd_2("exit", arg[1], "numeric argument required");
	}
	if (arg[1] && arg[2])
	{
		g_exit = 1;
		err_msg_cmd("exit", "too many arguments");
		return (1);
	}
	if (!arg || !arg[1] || g_exit == 2)
		exit_code = g_exit;
	else
		exit_code = ft_atoi_long_256(arg[1]);
	return_to_original_pipes(o);
	free_all(o);
	exit(exit_code);
	return (0);
}
