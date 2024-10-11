/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:34:22 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:34:25 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  calloc()  function allocates memory for an array of nmemb elements of
   size bytes each and returns a pointer to the allocated memory.  The memory
   is set to zero.  If nmemb or size is 0, then calloc() returns either NULL,
   or a unique pointer value that can later be successfully passed to free().
    If  the multiplication of nmemb and size would result in integer overflow,
   then calloc() returns an error.*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			max;
	unsigned char	*buf;
	size_t			total;

	max = (size_t) - 1;
	if (nmemb == 0 || size == 0)
		total = 1;
	else if ((max / size) < nmemb)
		return (0);
	else
		total = nmemb * size;
	buf = malloc(total);
	if (buf == 0)
		return (0);
	ft_bzero(buf, (size * nmemb));
	return (buf);
}
