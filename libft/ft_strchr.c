/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:42:02 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 09:42:07 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The  strchr()  function returns a pointer to the first occurrence of the
       character c in the string s.*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	to_find;

	i = 0;
	to_find = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == to_find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == to_find)
		return ((char *)s + i);
	return (0);
}
/*
#include <stdio.h>
 #include <string.h>

int	main()
{
	const char	*s = "a";
	int	c1 = 'a';
	int	c2 = 'f';
	int	c3 = '\0';

	printf("1.My: %s\n", ft_strchr(s, c1));
	printf("Original: %s\n", strchr(s, c1));

	printf("2.My: %s\n", ft_strchr(s, c2));
        printf("Original: %s\n", strchr(s, c2));

	printf("3.My: %s\n", ft_strchr(s, c3));
        printf("Original: %s\n", strchr(s, c3));
}*/
