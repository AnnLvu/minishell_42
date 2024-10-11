/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:15:45 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 17:54:37 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
RETURN VALUE
       The memset() function returns a pointer to the memory area s.*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*news;
	size_t			i;

	i = 0;
	news = s;
	while (i < n)
	{
		news[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s[] = "What happend?";
	int c = 'o';

	printf("%s\n", s);
	ft_memset(s, c, 4);
	printf("%s\n", s);

	memset(s, c, 4);
	printf("%s\n", s);
}*/
