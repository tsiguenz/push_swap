/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:34:50 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:21 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : void	reverse_rotate(t_stack **stack, int flag)                 */
/*                                                                            */
/*	Shift down all elements of stack by 1.                                    */
/*	The last element becomes the first one.                                   */
/*                                                                            */
/******************************************************************************/

void	reverse_rotate(t_stack **stack, int flag)
{
	t_stack	*elem1;
	t_stack	*curr;

	if (stacklen(stack) < 1)
		return ;
	curr = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	elem1 = curr->next;
	elem1->next = *stack;
	*stack = elem1;
	curr->next = NULL;
	if (flag == STACK_A)
		write(1, "rra\n", 4);
	else if (flag == STACK_B)
		write(1, "rrb\n", 4);
}

/******************************************************************************/
/*                                                                            */
/*	Function : void	rrr(t_stack **stack_a, t_stack **stack_b)                 */
/*                                                                            */
/*	Do rra and rrb at the same time.                                          */
/*                                                                            */
/******************************************************************************/

void	rrr(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL)
		return ;
	reverse_rotate(a, STACK_A_B);
	reverse_rotate(b, STACK_A_B);
	write(1, "rrr\n", 4);
}
