/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:44 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/22 11:42:15 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	example_function(unsigned int i, char *c)
{
	(void)i;
	*c = 'X';
}

int	main()
{
	char str[] = "Hello, world!";
	ft_striteri(str, &example_function);
	printf("Modified string: %s\n", str);
	return 0;
}*/
