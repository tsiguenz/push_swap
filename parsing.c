/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:18:18 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/14 20:00:32 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv)
{
	int	i;
	int	y;

	y = 1;
	if (argc == 1)
		return (1);
	while (y < argc)
	{
		i = 0;
		if (argv[y][i] == '-')
			i++;
		if (!argv[y][i])
			return (write(1, "Error\n", 6));
		while (argv[y][i])
		{
			if (!ft_isdigit(argv[y][i]))
				return (write(1, "Error\n", 6));
			i++;
		}
		y++;
	}

	return (0);
}
