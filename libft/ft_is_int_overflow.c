/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:03:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/20 19:46:45 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*                                                                            */
/*	Function : int	ft_is_int_overflow(char *str)                             */
/*                                                                            */
/*	This fuction check if the string in parameter is a int overflow.          */
/*	The string need to be formated with only digits and - for negative.       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_is_int_overflow(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < -2147483648l)
		return (1);
	if (nb > 2147483647l)
		return (1);
	if (ft_strlen(str) > 12)
		return (1);
	return (0);
}
