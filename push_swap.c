/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:22:18 by slampine          #+#    #+#             */
/*   Updated: 2023/03/13 12:24:03 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*is_long(t_stack *stack)
{
	if (stack->value > 99999 || stack->value < -9999)
		return ("\t");
	return ("\t\t");
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	char	*tabs;

	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			tabs = is_long(stack_a);
			ft_printf("a:%i%sb:%i \n", stack_a->value, tabs, stack_b->value);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		if (stack_a && !stack_b)
		{
			ft_printf("a:%i\n", stack_a->value);
			stack_a = stack_a->next;
		}
		if (!stack_a && stack_b)
		{
			ft_printf("		b:%i\n", stack_b->value);
			stack_b = stack_b->next;
		}
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	if (is_sorted(*stack_a))
		return ;
	if (size_a <= 3)
		sort_three(stack_a);
	if (size_a > 3)
		sort(stack_a, stack_b, size_a);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init(stack_a, argc, argv);
	if (!stack_a)
		return (0);
	if (check_duplicates(stack_a) == 1)
	{
		ft_printf("Error, duplicate numbers\n");
		return (0);
	}
	size_a = stack_size(stack_a);
	push_swap(&stack_a, &stack_b, size_a);
	//ft_printf("Sorted stack:\n");
	//print_stack(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
