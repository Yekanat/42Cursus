/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:12:14 by athekkan          #+#    #+#             */
/*   Updated: 2024/02/06 18:18:15 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from B to A.
int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = ft_count_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > ft_count_rarb_a(a, b, tmp->nbr))
			i = ft_count_rarb_a(a, b, tmp->nbr);
		if (i > ft_count_rrarrb_a(a, b, tmp->nbr))
			i = ft_count_rrarrb_a(a, b, tmp->nbr);
		if (i > ft_count_rarrb_a(a, b, tmp->nbr))
			i = ft_count_rarrb_a(a, b, tmp->nbr);
		if (i > ft_count_rrarb_a(a, b, tmp->nbr))
			i = ft_count_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from A to B.
int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = ft_count_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > ft_count_rarb(a, b, tmp->nbr))
			i = ft_count_rarb(a, b, tmp->nbr);
		if (i > ft_count_rrarrb(a, b, tmp->nbr))
			i = ft_count_rrarrb(a, b, tmp->nbr);
		if (i > ft_count_rarrb(a, b, tmp->nbr))
			i = ft_count_rarrb(a, b, tmp->nbr);
		if (i > ft_count_rrarb(a, b, tmp->nbr))
			i = ft_count_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
