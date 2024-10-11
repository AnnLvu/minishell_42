/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:38:32 by meroshen          #+#    #+#             */
/*   Updated: 2024/08/20 15:38:32 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_home(t_shell_context *o)
{
	char		*home;
	char		*oldpwd;
	t_env_var	*env;

	env = find_env_var_by_key(o->env_st, "HOME");
	if (!env)
	{
		err_msg_cmd("cd", "HOME not set");
		return (1);
	}
	home = ft_strdup(env->value);
	oldpwd = getcwd(NULL, 0);
	if (chdir(home) != (-1))
	{
		if (set_env_st("OLDPWD", oldpwd, o->env_st) == 1)
			free(oldpwd);
		if (set_env_st("PWD", home, o->env_st) == 1)
			free(home);
	}
	else
	{
		free(home);
		free(oldpwd);
	}
	return (0);
}

int	exec_cd(t_pipe_node *pipe, t_shell_context *o)
{
	char	*path;
	char	**arg;

	arg = pipe->arg;
	if (!arg[1])
		return (cd_home(o));
	if (arg[2])
	{
		err_msg_cmd("cd", "too many arguments");
		return (1);
	}
	path = getcwd(NULL, 0);
	if (chdir(arg[1]) == -1)
	{
		err_msg_cmd_2("cd", arg[1], "No such file or directory");
		free(path);
		return (1);
	}
	set_env_st("OLDPWD", path, o->env_st);
	set_env_st("PWD", getcwd(NULL, 0), o->env_st);
	return (0);
}
