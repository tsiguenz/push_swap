/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:27:42 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/18 19:13:06 by tsiguenz         ###   ########.fr       */
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

void	print_stack(t_stack **stack, int flag)
{
	t_stack	*tmp;

	tmp = *stack;
	if (flag == STACK_A)
		write(1, "Stack a :\n", 10);
	else if (flag == STACK_B)
		write(1, "Stack b :\n", 10);
	write(1, "----------\n", 11);
	while (tmp != NULL)
	{
		ft_printf("---> %d\n", tmp->value);
		tmp = tmp->next;
	}
	write(1, "----------\n", 11);
	write(1, "\n", 1);
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

/******************************************************************************/
/*                                                                            */
/*	Function : int	stack_is_sort(t_stack **stack)                            */
/*                                                                            */
/*	This function check if the stack contain duplicates.                      */
/*                                                                            */
/******************************************************************************/

int	stack_is_sort(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;

	i = *stack;
	j = i->next;
	while (j != NULL)
	{
		if (i->value > j->value)
			return (0);
		i = i->next;
		j = i->next;
	}
	return (1);
}

/******************************************************************************/
/*                                                                            */
/*	Function : int	stacklen(t_stack **stack)                                 */
/*                                                                            */
/*	Return the length of the stack.                                           */
/*                                                                            */
/******************************************************************************/

int	stacklen(t_stack **stack)
{
	int		res;
	t_stack	*current;

	res = 0;
	if (stack == NULL)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		res++;
		current = current->next;
	}
	return (res);
}
