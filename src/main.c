/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/16 19:55:25 by tsiguenz         ###   ########.fr       */
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

	a = NULL;
	if (parsing(argc, argv, &a))
		return (1);
	if (is_sort(&a))
	{
		free_stack(&a);
		return (0);
	}
	print_stack(&a);
	free_stack(&a);
	return (0);
}
