/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:26:33 by meroshen          #+#    #+#             */
/*   Updated: 2024/09/06 12:26:33 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_pwd(t_pipe_node *pipe, t_shell_context *o)
{
	char	*cwd;

	(void)pipe;
	(void)o;
	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	free(cwd);
	return (0);
}
