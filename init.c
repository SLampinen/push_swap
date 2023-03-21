/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:31:30 by slampine          #+#    #+#             */
/*   Updated: 2023/03/13 12:23:40 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*stack;
	t_stack	*highest;
	int		value;

	while (stack_size-- > 0)
	{
		stack = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (stack)
		{
			if (stack->value > value && stack->index == 0)
			{
				value = stack->value;
				highest = stack;
				stack = stack_a;
			}
			else
				stack = stack->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int	find_adjacent(t_stack *stack, int target, int size, int val)
{
	t_stack	*temp;
	int		min;
	int		max;
	int		res;

	temp = stack;
	min = INT_MIN;
	max = INT_MAX;
	res = val;
	while (temp)
	{
		if (temp->value > target && temp->value < max)
			max = temp->value;
		if (temp->value < target && temp->value > min)
			min = temp->value;
		temp = temp->next;
	}
	temp = stack;
	while (temp)
	{
		if (temp->value == max)
		{
			return (res);
		}
		if (temp->value == min)
		{
			return (res + 1);
		}
		val++;
		res = val;
		if (val >= size / 2)
			res = val - size;
		temp = temp->next;
	}
	return (res);
}

int	find_place(t_stack *stack, int target)
{
	int	place;
	int	size;

	size = stack_size(stack);
	place = find_adjacent(stack, target, size, 0);
	return (place);
}

void	assign_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	int		pos;
	int		size;

	pos = 0;
	size = stack_size(stack_b);
	assign_pos(stack_b);
	while (stack_b)
	{
		temp = stack_b;
		temp->cost_pos = find_place(stack_a, stack_b->value);
		if (pos > size / 2)
			temp->cost_top = (size - pos) * -1;
		else
			temp->cost_top = pos;
		if ((temp->cost_top >= 0 && temp->cost_pos >= 0) || (temp->cost_pos <= 0 && temp->cost_top <= 0))
		{
			if (abs_num(temp->cost_pos) >= abs_num(temp->cost_top))
				temp->cost = abs_num(temp->cost_pos);
			else if (abs_num(temp->cost_top) >= abs_num(temp->cost_pos))
				temp->cost = abs_num(temp->cost_top);
			else
				temp->cost = abs_num(temp->cost_pos) + abs_num(temp->cost_top);
		}
		else
			temp->cost = abs_num(temp->cost_pos) + abs_num(temp->cost_top);
		
		pos++;
		stack_b = stack_b->next;
	}
}

t_stack	*init(t_stack *stack, int amnt, char **src)
{
	int		ind;
	int		num;
	char	**array;

	ind = 1;
	while (ind < amnt)
	{
		array = ft_split(src[ind], ' ');
		num = 0;
		while (array[num] != '\0')
		{
			if (is_number(array[num]) == 0)
			{
				ft_printf("Error: %s is not an integer\n", array[num]);
				free(array);
				return (0);
			}
			stack_add_bottom(&stack, stack_new(ft_atoi(array[num])));
			num++;
		}
		ind++;
	}
	assign_index(stack, stack_size(stack) + 1);
	free(array);
	return (stack);
}
