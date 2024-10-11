/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:37:48 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/22 11:37:55 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f.*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	length;
	unsigned int	i;

	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	my_function(unsigned int index, char c)
{
	if (index % 2 == 0) {
		return c;
	}
	else
	{
		if (c >= 'a' && c <= 'z')
		{
			return (c - 32);
		}
		else
		{
			return (c);
		}
	}
}

int	main()
{
	const char *input = "hello, world!";
	char *result = ft_strmapi(input, &my_function);
	if (result)
	{
		printf("Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Allocation error\n");
	}
	return 0;
}*/
