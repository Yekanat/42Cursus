/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:10:08 by athekkan          #+#    #+#             */
/*   Updated: 2024/02/09 19:21:16 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Function to add a new node to the stack from back side

/*
** Custom function to add a new node to the end of a linked list (stack):
** 1. Checks if the input stack pointer is valid, returning if not.
** 2. If the stack is empty, sets the stack pointer to the new node.
** 3. If the stack is not empty, finds the last node in the stack and links
it to the new node.
*/

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}
