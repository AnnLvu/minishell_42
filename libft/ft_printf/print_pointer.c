/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:46:11 by meroshen          #+#    #+#             */
/*   Updated: 2024/05/01 23:46:13 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(unsigned long ul, int *len)
{
	char	*res;

	(*len) = 0;
	while (ul != 0)
	{
		ul = ul / 16;
		(*len)++;
	}
	(*len) += 2;
	res = (char *)ft_calloc((*len) + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (res);
}

static char	convert(unsigned long ul)
{
	if (ul <= 9)
		return ((char)('0' + ul));
	else if (ul <= 16)
		return ((char)('9' + 30 + ul));
	return (' ');
}

int	print_pointer(unsigned long ul)
{
	char	*str;
	int		len;
	int		i;

	if (ul == 0)
		return (print_str("(nil)"));
	str = create_str(ul, &len);
	if (!str)
		return (0);
	i = len - 1;
	while (ul != 0)
	{
		str[i] = convert(ul % 16);
		ul = ul / 16;
		i--;
	}
	str[i] = 'x';
	str[i - 1] = '0';
	print_str(str);
	free(str);
	return ((int)len);
}
