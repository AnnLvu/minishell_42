/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:44:27 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 13:59:05 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The  memchr()  function  scans  the  initial  n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and  the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;

	str = s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
		{
			return ((void *)str);
		}
		str++;
		n--;
	}
	return (0);
}
/*
int	main()
{
	const void *str = "ABCDEF";
	int c = 'i';
	size_t n = 6;

	void *result1 = ft_memchr(str, c, n);
	void *result2 = memchr(str, c, n);
	
	if (result1 != NULL)
		printf("My: %s\n", (char *)result1);
	else
		printf("My: Character not found.\n");
	if (result2 != NULL)
		printf("Original: %s\n", (char *)result2);
	else
		printf("Original: Character not found.\n");
	return 0;
}
*/
