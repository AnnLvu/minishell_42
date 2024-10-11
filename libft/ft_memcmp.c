/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:41:31 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 09:41:33 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The  memcmp()  function  compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	const char	*s1 = "ABCD";
	const char	*s2 = "ABCE";
	size_t	n = 4;

	int	result1 = ft_memcmp(s1, s2, n);
	int	result2 = memcmp(s1, s2, n);
	printf("My: %d\n", result1);
	printf("original %d\n", result2);
}*/
