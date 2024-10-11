/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:42:31 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 09:42:32 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
 	compares only the first (at
       most) n bytes of s1 and s2.*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main()
{
	const char	s1[] = "AABBkk";
	const char	s2[] = "wuifhwoiefhowiefjo";

	printf("1.My %d\n", ft_strncmp(s1, s2, 0));
	printf("1.Original %d\n",strncmp(s1, s2, 0));

	printf("2.My %d\n", ft_strncmp(s1, s2, 4));
        printf("2.Original %d\n",strncmp(s1, s2, 4));

	printf("3.My %d\n", ft_strncmp(s1, s2, 5));
        printf("3.Original %d\n",strncmp(s1, s2, 5));

	printf("1.My %d\n", ft_strncmp(s1, s2, 8));
        printf("1.Original %d\n",strncmp(s1, s2, 8));
}*/
