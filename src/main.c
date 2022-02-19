/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/19 19:39:33 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : int	main(int argc, char **argv)                               */
/*                                                                            */
/*	argv = list of the value to sort.                                         */
/*                                                                            */
/******************************************************************************/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (parsing(argc, argv, &a))
		return (1);
	if (stack_is_sort(&a))
	{
		free_stack(&a);
		return (0);
	}
	print_stack(&a, STACK_A);
	set_index(&a);
	print_stack(&a, STACK_A);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
