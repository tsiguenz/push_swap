/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:18:18 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/16 19:41:09 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : static t_stack	*fill_stack(int argc, char **argv)            */
/*                                                                            */
/*	This fuction fill the stack with argv. Start with argv[1].                */
/*                                                                            */
/******************************************************************************/

static t_stack	*fill_stack(int argc, char **argv)
{
	int		i;
	t_stack	*begin;
	t_stack	*new;
	t_stack	*tmp;

	i = 1;
	begin = malloc(sizeof(t_stack));
	if (!begin)
		return (NULL);
	begin->value = ft_atoi(argv[i]);
	begin->next = NULL;
	tmp = begin;
	while (++i < argc)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (begin);
		new->value = ft_atoi(argv[i]);
		new->next = NULL;
		tmp->next = new;
		tmp = new;
	}
	return (begin);
}

/******************************************************************************/
/*                                                                            */
/*	Function : static int	check_duplicate(t_stack **stack)                  */
/*                                                                            */
/*	This function check if the stack contain duplicates.                      */
/*                                                                            */
/******************************************************************************/

static int	check_duplicate(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;

	i = *stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value == j->value)
				return (write(1, "Error\n", 6));
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

/******************************************************************************/
/*                                                                            */
/*	Function : static int	check_arg_isdigit(int argc, char **argv)          */
/*                                                                            */
/*	This function check if the arguments contain digits (-0 is equal to 0).   */
/*                                                                            */
/******************************************************************************/

static int	check_arg_isdigit(int argc, char **argv)
{
	int	i;
	int	y;

	y = 1;
	i = 0;
	if (argc == 1)
		return (1);
	while (y < argc)
	{
		i = 0;
		if (argv[y][i] == '-')
			i++;
		if (!argv[y][i] || (argv[y][i] == '0' && argv[y][i + 1]))
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

/******************************************************************************/
/*                                                                            */
/*	Function : int	parsing(int argc, char **argv)                            */
/*                                                                            */
/*	Check if the arguments are correct, initialise the stack a,               */
/*	check duplicates and check if the stack is sorted.                        */
/*                                                                            */
/******************************************************************************/

int	parsing(int argc, char **argv, t_stack **a)
{
	t_stack	*first;

	if (check_arg_isdigit(argc, argv))
		return (1);
	first = fill_stack(argc, argv);
	if (first == NULL)
		return (write(1, "Error while creating the stack\n", 32));
	*a = first;
	if (check_duplicate(a))
	{
		free_stack(a);
		return (1);
	}
	return (0);
}
