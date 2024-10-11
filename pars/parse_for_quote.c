/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:39 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:40 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_error_unclosed(char *prefix, int i, char *input)
{
	if (prefix[i] == 0)
	{
		printf("%s: %s\n", ERROR_NAME, QUOTE);
		free_two_str(prefix, input);
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

char	*extract_quote_prefix(int *i, int *index, char *input)
{
	char	*start;

	*i = *index;
	start = ft_strdup(input);
	start[(*i)++] = 0;
	while (start[*i] && start[*i] != '\'')
		(*i)++;
	if (check_error_unclosed(start, *i, input))
		return (NULL);
	start[(*i)++] = 0;
	return (start);
}

char	*parse_for_quote(char *input, int *index, int *err)
{
	char	*prefix;
	char	*quoted_part;
	char	*suffix;
	char	*res;
	int		i;

	prefix = extract_quote_prefix(&i, index, input);
	if (!prefix)
	{
		*err = 2;
		return (NULL);
	}
	quoted_part = ft_strdup(prefix + *index + 1);
	res = for_norm(prefix, quoted_part);
	*index = ft_strlen(res) - 1;
	prefix = res;
	suffix = ft_substr(input, i, ft_strlen(input));
	res = ft_strjoin(res, suffix);
	free_three_str(input, prefix, suffix);
	return (res);
}
