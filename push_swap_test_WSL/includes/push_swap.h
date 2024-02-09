/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:08:50 by athekkan          #+#    #+#             */
/*   Updated: 2024/02/06 18:18:15 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void		list_args(char **argv, t_stack **stack_a);
void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
void		ft_error(void);
void		ft_free(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_rotate_a(t_stack **a, int j);
void		ft_rotate_b(t_stack **b, int j);
void		ft_swap_a(t_stack **a, int j);
void		ft_push_a(t_stack **a, t_stack **b, int j);
void		ft_push_b(t_stack **stack_a, t_stack **stack_b, int j);
void		ft_reverse_rotate_a(t_stack **a, int j);
void		ft_swap_ab(t_stack **a, t_stack **b, int j);
void		ft_rotate_ab(t_stack **a, t_stack **b, int j);
void		ft_reverse_rotate_ab2(t_stack **b, int j);
void		ft_reverse_rotate_ab1(t_stack **a, t_stack **b, int j);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_find_index(t_stack *a, int nbr);
int			ft_find_place_b(t_stack *stack_b, int nbr_push);
int			ft_find_place_a(t_stack *a, int nbr);
void		ft_sort(t_stack **stack_a);
int			ft_checksorted(t_stack *stack_a);
void		ft_sort_big(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a);
t_stack		*ft_parse(int argc, char **argv);
t_stack		*ft_parse_args_quoted(char **argv);
void		ft_freestr(char **lst);
int			ft_count_rarb_a(t_stack *a, t_stack *b, int c);
int			ft_count_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ft_count_rarrb_a(t_stack *a, t_stack *b, int c);
int			ft_count_rrarb_a(t_stack *a, t_stack *b, int c);
int			ft_count_rarb(t_stack *a, t_stack *b, int c);
int			ft_count_rrarrb(t_stack *a, t_stack *b, int c);
int			ft_count_rrarb(t_stack *a, t_stack *b, int c);
int			ft_count_rarrb(t_stack *a, t_stack *b, int c);
int			ft_rotate_type_ab(t_stack *a, t_stack *b);
int			ft_rotate_type_ba(t_stack *a, t_stack *b);
int			ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void		ft_reverse_rotate_b(t_stack **b, int j);
void		ft_check_sub(t_stack **a, t_stack **b, char *line);
char		*ft_check(t_stack **a, t_stack **b, char *line);
void		ft_checker_sub(t_stack **a, t_stack **b, char *line);
t_stack		*ft_process(int argc, char **argv);
void		ft_swap_b(t_stack **b, int j);
void		algorithm(int argc, char **argv);
void		ft_sort_b_to_3(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sub_process(char **argv);
void		ft_error_ch(void);

#endif