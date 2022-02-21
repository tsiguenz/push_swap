/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:40:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/21 10:45:03 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

# define STACK_A 0
# define STACK_B 1
# define STACK_A_B 2

typedef struct s_stack
{
	int					value;
	unsigned int		index;
	struct s_stack		*next;
}				t_stack;

int		parsing(int argc, char **argv, t_stack **a);
void	print_stack(t_stack **stack, int flag);
int		free_stack(t_stack **stack);
int		stack_is_sort(t_stack **stack);
int		stacklen(t_stack **stack);
int		set_index(t_stack **a);

/*	Authorized operations                                                     */

void	swap(t_stack **stack, int flag);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b, int flag);
void	rotate(t_stack **stack, int flag);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack, int flag);
void	rrr(t_stack **a, t_stack **b);
/*	Sorting function                                                          */

void	radix_sort(t_stack **a, t_stack **b);
void	sort_3elem(t_stack **a);
void	sort_5elem(t_stack **a, t_stack **b);
#endif
