/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:33:03 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:33:04 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(n + 1);
	if (str)
	{
		i = 0;
		while (i < n && s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}

int	check_key_recursive(const char *key, size_t index)
{
	if (key[index] == '\0')
		return (1);
	if (index == 0)
	{
		if (!ft_isalpha(key[index]) && key[index] != '_')
			return (0);
	}
	else
	{
		if (!ft_isalnum(key[index]) && key[index] != '_')
		{
			return (0);
		}
	}
	return (check_key_recursive(key, index + 1));
}

int	is_valid_key(const char *key)
{
	if (key == NULL || *key == '\0')
		return (0);
	return (check_key_recursive(key, 0));
}

t_env_var	*find_env_var_by_key(t_env_var *env_list, const char *key)
{
	while (env_list != NULL)
	{
		if (ft_strcmp(env_list->key, key) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}
