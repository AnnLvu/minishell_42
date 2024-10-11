/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:41:43 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 09:41:44 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The memcpy() function copies n bytes from memory area src
       to memory area dest.  The memory areas must not overlap.
  RETURN VALUE
       The memcpy() function returns a pointer to dest.*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (src == 0 && dest == 0)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
int	main(void)
{
	char	src[] = "fjero";
	char	dest[] = "seoidfhw";

	char	*result1 = ft_memcpy(dest, src, 5);
	printf("My %s\n", result1);
	char	*result2 = memcpy(dest, src, 5);
	printf("Original %s\n", result2);
	return (0);
}*/
