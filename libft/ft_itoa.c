/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:45:34 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/22 12:17:13 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.*/
#include "libft.h"

size_t	ft_count_nb_len(int nb)
{
	int	length;

	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		length++;
	while (nb)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;
	long	number;

	length = ft_count_nb_len(n);
	number = n;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	if (number == 0)
		str[0] = '0';
	str[length--] = '\0';
	while (number)
	{
		str[length] = number % 10 + '0';
		length--;
		number = number / 10;
	}
	return (str);
}
/*
int	main()
{
	printf("My: %s\n", ft_itoa(-2147483648));
}*/
