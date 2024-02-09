/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:12:53 by athekkan          #+#    #+#             */
/*   Updated: 2024/01/25 11:44:44 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function sort the stack if there are only 
// three elements in the stack.
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_reverse_rotate_a(stack_a, 0);
		ft_swap_a(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_rotate_a(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			ft_swap_a(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_reverse_rotate_a(stack_a, 0);
		else
			ft_swap_a(stack_a, 0);
	}
}
