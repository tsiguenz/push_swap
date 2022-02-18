/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:28:37 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/18 17:43:27 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : void	push(t_stack **a, t_stack **b, int flag)                  */
/*                                                                            */
/*	Take the first element at the top of b and put it at the top of a.        */
/*	Do nothing if b is empty.                                                 */
/*	Do the opposite if flag == 1.                                             */
/*                                                                            */
/******************************************************************************/

void	push(t_stack **a, t_stack **b, int flag)
{
	t_stack	*elem1;

	if ((flag == STACK_A && *b == NULL) || (flag == STACK_B && *a == NULL))
		return ;
	if (flag == STACK_A)
	{
		elem1 = *b;
		*b = (*b)->next;
		elem1->next = *a;
		*a = elem1;
		write(1, "pa\n", 3);
	}
	else if (flag == STACK_B)
	{
		elem1 = *a;
		*a = (*a)->next;
		elem1->next = *b;
		*b = elem1;
		write(1, "pb\n", 3);
	}
}
