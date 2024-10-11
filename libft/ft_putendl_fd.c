/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:42:42 by alvutina          #+#    #+#             */
/*   Updated: 2024/04/22 11:43:20 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the string ’s’ to the given file descriptor
followed by a newline.*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
