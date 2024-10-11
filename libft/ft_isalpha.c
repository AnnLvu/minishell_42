/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:06:00 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/18 16:30:51 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
       checks  for an alphabetic character; in the standard "C" locale,
              it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
              cales, there may be additional characters for which isalpha() is
              true—letters which are neither uppercase nor lowercase.
	The  values  returned  are  nonzero  if  the character c falls into the
       tested class, and zero if not.*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("Is 'A' alpha? %d\n",  ft_isalpha('A'));
	printf("Is 'Z' alpha? %d\n",  ft_isalpha('Z'));
	printf("Is 'K' alpha? %d\n",  ft_isalpha('K'));
	printf("Is 'a' alpha? %d\n",  ft_isalpha('a'));
	printf("Is 'z' alpha? %d\n",  ft_isalpha('z'));
	printf("Is 'h' alpha? %d\n",  ft_isalpha('h'));
	printf("Is '5' alpha? %d\n",  ft_isalpha('5'));
	printf("Is '`' alpha? %d\n",  ft_isalpha('`'));
	printf("Is ' ' alpha? %d\n",  ft_isalpha(' '));
	return (0);
}*/
