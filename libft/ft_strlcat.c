/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:52:53 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 13:14:33 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlcat() function appends the NUL-terminated string src to the end of
     dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
     the result.*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	result = ft_strlen(src);
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	j = i;
	if (size != 0)
	{
		while (*src && i < size - 1)
		{
			*dst = *src;
			i++;
			src++;
			dst++;
		}
	}
	if (i < size)
		*dst = '\0';
	return (j + result);
}
/*
int main()
{
    char dst[20] = "Hello, ";
    char src[] = "world!";
    size_t size = sizeof(dst);

    printf("Before strlcat: %s\n", dst);
    printf("Result of strlcat: %zu\n", ft_strlcat(dst, src, size));
    printf("After strlcat: %s\n", dst);

    return 0;
}*/
