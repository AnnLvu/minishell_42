/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:01:44 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 12:21:37 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlcpy() function copies up to size - 1 characters from the NUL-ter‐
     minated string src to dst, NUL-terminating the result.*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main()
{
	char src[] = "This is a test string.";
	char dst[20];

	size_t copied = ft_strlcpy(dst, src, sizeof(dst));
	//size_t copied2 = strlcpy(dst, src, sizeof(dst));
	printf("My Copied: %zu\n", copied);
	//printf("Original: %zu\n", copied2);
	printf("Destination string: %s\n", dst);
	return 0;
}*/
