/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:38:13 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:07 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : void	rotate(t_stack **stack, int flag)                         */
/*                                                                            */
/*	Shift up all elements of stack by 1.                                      */
/*	The first element becomes the last one.                                   */
/*                                                                            */
/******************************************************************************/

void	rotate(t_stack **stack, int flag)
{
	t_stack	*elem1;
	t_stack	*curr;

	if (stacklen(stack) < 1)
		return ;
	elem1 = *stack;
	curr = *stack;
	*stack = (*stack)->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = elem1;
	elem1->next = NULL;
	if (flag == STACK_A)
		write(1, "ra\n", 3);
	else if (flag == STACK_B)
		write(1, "rb\n", 3);
}

/******************************************************************************/
/*                                                                            */
/*	Function : void	rr(t_stack **a, t_stack **b)                              */
/*                                                                            */
/*	Do ra and rb at the same time.                                            */
/*                                                                            */
/******************************************************************************/

void	rr(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL)
		return ;
	rotate(a, STACK_A_B);
	rotate(b, STACK_A_B);
	write(1, "rr\n", 3);
}
