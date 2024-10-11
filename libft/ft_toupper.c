/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:26 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 16:11:57 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*These functions convert lowercase letters to uppercase*/
#include "libft.h"

int	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main()
{
	printf("Transfer 'C' %c\n", ft_toupper('C'));
	printf("Transfer 'a' %c\n", ft_toupper('a'));
}*/
