/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_dollar_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:16 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:17 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(const char *key, t_shell_context *o)
{
	t_env_var	*env_var;

	env_var = find_env_var_by_key(o->env_st, key);
	if (env_var != NULL && env_var->value != NULL)
		return (ft_strdup(env_var->value));
	return (NULL);
}

char	*find_dollar(char *mid, t_shell_context *o)
{
	int		i;
	char	*new_mid;

	i = 0;
	while (mid[i])
	{
		if (mid[i] == '$' && (ft_isalnum(mid[i + 1]) || mid[i + 1] == '?'))
		{
			new_mid = parse_dollar(mid, &i, o);
			if (!new_mid)
				return (NULL);
			mid = new_mid;
		}
		else
			i++;
	}
	return (mid);
}
