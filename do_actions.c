/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:40:59 by slampine          #+#    #+#             */
/*   Updated: 2023/03/13 12:23:33 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_action(t_stack **stack_a, t_stack **stack_b, int target)
{
	t_stack *temp;
	int		cost_b;
	int		cost_a;

	temp = *stack_b;
	while (temp->value != target)
		temp = temp->next;
	cost_b = temp->cost_top;
	cost_a = temp->cost_pos;
	//ft_printf("value is %i, cost is %i, cost_top is %i, cost_pos is %i\n",temp->value, temp->cost,temp->cost_top, temp->cost_pos);
	while (cost_b > 0 && cost_a > 0)
	{
		do_rot_both(stack_b, stack_a, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		do_rot_both(stack_b, stack_a, -1);
		cost_b++;
		cost_a++;
	}
	do_rotate(stack_a, cost_a, 'a');
	do_rotate(stack_b, cost_b, 'b');
	do_pa(stack_a, stack_b);
}

void	do_rotate(t_stack **stack, int num, char spec)
{
	while (num > 0)
	{
		rotate(stack);
		num--;
		ft_printf("r%c\n", spec);
	}
	while (num < 0)
	{
		reverse_rotate(stack);
		num++;
		ft_printf("rr%c\n", spec);
	}
}


void	do_rot_both(t_stack **stack_a, t_stack **stack_b, int num)
{
	while (num > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
		num--;
	}
	while (num < 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
		num++;
	}
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b[0])
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a[0])
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	do_swap(t_stack **stack, char spec)
{
	swap(*stack);
	ft_printf("s%c\n", spec);
}
