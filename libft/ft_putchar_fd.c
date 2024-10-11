/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:39:23 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/22 11:40:24 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the character ’c’ to the given file
descriptor.*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
