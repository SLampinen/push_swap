/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:15:43 by slampine          #+#    #+#             */
/*   Updated: 2023/02/06 09:15:45 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				current;
	int				cost_top;
	int				cost_pos;
	int				cost;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);
t_stack	*init(t_stack *stack, int argc, char **src);
t_stack	*stack_new(int data);
int		check_duplicates(t_stack *src);
int		is_number(char *src);
t_stack	*stack_last(t_stack *stack);
t_stack	*second_last(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	assign_index(t_stack *stack_a, int stack_size);
void	swap(t_stack *stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	do_action(t_stack **stack_a, t_stack **stack_b, int target);
void	do_rotate(t_stack **stack, int num, char spec);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_swap(t_stack **stack, char spec);
void	do_rot_both(t_stack **stack_a, t_stack **stack_b, int num);
int		is_sorted(t_stack *stack);
int		is_rev_sorted(t_stack *stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size_a);
void	sort_three(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b, int size_a);
int		find_index_pos(t_stack *stack, int target);
int		find_highest(t_stack *stack);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	assign_cost(t_stack *stack_a, t_stack *stack_b);
void	assign_pos(t_stack *stack);
int		abs_num(int num);
#endif
