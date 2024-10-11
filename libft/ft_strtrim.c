/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:38 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:35:41 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/
#include "libft.h"

static int	check_set(const char *set, int c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	left;
	size_t	right;

	left = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (s1[left] && check_set(set, s1[left]))
		left++;
	right = ft_strlen(s1);
	while (right > left && check_set(set, s1[right - 1]))
		right--;
	str = malloc(right - left + 1);
	if (str)
	{
		i = 0;
		while (left < right)
			str[i++] = s1[left++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}
/*
int	main()
{
	printf("%s\n", ft_strtrim("ABCD", "A"));
	printf("%s\n", ft_strtrim("ABCD", "B"));
	printf("%s\n", ft_strtrim("ABCD", "CD"));
	printf("%s\n", ft_strtrim("ABCD", "ABCD"));
	printf("%s\n", ft_strtrim("abbcd", "abb"));
	printf("%s\n", ft_strtrim("abbcd", "abb"));
	printf("%s\n", ft_strtrim("abbabbabb", "abb"));
	printf("%s\n", ft_strtrim("abcdabb", "abb"));//kosyak
	printf("%s\n", ft_strtrim("babbhelloabb", "abb"));
	printf("%s\n", ft_strtrim("agrarfgsdfgasdab", "abb"));//kosyak
	printf("%s\n", ft_strtrim("", "abb"));
	printf("%s\n", ft_strtrim("ABCD", "ABCD"));
}*/
