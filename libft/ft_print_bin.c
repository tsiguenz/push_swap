/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:26:37 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/08 17:59:07 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bin(char *str, char c)
{
	int	i;

	i = 0;
	write(1, str, ft_strlen(str));
	while (i < 8)
	{
		if (0x80 & c << i)
			write(1, "1 ", 2);
		else
			write(1, "0 ", 2);
		i++;
	}
	write(1, "\n", 1);
}
