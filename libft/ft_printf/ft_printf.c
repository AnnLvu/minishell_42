/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meroshen <meroshen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:25:22 by meroshen          #+#    #+#             */
/*   Updated: 2024/04/27 22:25:25 by meroshen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(char chr, va_list *args, t_info *output_flags)
{
	int		count;

	count = 0;
	if (chr == 'c')
		count += print_char((char)va_arg(*args, int));
	if (chr == 's')
		count += print_str(va_arg(*args, char *));
	if (chr == 'i' || chr == 'd')
		count += print_int(va_arg(*args, int), output_flags);
	if (chr == 'x' || chr == 'X')
		count += print_hexadec(va_arg(*args, unsigned int), chr, output_flags);
	if (chr == 'u')
		count += print_unsign(va_arg(*args, unsigned int));
	if (chr == 'p')
		count += print_pointer(va_arg(*args, unsigned long));
	return (count);
}

static void	init_info(t_info	*output_flags)
{
	output_flags->count_space = 0;
	output_flags->sign_hash = 0;
	output_flags->sign_plus = 0;
}

static void	parsing(const char *format, va_list *args, int *count, int *i)
{
	t_info	output_flags;

	init_info(&output_flags);
	if (format[*i] == '#')
	{
		(*i)++;
		output_flags.sign_hash = 1;
	}
	while (format[*i] == ' ' && format[*i] != '\0')
	{
		(*i)++;
		output_flags.count_space++;
	}
	if (format[*i] == '+')
	{
		(*i)++;
		output_flags.sign_plus = 1;
	}
	if (ft_strchr("cspdiuxX%", format[*i]))
	{
		if (format[*i] == '%')
			*count += print_char(format[*i]);
		else
			*count += print(format[*i], args, &output_flags);
	}
}

/*
DESCRIPTION
	The function formats and output data  in standart outputs.
RETURN VALUE
	None.
*/
int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			parsing(format, &args, &count, &i);
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
