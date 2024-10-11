/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:46 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:47 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_spaces(char *input, int *index, t_shell_context *o)
{
	char	*prefix;
	char	*suffix;
	int		i;

	i = *index;
	prefix = ft_strdup(input);
	prefix[i++] = 0;
	put_str_to_list(prefix, o);
	skip_leading_spaces(input, &i);
	suffix = ft_substr(input, i, ft_strlen(input));
	free(input);
	*index = -1;
	if (ft_strlen(suffix) == 0)
	{
		free(suffix);
		suffix = NULL;
	}
	return (suffix);
}
