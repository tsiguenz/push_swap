/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:48:10 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/20 17:54:38 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/
/*                                                                            */
/*	Function :  int	set_index(t_stack **a)                                    */
/*                                                                            */
/*	Set the index for the stack a.                                            */
/*                                                                            */
/******************************************************************************/

int	set_index(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;

	if (a == NULL)
		return (1);
	current = *a;
	while (current != NULL)
	{
		tmp = *a;
		while (tmp != NULL)
		{
			if (current->value > tmp->value)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}
