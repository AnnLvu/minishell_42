/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:25 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 16:05:09 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The strlen() function calculates the length of the
       string pointed to by s, excluding the terminating null byte ('\0').
       size_t - an unsigned integer data type. Used in places where
       guaranteed ability to represent all possible memory sizes
       is required.*/
#include "libft.h"
//#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	printf("Size of HKDH %zu\n", ft_strlen("HKDH"));
	printf("Size of HH %zu\n", ft_strlen("HH"));
	printf("Size of   %zu\n", ft_strlen(" "));
	printf("Size of empty  %zu\n", ft_strlen(""));
}*/
