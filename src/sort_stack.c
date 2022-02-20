/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/20 19:42:39 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function :  void	radix_sort(t_stack **a, t_stack **b)                  */
/*                                                                            */
/*	Sort the stack using the index in binary.                                 */
/*	Start to the Lowest Significant Digit (LSD).                              */
/*                                                                            */
/******************************************************************************/

void	radix_sort(t_stack **a, t_stack **b)
{
	unsigned int	i;
	int				j;
	int				size;

	i = 0;
	size = stacklen(a);
	while (stack_is_sort(a) == 0 || stacklen(b) != 0)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1u) == 1u)
				rotate(a, STACK_A);
			else
				push(a, b, STACK_B);
			j++;
		}
		while (stacklen(b) != 0)
			push(a, b, STACK_A);
		i++;
	}
}
