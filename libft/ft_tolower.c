/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:12:14 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 16:15:13 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Convert character to lowercase*/
#include "libft.h"

int	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main()
{
	printf("Transfer 'C' %c\n", ft_tolower('C'));
	printf("Transfer 'a' %c\n", ft_tolower('a'));
}*/
