/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:27:42 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/16 17:21:29 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : void	print_stack(t_stack **stack)                              */
/*                                                                            */
/*	This function print the stack passed in parameter.                        */
/*                                                                            */
/******************************************************************************/

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		ft_printf("---> %d\n", tmp->value);
		tmp = tmp->next;
	}
}

/******************************************************************************/
/*                                                                            */
/*	Function : void	free_stack(t_stack **stack)                               */
/*                                                                            */
/*	This function check if the stack contain duplicates.                      */
/*                                                                            */
/******************************************************************************/

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = 0;
}
