/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:19 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:20 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_env_var_key(const char *start, int i)
{
	int	j;

	j = 0;
	if (start && start[i] == '$')
		j++;
	while (start[i + j] && (ft_isalnum(start[i + j]) > 0 \
	|| start[i + j] == '_'))
	{
		j++;
	}
	return (j);
}

static char	*init_dollar(const char *start, int *i, t_shell_context *o)
{
	char	*key;
	char	*value;
	int		len_key;

	if (start[*i] == '$' && start[*i + 1] == '?')
	{
		value = ft_itoa(g_exit);
		if (!value)
			return (NULL);
		(*i) += 2;
		return (value);
	}
	len_key = len_env_var_key(start, *i);
	key = ft_strndup(start + *i + 1, len_key - 1);
	if (!key)
		return (NULL);
	value = get_env_value(key, o);
	free(key);
	if (!value)
	{
		o->is_was_dollar++;
		value = ft_strdup("");
	}
	*i += len_key;
	return (value);
}

char	*join_parts(t_join_params *params)
{
	char	*result;
	char	*end;
	char	*final_str;

	result = ft_strjoin(params->start, params->dollar_value);
	free(params->start);
	free(params->dollar_value);
	if (!result)
		return (NULL);
	end = ft_substr(params->mid, *(params->index), \
	params->orig_mid_len - *(params->index));
	free(params->mid);
	if (!end)
	{
		free(result);
		return (NULL);
	}
	if (ft_strlen(result) > 0)
		*(params->index) = ft_strlen(result) - 1;
	else
		*(params->index) = 0;
	final_str = ft_strjoin(result, end);
	free(result);
	free(end);
	return (final_str);
}

char	*get_start_and_dollar_value(char *mid, int *index, \
t_shell_context *o, char **start)
{
	char	*dollar_value;
	int		i;

	i = *index;
	*start = ft_strndup(mid, i);
	if (!(*start))
		return (NULL);
	dollar_value = init_dollar(mid, &i, o);
	if (!dollar_value)
	{
		free(*start);
		return (NULL);
	}
	*index = i;
	return (dollar_value);
}

char	*parse_dollar(char *mid, int *index, t_shell_context *o)
{
	char			*start;
	char			*dollar_value;
	int				orig_mid_len;
	t_join_params	params;

	orig_mid_len = ft_strlen(mid);
	dollar_value = get_start_and_dollar_value(mid, index, o, &start);
	if (!dollar_value)
		return (NULL);
	params.start = start;
	params.dollar_value = dollar_value;
	params.mid = mid;
	params.index = index;
	params.orig_mid_len = orig_mid_len;
	return (join_parts(&params));
}
