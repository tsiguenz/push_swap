/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:18:18 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/15 19:32:53 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg(int argc, char **argv)
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

static t_stack	*fill_stack(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_stack *begin = malloc(sizeof(t_stack));
	t_stack	*elem1 = malloc(sizeof(t_stack));
	t_stack	*elem2 = malloc(sizeof(t_stack));

	begin->next = elem1;
	elem1->next = elem2;
	elem2->next = NULL;
	begin->value = 5;
	elem1->value = 3;
	elem2->value = -1;
	return (begin);
}

int	parsing(int argc, char **argv)
{
	t_stack	*begin;

	if (check_arg(argc, argv))
		return (1);
	begin = fill_stack(argc, argv);
	if (begin == NULL)
		return (write(1, "Error while creating the stack\n", 32));
	print_stack(begin);
	free_stack(begin);
	return (0);
}
