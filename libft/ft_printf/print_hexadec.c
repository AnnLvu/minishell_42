/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:40:12 by meroshen          #+#    #+#             */
/*   Updated: 2024/05/01 18:40:15 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(unsigned int ui, unsigned int *len)
{
	char	*res;

	(*len) = 0;
	while (ui != 0)
	{
		ui = ui / 16;
		(*len)++;
	}
	res = (char *)ft_calloc((*len) + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (res);
}

static char	convert(unsigned int ui, char sign)
{
	if (ui <= 9)
		return ((char)('0' + ui));
	else if (ui <= 16 && sign == 'x')
		return ((char)('9' + 30 + ui));
	else if (ui <= 16 && sign == 'X')
		return ((char)('9' - 2 + ui));
	return (' ');
}

static char	*create_prefix(char sign, t_info *output_flags)
{
	char	*res;

	if (output_flags->sign_hash == 1)
	{
		res = (char *)ft_calloc(3, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = sign;
	}
	else
		res = (char *)ft_calloc(0, 0);
	return (res);
}

int	print_hexadec(unsigned int ui, char sign, t_info *output_flags)
{
	char			*str_nbr;
	unsigned int	len;
	unsigned int	i;
	char			*str_pref;

	if (ui == 0)
		return (print_str("0"));
	str_pref = create_prefix(sign, output_flags);
	str_nbr = create_str(ui, &len);
	if (!str_nbr || !str_pref)
		return (0);
	i = len - 1;
	while (ui != 0)
	{
		str_nbr[i] = convert(ui % 16, sign);
		ui = ui / 16;
		i--;
	}
	print_str(str_pref);
	print_str(str_nbr);
	free(str_nbr);
	free(str_pref);
	return ((int)len + 2 * output_flags->sign_hash);
}
