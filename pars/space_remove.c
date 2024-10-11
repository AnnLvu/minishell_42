/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:49 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:50 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_start_spaces(char *input)
{
	int		i;
	int		length;
	char	*res;

	i = 0;
	length = ft_strlen(input);
	while (input[i] == ' ')
		i++;
	res = ft_substr(input, i, length);
	free(input);
	return (res);
}

char	*remove_end_spaces(char *input)
{
	int		length;
	char	*res;

	length = ft_strlen(input);
	while (length >= 0 && ft_strchr(" ", input[length]))
		length--;
	length++;
	input[length] = 0;
	res = ft_strdup(input);
	free(input);
	return (res);
}

char	*space_remove(char *input)
{
	input = remove_start_spaces(input);
	input = remove_end_spaces(input);
	return (input);
}
