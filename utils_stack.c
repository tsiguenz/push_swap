/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:27:42 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/15 19:32:26 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *begin)
{
	t_stack	*tmp;

	tmp = begin;
	while (tmp != NULL)
	{
		ft_printf("---> %d\n", tmp->value);
		tmp = tmp->next;
	}
}

void	free_stack(t_stack *begin)
{
	t_stack	*current;
	t_stack	*next;

	current = begin;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	begin = 0;
}
