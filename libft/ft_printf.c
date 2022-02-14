/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:22:49 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/14 16:08:30 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(char *format, va_list *arg)
{
	int	count_print;

	count_print = 0;
	if (*format == 'c')
		count_print += ft_printchar((char)va_arg(*arg, int));
	else if (*format == 's')
		count_print += ft_printstr((char *)va_arg(*arg, void *));
	else if (*format == 'd' || *format == 'i')
		count_print += ft_printnbr(va_arg(*arg, int));
	else if (*format == 'u')
		count_print += (unsigned int) ft_printunsigned(va_arg(*arg, int));
	else if (*format == 'x')
		count_print += ft_printnbr_base(va_arg(*arg, unsigned int), 0);
	else if (*format == 'X')
		count_print += ft_printnbr_base(va_arg(*arg, unsigned int), 1);
	else if (*format == '%')
		count_print += ft_printpercent();
	else if (*format == 'p')
		count_print += ft_printptr(va_arg(*arg, unsigned long int));
	else
		count_print += ft_printchar(*format);
	return (count_print);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret_val;
	va_list	arg;

	i = 0;
	ret_val = 0;
	if (!format)
		return (0);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			ret_val += ft_parser((char *)(format + ++i), &arg);
		else
			ret_val += ft_printchar(format[i]);
		i++;
	}
	va_end(arg);
	return (ret_val);
}
