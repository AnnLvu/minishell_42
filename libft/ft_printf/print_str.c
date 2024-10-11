/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:50:26 by meroshen          #+#    #+#             */
/*   Updated: 2024/05/01 18:50:29 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (i);
}
