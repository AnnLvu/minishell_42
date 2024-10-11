/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:33:07 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:33:08 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_or_update_env_var(t_shell_context *o, t_env_var *new_var)
{
	t_env_var	*existing_var;

	existing_var = find_env_var_by_key(o->env_st, new_var->key);
	if (existing_var)
	{
		free(existing_var->value);
		existing_var->value = new_var->value;
		existing_var->sign_exp = new_var->sign_exp;
		free(new_var->key);
		free(new_var);
	}
	else
		lst_add_back(o, new_var);
}

int	handle_env_var_allocation_failure(t_env_var *new_var)
{
	free(new_var->key);
	free(new_var->value);
	free(new_var);
	return (1);
}

int	allocate_key_val(t_env_var *new_var, const char *env, \
char *equals_sign)
{
	size_t	key_len;

	if (equals_sign == NULL)
	{
		new_var->key = ft_strdup(env);
		new_var->value = NULL;
	}
	else
	{
		key_len = equals_sign - env;
		new_var->key = ft_strndup(env, key_len);
		new_var->value = ft_strdup(equals_sign + 1);
	}
	if (new_var->key == NULL || (new_var->value == NULL && equals_sign != NULL))
		return (1);
	return (0);
}

t_env_var	*parse_key_val(const char *env, t_shell_context *o, \
int sign_exp)
{
	t_env_var	*new_var;
	char		*equals_sign;

	if (env == NULL || o == NULL)
		return (NULL);
	new_var = (t_env_var *)malloc(sizeof(t_env_var));
	if (new_var == NULL)
		return (NULL);
	equals_sign = ft_strchr(env, '=');
	if (allocate_key_val(new_var, env, equals_sign))
	{
		handle_env_var_allocation_failure(new_var);
		return (NULL);
	}
	new_var->sign_exp = sign_exp;
	new_var->next = NULL;
	return (new_var);
}

void	create_upd_env_st(char **env, t_shell_context *o, int sign_exp)
{
	int			i;
	t_env_var	*new_var;

	i = 0;
	while (env[i] != NULL)
	{
		new_var = parse_key_val(env[i], o, sign_exp);
		if (new_var == NULL)
		{
			perror("malloc");
			return ;
		}
		if (new_var->key == NULL || !is_valid_key(new_var->key) \
		|| (new_var->value == NULL && ft_strchr(env[i], '=')))
		{
			perror("Error: Invalid environment variable key or value");
			free(new_var->key);
			free(new_var->value);
			free(new_var);
			return ;
		}
		add_or_update_env_var(o, new_var);
		i++;
	}
}
