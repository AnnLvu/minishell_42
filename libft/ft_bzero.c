/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:24:29 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/17 09:55:51 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The bzero() function erases the data in the n bytes of the memory start‐
       ing at the location pointed to by s, by writing zeros (bytes  containing
       '\0') to that area.*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
#include <strings.h>
#include <stdio.h>

int	main()
{
	char	str[16] = "ABCDEFGHIJKLMNOP";
	char	str1[16] = "ABCDEFGHIJKLMNOP";
	int	i;
	int	j;

	i = 0;
	j = 0;
	bzero(str, 5);
	ft_bzero(str1, 5);
	while (i <= 16)
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	while (j <= 16)
	{
		printf("%c", str[j]);
		j++;
	}
	printf("\n");
}*/
