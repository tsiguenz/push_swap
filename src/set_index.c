/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:15 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/19 22:31:42 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function : static void	fill_index_a(t_stack **a, t_stack **copy)         */
/*                                                                            */
/*	Fill the index of the stack a with the help of copy.                      */
/*                                                                            */
/******************************************************************************/

static void	fill_index_a(t_stack **a, t_stack **copy)
{
	t_stack	*elem_a;
	t_stack	*elem_copy;

	elem_copy = *copy;
	while (elem_copy != NULL)
	{
		elem_a = *a;
		while (elem_a != NULL)
		{
			if (elem_copy->value == elem_a->value)
			{
				elem_a->index = elem_copy->index;
				break ;
			}
			else
				elem_a = elem_a->next;
		}
		elem_copy = elem_copy->next;
	}
}

/******************************************************************************/
/*                                                                            */
/*	Function : static void	fill_index_copy(t_stack **copy)                   */
/*                                                                            */
/*	Fill the index of the stack copy.                                         */
/*                                                                            */
/******************************************************************************/

static void	fill_index_copy(t_stack **copy)
{
	t_stack				*elem;
	unsigned int		i;

	i = 1;
	elem = *copy;
	while (elem != NULL)
	{
		elem->index = i++;
		elem = elem->next;
	}
}

/******************************************************************************/
/*                                                                            */
/*	Function : static void	bubble_sort_stack(t_stack **copy)                 */
/*                                                                            */
/*	Sort the stack copy.                                                      */
/*                                                                            */
/******************************************************************************/

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

/******************************************************************************/
/*                                                                            */
/*	Function : static t_stack	*copy_stack(t_stack **stack)                  */
/*                                                                            */
/*	Create a copy of stack a.                                                 */
/*                                                                            */
/******************************************************************************/

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
			return (NULL);
		new->value = curr->value;
		new->next = NULL;
		tmp->next = new;
		tmp = new;
		curr = curr->next;
	}
	return (begin);
}

/******************************************************************************/
/*                                                                            */
/*	Function :  int	set_index(t_stack **a)                                    */
/*                                                                            */
/*	Set the index for the stack a.                                            */
/*	Create a copy of a, sort the copy, set index in copy and set the index    */
/*	in a and free the copy.                                                   */
/*                                                                            */
/******************************************************************************/

int	set_index(t_stack **a)
{
	t_stack	*copy;

	if (a == NULL)
		return (1);
	copy = copy_stack(a);
	if (copy == NULL)
		return (1);
	bubble_sort_stack(&copy);
	fill_index_copy(&copy);
	fill_index_a(a, &copy);
	return (free_stack(&copy));
}
