/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/20 21:12:41 by tsiguenz         ###   ########.fr       */
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
	if (parsing(argc, argv, &a) || stack_is_sort(&a) || set_index(&a))
		return (free_stack(&a));
//	print_stack(&a, STACK_A);
	radix_sort(&a, &b);
//	print_stack(&a, STACK_A);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
