/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:04:27 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/13 20:20:22 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	int	ret_val;

	ret_val = 0;
	ret_val += write(1, &c, 1);
	return (ret_val);
}

int	ft_printstr(char *str)
{
	int	ret_val;
	int	len;

	ret_val = 0;
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	ret_val += (int)write(1, str, len);
	return (ret_val);
}

int	ft_printpercent(void)
{
	ft_printchar('%');
	return (1);
}
