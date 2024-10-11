/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:42:32 by meroshen          #+#    #+#             */
/*   Updated: 2024/05/01 19:42:36 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	utoa(unsigned int ui, int *count)
{
	int	digit;

	if (ui > 9)
	{
		digit = ui % 10;
		utoa(ui / 10, count);
		print_char('0' + digit);
		(*count)++;
	}
	if (ui <= 9)
	{
		digit = ui;
		print_char('0' + digit);
		(*count)++;
		return ;
	}
}

int	print_unsign(unsigned int ui)
{
	int		count;

	count = 0;
	utoa(ui, &count);
	return (count);
}
