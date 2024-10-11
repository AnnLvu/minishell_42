/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:08 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:35:11 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (i + 1));
	if (!join)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}
/*
 int	main()
 {
 	char	s1[] = "Sroihge";
 	char	s2[] = "hfisuhf";

 	printf("%s\n", ft_strjoin(s1, s2));
 	printf("%s\n", "second fun");
 	ft_strjoin(0, 0);
 	printf("%s\n", "thjird fun");
 	printf("%s\n", ft_strjoin(0, 0));
 	return (0);
 }*/