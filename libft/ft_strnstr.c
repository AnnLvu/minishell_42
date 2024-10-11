/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:23 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:35:25 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated
     string little in the string big, where not more than len characters are
     searched.Characters that appear after a ‘\0’ character are not searched.*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	big[] = "Hello world";
	char	little[] = "wo";

	char	*result1 = ft_strnstr(big, little, 10);
	//char	*result2 = strnstr(big, little, 7);

	printf("My: %s\n", result1);
	//printf("original %s\n", result2);
}*/
