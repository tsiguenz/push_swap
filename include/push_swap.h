/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:40:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/02/16 15:51:54 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
//	struct s_stack	*head;
//	struct s_stack	*tail;
}				t_stack;

int		parsing(int argc, char **argv);
void	print_stack(t_stack **stack);
void	free_stack(t_stack **stack);
#endif
