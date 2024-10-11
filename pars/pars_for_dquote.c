/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_for_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:06 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:07 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_error_unclosed(char *prefix, int i, char *input)
{
	if (prefix[i] == 0)
	{
		printf("%s: %s\n", ERROR_NAME, DQUOTE);
		free_two_str(input, prefix);
		return (1);
	}
	return (0);
}

static char	*for_norm(char *prefix, char *quoted_part)
{
	char	*res;

	res = ft_strjoin(prefix, quoted_part);
	free_two_str(prefix, quoted_part);
	return (res);
}

char	*extract_dquote_prefix(int *i, int *index, char *input)
{
	char	*prefix;

	*i = *index;
	prefix = ft_strdup(input);
	prefix[(*i)++] = 0;
	while (prefix[*i] && prefix[*i] != '"')
		(*i)++;
	if (check_error_unclosed(prefix, *i, input))
		return (NULL);
	prefix[(*i)++] = 0;
	return (prefix);
}

char	*parse_for_dquote(char *input, int *index, t_shell_context *o, int *err)
{
	char	*prefix;
	char	*dquoted_part;
	char	*suffix;
	char	*res;
	int		i;

	prefix = extract_dquote_prefix(&i, index, input);
	if (!prefix)
	{
		*err = 2;
		return (NULL);
	}
	dquoted_part = ft_strdup(prefix + *index + 1);
	if (ft_strchr(dquoted_part, '$'))
		dquoted_part = find_dollar(dquoted_part, o);
	res = for_norm(prefix, dquoted_part);
	*index = ft_strlen(res) - 1;
	prefix = res;
	suffix = ft_substr(input, i, ft_strlen(input));
	res = ft_strjoin(res, suffix);
	free_three_str(input, prefix, suffix);
	return (res);
}
