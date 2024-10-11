/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:42:09 by meroshen          #+#    #+#             */
/*   Updated: 2024/05/01 18:42:11 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_prefix(int i, t_info *output_flags, unsigned int *len)
{
	char	*str_res;

	if (output_flags->sign_plus && i >= 0)
	{
		str_res = ft_calloc(*len + 2, sizeof(char));
		if (!str_res)
			return (NULL);
		str_res[0] = '+';
		(*len)++;
	}
	else
		str_res = ft_calloc(*len + 1, sizeof(char));
	if (!str_res)
		return (NULL);
	return (str_res);
}

int	print_int(int i, t_info *output_flags)
{
	char			*str_int;
	char			*str_res;
	unsigned int	len;
	unsigned int	len_res;

	str_int = ft_itoa(i);
	if (!str_int)
		return (0);
	len = ft_strlen(str_int);
	str_res = create_prefix(i, output_flags, &len);
	len_res = ft_strlen(str_res);
	if (str_res != NULL && len_res > 0)
	{
		ft_memmove(str_res + ft_strlen(str_res), str_int, len);
		free(str_int);
	}
	else
	{
		if (len_res == 0)
			free(str_res);
		str_res = str_int;
	}
	ft_putstr_fd(str_res, 1);
	free(str_res);
	return (len);
}
