/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:16:57 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:29 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : void	swap(t_stack **stack, int flag)                           */
/*                                                                            */
/*	Swap the first 2 elements at the top of stack.                            */
/*	Do nothing if there is only one or no elements.                           */
/*	FLag : Use define STACK_A STACK_B or STACK_A_B for print sa, sb or nothing*/
/*                                                                            */
/******************************************************************************/

void	swap(t_stack **stack, int flag)
{
	t_stack	*elem1;
	t_stack	*elem2;

	if (stacklen(stack) <= 1)
		return ;
	elem1 = *stack;
	elem2 = (*stack)->next;
	elem1->next = elem2->next;
	elem2->next = elem1;
	*stack = elem2;
	if (flag == STACK_A)
		write(1, "sa\n", 3);
	else if (flag == STACK_B)
		write(1, "sb\n", 3);
}

/******************************************************************************/
/*                                                                            */
/*	Function : void	ss(t_stack **stack_a, t_stack **stack_b)                  */
/*                                                                            */
/*	Do sa and sb at the same time.                                            */
/*                                                                            */
/******************************************************************************/

void	ss(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL)
		return ;
	swap(a, STACK_A_B);
	swap(b, STACK_A_B);
	write(1, "ss\n", 3);
}
