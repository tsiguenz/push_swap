/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:42:21 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/08 09:26:01 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	int	ret;

	ret = 0;
	if (nb >= 0 && nb <= 9)
		ret += ft_printchar(nb + '0');
	else if (nb == -2147483648)
		ret += (int) write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ret += (int) write(1, "-", 1);
		ret += ft_printnbr(-nb);
	}
	else
	{
		ret += ft_printnbr(nb / 10);
		ret += ft_printnbr(nb % 10);
	}
	return (ret);
}

int	ft_printunsigned(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb <= 9)
		ret += ft_printchar(nb + '0');
	else
	{
		ret += ft_printnbr(nb / 10);
		ret += ft_printnbr(nb % 10);
	}
	return (ret);
}

int	ft_printnbr_base(unsigned int nb, int maj)
{
	int		ret;
	char	*base;

	ret = 0;
	if (!maj)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb <= (unsigned int)ft_strlen(base) - 1)
		ret += ft_printchar(base[nb]);
	else
	{
		ret += ft_printnbr_base(nb / ft_strlen(base), maj);
		ret += ft_printnbr_base(nb % ft_strlen(base), maj);
	}
	return (ret);
}

int	ft_printaddress(unsigned long nb)
{
	int		ret;
	char	*base;

	ret = 0;
	base = "0123456789abcdef";
	if (nb <= 15)
		ret += ft_printchar(base[nb]);
	else
	{
		ret += ft_printaddress(nb / 16);
		ret += ft_printaddress(nb % 16);
	}
	return (ret);
}

int	ft_printptr(unsigned long nb)
{
	int	ret;

	ret = 0;
	ret += ft_printstr("0x");
	ret += ft_printaddress(nb);
	return (ret);
}
