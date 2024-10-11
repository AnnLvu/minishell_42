/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:17:04 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:51 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  strdup() function returns a pointer to a new string which is a dupli‐
       cate of the string s.*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen((char *)s) + 1);
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
	}
	else
		return (0);
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*src;
	char	*copy;

	src = "hello world!";
	copy = ft_strdup(src);
	if (copy != NULL)
	{
		printf("Original: %s\n", src);
		printf("Copy: %s\n", copy);
		free(copy);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}*/
