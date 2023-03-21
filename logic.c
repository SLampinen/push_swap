/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:50:17 by slampine          #+#    #+#             */
/*   Updated: 2023/03/03 11:50:18 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(t_stack *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

int	find_lowest(t_stack *stack)
{
	int	lowest;

	lowest = stack->index;
	while (stack)
	{
		if (stack->index < lowest)
			lowest = stack->index;
		stack = stack->next;
	}
	return (lowest);
}

int	find_index_pos(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack->index != target)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort_three(t_stack **stack)
{
	int	highest;
	int	pos;

	highest = find_highest(*stack);
	pos = find_index_pos(*stack, highest);
	if (pos == 0)
		do_rotate(stack, 1, 'a');
	if (pos == 1)
		do_rotate(stack, -1, 'a');
	if (!is_sorted(*stack))
		do_swap(stack, 'a');
}

int	abs_num(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

void	assign_pos(t_stack *stack)
{
	t_stack	*temp;
	int		val;

	val = 0;
	temp = stack;
	while (temp)
	{
		temp->current = val;
		temp = temp->next;
		val++;
	}
}
int	find_cheapest(t_stack *stack)
{
	t_stack *temp;
	int	cheapest;
	int index;

	temp = stack;
	cheapest = INT_MAX;
	while (temp)
	{
		if (temp->cost < cheapest)
		{
			index = temp->value;
			cheapest = temp->cost;
		}
		temp = temp->next;
	}
	return (index);
}
void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	t_stack	*temp;

	temp = *stack_b;
	cheapest = find_cheapest(temp);
	while (temp)
	{
		if (temp->value == cheapest)
			do_action(stack_a, stack_b, cheapest);
		temp = temp->next;
	}
}
void	push_bulk(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int	size;

	size = stack_size(*stack_a);
	temp = *stack_a;
	while (size > 3)
	{
		do_pb(stack_a, stack_b);
		size--;
	}
}
void	sort(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	t_stack *temp;
	
	if (size_a > 3)
		push_bulk(stack_a, stack_b);
	sort_three(stack_a);
	temp = *stack_b;
	while (temp)
	{
		print_stack(*stack_a, *stack_b);
		assign_cost(*stack_a, *stack_b);
		do_cheapest(stack_a, stack_b);
		temp = (*stack_b)->next;
	}
	assign_cost(*stack_a, *stack_b);
	do_cheapest(stack_a, stack_b);
	do_rotate(stack_a, -1 * ((*stack_a)->index - 1), 'a');
}
