/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:30:53 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 15:42:32 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
	 checks whether c is a 7-bit unsigned char value that  fits  into
              the ASCII character set.*/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("Is 'A' digit? %d\n",  ft_isascii('A'));
	printf("Is 'Z' digit? %d\n",  ft_isascii('Z'));
	printf("Is '8' digit? %d\n",  ft_isascii('8'));
	printf("Is 'a' digit? %d\n",  ft_isascii('a'));
	printf("Is '0' digit? %d\n",  ft_isascii('0'));
	printf("Is 'h' digit? %d\n",  ft_isascii('h'));
	printf("Is '5' digit? %d\n",  ft_isascii('5'));
	printf("Is '`' digit? %d\n",  ft_isascii('`'));
	printf("Is ' ' digit? %d\n",  ft_isascii(' '));
	return (0);
}*/
