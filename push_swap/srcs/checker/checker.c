/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:07:31 by athekkan          #+#    #+#             */
/*   Updated: 2024/01/25 12:43:52 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function is the second part of the ft_check function.
void	ft_check_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_reverse_rotate_a(a, 1);
	else if (line[2] == 'b')
		ft_reverse_rotate_b(b, 1);
	else if (line[2] == 'r')
		ft_reverse_rotate_ab1(a, b, 1);
}

// This function reads the line and checks if the command is valid.
// If it is, it executes the command.
char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_swap_a(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_swap_b(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_push_a(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_push_b(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_rotate_a(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rotate_b(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rotate_ab(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_swap_ab(a, b, 1);
	else
		ft_error_ch();
	return (get_next_line(0));
}

// This function checks the validity of the commands and stack.
// If it is valid, and the stack_a is sorted, the program prints "OK". 
void	ft_checker_sub(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!ft_checksorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free (&a);
		ft_error_ch();
	}
	line = get_next_line(0);
	if (!line && !ft_checksorted(a))
		write(1, "KO\n", 3);
	else if (!line && ft_checksorted(a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
