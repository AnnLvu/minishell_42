/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:31 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:35:33 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strrchr() function returns a pointer to the last occurrence  of  the
       character c in the string s.*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	to_find;
	char	*last;
	size_t	i;

	last = (char *)s;
	to_find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == to_find)
			return (last + i);
		i--;
	}
	if (last[i] == to_find)
		return (last);
	return (0);
}
/*
int     main()
{
        const char      *s = "alerjikgheoira";
        int     c1 = 'a';
        int     c2 = 'f';
        int     c3 = '\0';

        printf("1.My: %s\n", ft_strrchr(s, c1));
        printf("Original: %s\n", strrchr(s, c1));

        printf("2.My: %s\n", ft_strrchr(s, c2));
        printf("Original: %s\n", strrchr(s, c2));

        printf("3.My: %s\n", ft_strrchr(s, c3));
        printf("Original: %s\n", strrchr(s, c3));
}
*/
