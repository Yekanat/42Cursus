/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:11:32 by athekkan          #+#    #+#             */
/*   Updated: 2024/01/25 15:53:08 by athekkan         ###   ########.fr       */
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
// This function handles the parsing of command-line arguments and creates a stack based on the input.
// Parameters:
//   - argc: Number of command-line arguments
//   - argv: Array of pointers to strings representing command-line arguments
// Returns:
//   - Pointer to the top of the created stack
t_stack *ft_parse(int argc, char **argv)
{
    t_stack *stack_a; // Pointer to the top of the stack
    int		i; // Loop variable
    int		j; // Loop variable

    i = 1; // Start at index 1 to skip the program name
    stack_a = NULL; // Initialize the stack pointer to NULL

    // Case 1: Less Than 2 Arguments
    if (argc < 2) {
        ft_error(); // Raise error if no arguments provided
    }
    // Case 2: Exactly 2 Arguments (Quoted String)
    else if (argc == 2) {
        stack_a = ft_parse_args_quoted(argv); // Parse the quoted string
    }
    // Case 3: More Than 2 Arguments (List Arguments)
    else {
        list_args(argv, &stack_a); // Parse and list individual arguments
    }

    return stack_a; // Return the created stack
}
