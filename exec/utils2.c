/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:30:08 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:40:19 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_msg_cmd(char *command, char *error_message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (command != NULL)
	{
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(error_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	err_msg_cmd_2(char *command, char *var, char *error_message)
{
	char	*str;
	char	*str_;

	str = ft_strjoin(var, ": ");
	if (!str)
	{
		g_exit = ENOMEM;
		return ;
	}
	str_ = ft_strjoin(str, error_message);
	free(str);
	if (!str_)
	{
		g_exit = ENOMEM;
		return ;
	}
	err_msg_cmd(command, str_);
	free(str_);
}

int	run_builtin_single(t_pipe_node *pipe, int j, t_shell_context *o, \
				int (*builtin_func)(t_pipe_node *, t_shell_context *))
{
	int	res;

	save_original_pipes(o);
	set_pipes_fd(o, j, pipe, 1);
	res = (*builtin_func)(pipe, o);
	return_to_original_pipes(o);
	return (res);
}
