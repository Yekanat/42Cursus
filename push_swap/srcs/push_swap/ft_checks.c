/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:10:14 by athekkan          #+#    #+#             */
/*   Updated: 2024/02/09 19:27:52 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//function which checks the character if it is alphanumerical
int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}

//Here arguments are send to make ASCII check
//regarding the alphanumeric values
void	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

//With this function it is checked 
//whether arguments include alfanumeric or not
int	check_args(char **argv)
{
	alpha_check(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}

// This function checks if the stack includes
// any duplicate numbers.
int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

// This function checks if the stack is sorted.
int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
