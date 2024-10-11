/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:34:24 by meroshen          #+#    #+#             */
/*   Updated: 2024/05/02 11:34:25 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

typedef struct s_info
{
	int	sign_hash;
	int	count_space;
	int	sign_plus;
}	t_info;

int	ft_printf(const char *format, ...);
int	print_char(char chr);
int	print_str(char *str);
int	print_int(int i, t_info *output_flags);
int	print_hexadec(unsigned int ui, char sign, t_info *output_flags);
int	print_unsign(unsigned int ui);
int	print_pointer(unsigned long ui);

#endif