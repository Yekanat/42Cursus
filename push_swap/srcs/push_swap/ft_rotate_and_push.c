/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_and_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:12:03 by athekkan          #+#    #+#             */
/*   Updated: 2024/01/25 12:43:52 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function rotates both stack_a and stack_b
// in the same direction as required amount.
int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rotate_ab(a, b, 0);
		while ((*a)->nbr != c)
			ft_rotate_a(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rotate_b(b, 0);
		ft_push_b(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rotate_ab(a, b, 0);
		while ((*b)->nbr != c)
			ft_rotate_b(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rotate_a(a, 0);
		ft_push_a(a, b, 0);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_reverse_rotate_ab1(a, b, 0);
		while ((*a)->nbr != c)
			ft_reverse_rotate_a(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_reverse_rotate_b(b, 0);
		ft_push_b(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_reverse_rotate_ab1(a, b, 0);
		while ((*b)->nbr != c)
			ft_reverse_rotate_b(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_reverse_rotate_a(a, 0);
		ft_push_a(a, b, 0);
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_reverse_rotate_a(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rotate_b(b, 0);
		ft_push_b(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_reverse_rotate_a(a, 0);
		while ((*b)->nbr != c)
			ft_rotate_b(b, 0);
		ft_push_a(a, b, 0);
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_rotate_a(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_reverse_rotate_b(b, 0);
		ft_push_b(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rotate_a(a, 0);
		while ((*b)->nbr != c)
			ft_reverse_rotate_b(b, 0);
		ft_push_a(a, b, 0);
	}
	return (-1);
}
