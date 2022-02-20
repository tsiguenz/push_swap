/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/20 22:20:08 by tsiguenz         ###   ########.fr       */
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
	int		size;

	a = NULL;
	b = NULL;
	size = stacklen(&a);
	if (parsing(argc, argv, &a) || stack_is_sort(&a) || set_index(&a))
		return (free_stack(&a));
//	print_stack(&a, STACK_A);
	else if (size <= 3)
		sort_3elem(&a, size);
//	else if (size <= 5)
//		sort_5elem(&a, &b);
	else if (size > 5)
		radix_sort(&a, &b);
//	print_stack(&a, STACK_A);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
