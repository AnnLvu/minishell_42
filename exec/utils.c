/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:29:55 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:29:58 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_builtin_arrs(char **builtin_str, \
					int (**builtin_func)(t_pipe_node *pipe, t_shell_context *o))
{
	builtin_str[0] = "echo";
	builtin_str[1] = "cd";
	builtin_str[2] = "pwd";
	builtin_str[3] = "export";
	builtin_str[4] = "unset";
	builtin_str[5] = "env";
	builtin_str[6] = "exit";
	builtin_str[7] = NULL;
	builtin_func[0] = &exec_echo;
	builtin_func[1] = &exec_cd;
	builtin_func[2] = &exec_pwd;
	builtin_func[3] = &exec_export;
	builtin_func[4] = &exec_unset;
	builtin_func[5] = &exec_env;
	builtin_func[6] = &exec_exit;
}

/* set value in list of environmante variables by key.
It returns 0 on success or 1 - if the variable with this key was not found */
int	set_env_st(char *key, char *value, t_env_var *env)
{
	t_env_var	*list;
	int			res;

	list = env;
	res = 1;
	if (key && ft_strcmp(key, "") != 0 && env)
	{
		while (list)
		{
			if (ft_strcmp(key, list->key) == 0)
			{
				if (list->value)
					free(list->value);
				list->value = value;
				res = 0;
			}
			list = list->next;
		}
	}
	return (res);
}

int	str_is_num(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_listlen(t_env_var *list)
{
	int	res;

	res = 0;
	while (list)
	{
		list = list->next;
		res++;
	}
	return (res);
}

char	**create_env_arr(t_shell_context *o)
{
	char		**res;
	int			i;
	t_env_var	*list;
	char		*tmp;

	if (ft_listlen(o->env_st) == 0)
		return (NULL);
	res = (char **)malloc((ft_listlen(o->env_st) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	list = o->env_st;
	while (list)
	{
		tmp = ft_strjoin(list->key, "=");
		if (!(list->value))
			res[i] = tmp;
		else
			res[i] = ft_strjoin(tmp, list->value);
		if (list->value)
			free(tmp);
		list = list->next;
		i++;
	}
	return (res[i] = NULL, res);
}
