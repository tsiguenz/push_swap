/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:15 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/19 19:39:19 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort_stack(t_stack **copy)
{
	int		tempvar;
	t_stack	*elem;
	t_stack	*temp;

	elem = *copy;
	while (elem != NULL)
	{
		temp = elem->next;
		while (temp != NULL)
		{
			if (elem->value > temp->value)
			{
				tempvar = elem->value;
				elem->value = temp->value;
				temp->value = tempvar;
			}
			temp = temp->next;
		}
		elem = elem->next;
	}
}

static t_stack	*copy_stack(t_stack **stack)
{
	t_stack	*begin;
	t_stack	*new;
	t_stack	*tmp;
	t_stack	*curr;

	curr = *stack;
	begin = malloc(sizeof(t_stack));
	if (!begin)
		return (NULL);
	begin->next = NULL;
	begin->value = curr->value;
	tmp = begin;
	curr = curr->next;
	while (curr != NULL)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (begin);
		new->value = curr->value;
		new->next = NULL;
		tmp->next = new;
		tmp = new;
		curr = curr->next;
	}
	return (begin);
}

void	set_index(t_stack **a)
{
	t_stack	*copy;

	if (a == NULL)
		return ;
	copy = copy_stack(a);
	bubble_sort_stack(&copy);
	print_stack(&copy, STACK_B);
}
