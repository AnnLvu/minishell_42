/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:43:07 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/16 15:45:52 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION 
	checks for any printable character including space.*/
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
