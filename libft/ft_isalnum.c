/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:51:00 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 15:26:47 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
	checks for an alphanumeric character; it is equivalent to (isal‐
              pha(c) || isdigit(c)).*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("Is 'A' alpha? %d\n",  ft_isalnum('A'));
	printf("Is 'Z' alpha? %d\n",  ft_isalnum('Z'));
	printf("Is 'a' alpha? %d\n",  ft_isalnum('a'));
	printf("Is 'z' alpha? %d\n",  ft_isalnum('z'));
	printf("Is '0' alpha? %d\n",  ft_isalnum('0'));
	printf("Is '5' alpha? %d\n",  ft_isalnum('5'));
	printf("Is '9' alpha? %d\n",  ft_isalnum('9'));
	printf("Is ' ' alpha? %d\n",  ft_isalnum(' '));
	printf("Is '`' alpha? %d\n",  ft_isalnum('`'));
}*/
