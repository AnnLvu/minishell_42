/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:17:14 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 11:08:13 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The  memmove()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas may overlap: copying takes place as  though
       the  bytes  in src are first copied into a temporary array that does not
       overlap src or dest, and the bytes are then copied  from  the  temporary
       array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*newdest;
	unsigned char const	*newsrc;
	size_t				i;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	newdest = (unsigned char *)dest;
	newsrc = (unsigned const char *)src;
	if ((size_t)newdest < (size_t)newsrc)
	{
		while ((n--) > 0)
		{
			newdest[i] = newsrc[i];
			i++;
		}
	}
	else
	{
		while ((n--) > 0)
		{
			newdest[n] = newsrc[n];
		}
	}
	return (dest);
}
/*
int	main()
{
	char	src[] = "wifdjw";
	char	dest[] = "wifdjw";

	char	*result1 = ft_memmove(dest, src, 2);
	char	*result2 = memmove(dest, src, 2);

	printf("My %s\n", result1);
	printf("Original %s\n", result2);
	}*/
