/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:40:20 by alvutina          #+#    #+#             */
/*   Updated: 2024/08/18 11:23:36 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The  atoi()  function converts the initial portion of the string pointed
       to by nptr to int.*/
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
		sign = sign * (-1);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

// int	main()
// {
// 	char	a[] ="   -546.564 ";

// 	printf("My: %d\n", ft_atoi(a));
// 	printf("Original: %d\n", atoi(a));
// }
