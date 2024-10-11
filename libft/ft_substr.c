/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:47 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:35:49 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description
 Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start > strlen - 1)
		len = 0;
	else if (start + len > strlen - 1)
		len = strlen - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
/*
int	main()
{
	char	*s;

	s = ft_substr("QWERTY", 0, 2);
	s = ft_substr("tripouille", 1, 1);
	printf("%s\n", s);
}*/
