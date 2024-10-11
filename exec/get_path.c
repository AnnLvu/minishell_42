/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:29:40 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:29:43 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_all_paths(t_shell_context *o)
{
	char	*path;
	char	**all_paths;

	path = get_env_value("PATH", o);
	if (!path)
		return (NULL);
	all_paths = ft_split(path, ':');
	if (path)
		free(path);
	return (all_paths);
}

char	*get_path_from_env(char *arg, t_shell_context *o)
{
	char	*tmp;
	int		i;
	char	*path;
	char	**all_paths;

	all_paths = get_all_paths(o);
	if (all_paths == NULL)
		return (NULL);
	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin("/", arg);
		path = ft_strjoin(all_paths[i], tmp);
		if (access(path, F_OK) != -1)
		{
			free(tmp);
			break ;
		}
		free(tmp);
		free(path);
		path = NULL;
		i++;
	}
	free_array(all_paths);
	return (path);
}

char	*get_path(char *arg, t_shell_context *o)
{
	char	*path;
	char	*tmp;

	if (ft_strncmp(arg, "/", 1) == 0)
	{
		path = ft_strdup(arg);
		if (access(path, F_OK) != -1)
			return (path);
		else
		{
			free (path);
			return (NULL);
		}
	}
	path = getcwd(NULL, 0);
	tmp = ft_strjoin(path, "/");
	free(path);
	path = ft_strjoin(tmp, arg);
	free(tmp);
	if (access(path, F_OK) != -1)
		return (path);
	free(path);
	path = get_path_from_env(arg, o);
	return (path);
}

/*	this function returns path and changes string str(add path to the start
	of string), that's why thare is a pointer to string str */
char	*create_path_to_cmd(char **str, t_shell_context *o)
{
	char	*cmd_with_path;

	cmd_with_path = get_path(*str, o);
	if (cmd_with_path && ft_strlen(cmd_with_path) > 0)
	{
		free(*str);
		*str = cmd_with_path;
		cmd_with_path = ft_strdup(cmd_with_path);
	}
	return (cmd_with_path);
}
