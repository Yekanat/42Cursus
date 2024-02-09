/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:10:00 by athekkan          #+#    #+#             */
/*   Updated: 2024/01/17 17:30:39 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string.
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.

/*
** Custom implementation of atoi function:
** Converts a string representing an integer to an int.
** Handles leading spaces, signs, and checks for overflow.
*/
int	ft_atoi2(const char *str)
{
	int mod;             // Sign of the number (-1 for negative, 1 for positive)
	long long int i;     // Accumulator for the numeric value

	i = 0;
	mod = 1;

	// Ignore leading white spaces
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;

	// Handle sign
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	// Convert the string to an integer
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}

	// Check for overflow
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();

	// Return the result
	return (mod * i);
}


// This function works and sorts the stacks
// in case of they are passed in between quotation
// marks. In this scenario, this function takes the
// string, and splits the numbers in order to create
// seperated integer number.

/*
** Custom function to process a string of space-separated integers:
** 1. Initializes an empty stack 'a'.
** 2. Splits the input string into an array of strings using space as the delimiter.
** 3. Converts each string to an integer using ft_atoi2 and adds it to the end of the stack.
** 4. Frees the memory allocated for the array of strings.
** 5. Frees the memory allocated for the array of string pointers.
** 6. Returns the linked list 'a', which now contains integers from the input string.
*/
t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;        // Linked list (stack) to store integers
	char	**tmp;      // Array of strings obtained by splitting the input
	int		i;          // Index for traversing the array of strings
	int		j;          // Converted integer value from a string

	a = NULL;           // Initialize an empty stack
	i = 0;

	// Split the input string into an array of strings using space as the delimiter
	tmp = ft_split(argv[1], 32);

	// Iterate through the array of strings
	while (tmp[i])
	{
		// Convert the current string to an integer using ft_atoi2
		j = ft_atoi2(tmp[i]);

		// Add the integer to the end of the linked list (stack)
		ft_add_back(&a, ft_stack_new(j));

		i++;
	}

	// Free the memory allocated for the array of strings
	ft_freestr(tmp);

	// Free the memory allocated for the array of string pointers
	free(tmp);

	// Return the linked list (stack) containing integers from the input string
	return (a);
}


// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string. Call
//	  another function. <ft_sub_process>
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguments.

/*
** Custom function to process command-line arguments and create a linked list of integers:
** 1. Initializes an empty stack 'a'.
** 2. Checks the number of command-line arguments, raising an error if there are too few.
** 3. If there are two arguments, calls ft_sub_process to handle processing a string of space-separated integers.
** 4. If there are more than two arguments, iterates through the arguments, converts each to an integer, and adds it to the stack.
** 5. Returns the linked list 'a', which contains integers based on the provided command-line arguments.
*/
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;        // Linked list (stack) to store integers
	int		i;          // Index for traversing command-line arguments
	int		j;          // Converted integer value from a string

	i = 1;
	a = NULL;           // Initialize an empty stack

	// Check if there are too few command-line arguments
	if (argc < 2)
		ft_error();

	// Check the number of arguments and handle accordingly
	if (argc == 2)
		a = ft_sub_process(argv);   // Call ft_sub_process for a single argument
	else
	{
		// Iterate through the command-line arguments (starting from the second argument)
		while (i < argc)
		{
			// Convert the current argument to an integer using ft_atoi2
			j = ft_atoi2(argv[i]);

			// Add the integer to the end of the linked list (stack)
			ft_add_back(&a, ft_stack_new(j));

			i++;
		}
	}

	// Return the linked list (stack) containing integers based on command-line arguments
	return (a);
}
