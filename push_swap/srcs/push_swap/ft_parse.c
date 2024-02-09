/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:11:32 by athekkan          #+#    #+#             */
/*   Updated: 2024/02/09 19:47:52 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function free the string which is 
// the integer values in between quotes.
void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

// Function to parse the arguments from the quoted string
// and send them to list_args function to add them into list.
// With ft_split we split numbers from spaces.
t_stack	*ft_parse_args_quoted(char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	list_args(tmp, &stack_a);
	ft_freestr(tmp);
	free(tmp);
	return (stack_a);
}

// ft_parse: Parse Command-Line Arguments and Create Stack
// This function handles the parsing of command-line arguments
// and creates a stack based on the input.
// Parameters:
//   - argc: Number of command-line arguments
//   - argv: Array of pointers to strings representing command-line arguments
// Returns:
//   - Pointer to the top of the created stack
t_stack	*ft_parse(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;
	int			j;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
	{
		ft_error();
	}
	else if (argc == 2)
	{
		stack_a = ft_parse_args_quoted(argv);
	}
	else
	{
		list_args(argv, &stack_a);
	}
	return (stack_a);
}
