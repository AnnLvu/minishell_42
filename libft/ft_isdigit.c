/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:30:40 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 12:49:22 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
	checks for a digit (0 through 9).*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("Is 'A' digit? %d\n",  ft_isdigit('A'));
	printf("Is 'Z' digit? %d\n",  ft_isdigit('Z'));
	printf("Is '8' digit? %d\n",  ft_isdigit('8'));
	printf("Is 'a' digit? %d\n",  ft_isdigit('a'));
	printf("Is '0' digit? %d\n",  ft_isdigit('0'));
	printf("Is 'h' digit? %d\n",  ft_isdigit('h'));
	printf("Is '5' digit? %d\n",  ft_isdigit('5'));
	printf("Is '`' digit? %d\n",  ft_isdigit('`'));
	printf("Is ' ' digit? %d\n",  ft_isdigit(' '));
	return (0);
}
*/
